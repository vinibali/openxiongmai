#include "mpi_ae.h"
#include "mpi_awb.h"
#include "mpi_isp.h"
#include "xm_awb_comm.h"
#include "xm_comm_isp.h"
#include "xm_comm_sns.h"
#include "xm_sns_ctrl.h"
#include "xm_type.h"

#include "XAx_cmos.h"
#include "xm_print.h"

#define STATIC static

extern const ISP_CMOS_GAMMA_S gstIspGamma;
extern XM_VOID XM_MPI_ISP_Memset(XM_U8 *pu8Addr, XM_U8 u8Ch, XM_U32 u32Num);
#define HD3MP_25P_LINES (1350)

extern XM_U32 gau32AllGain;
extern XM_U32 gu32DGainNow;
extern XM_U32 gu32AGainNow;

static const ISP_CMOS_AGC_TABLE_S g_stIspAgcTable = {
    /* bvalid */
    1,
    /* 100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200, 102400,
       204800, 409600, 819200, 1638400, 3276800 */
    /* sharpen_D	H	*/
    {0x34, 0x34, 0x2C, 0x2C, 0x2A, 0x22, 0x1C, 0x10, 0x04, 0x04, 0x04, 0x04,
     0x04, 0x04, 0x04, 0x04},
    /* sharpen_Ud M	*/
    {0x34, 0x34, 0x30, 0x2C, 0x2A, 0x24, 0x18, 0x10, 0x04, 0x04, 0x04, 0x04,
     0x04, 0x04, 0x04, 0x04},
    /* sharpen_Kd  */
    {0x3C, 0x3C, 0x2E, 0x2C, 0x28, 0x24, 0x1C, 0x10, 0x08, 0x08, 0x08, 0x08,
     0x08, 0x08, 0x08, 0x08},
    /* snr_thresh 2DNr		*/
    {0x01, 0x02, 0x03, 0x06, 0x09, 0x0b, 0x0F, 0x1C, 0x30, 0x40, 0x40, 0x40,
     0x40, 0x40, 0x40, 0x40},
    /* snr_thresh 3DNr	 Tf	*/
    {0x04, 0x05, 0x08, 0x0A, 0x11, 0x18, 0x1A, 0x20, 0x20, 0x19, 0x18, 0x18,
     0x18, 0x18, 0x18, 0x18},
    /* snr_thresh 3DNr	 Sf	*/
    {0x00, 0x00, 0x01, 0x04, 0x0C, 0x10, 0x14, 0x18, 0x18, 0x18, 0x18, 0x18,
     0x18, 0x18, 0x10, 0x10},
    /* DyDpc_thresh 		*/
    {0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD0, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8,
     0xD8, 0xD8, 0xD8, 0xD8},
    /* saturation_strength */
    {0xAF, 0xAF, 0xAF, 0xAA, 0xA8, 0x96, 0x6E, 0x64, 0x10, 0x10, 0x10, 0x10,
     0x10, 0x10, 0x10, 0x10},
    /* Blc	*/
    {0x104, 0x104, 0x104, 0x104, 0x0F0, 0x0F0, 0x0E6, 0x0DC, 0x0DC, 0x0DC,
     0x104, 0x104, 0x104, 0x104, 0x104, 0x104},
    /*Y_Tran gamma*/
    {0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
     0x32, 0x32, 0x32, 0x32}};

static XM_S32 cmos_get_isp_default(ISP_CMOS_DEFAULT_S *pstDef) {
  if (XM_NULL == pstDef) {
    ERR("null pointer when get isp default value!\n");
    return -1;
  }
  pstDef->stGamma.bValid = XM_TRUE;
  XM_MPI_ISP_Memncpy((XM_U8 *)&pstDef->stGamma, (XM_U8 *)&gstIspGamma,
                     sizeof(ISP_CMOS_GAMMA_S));
  XM_MPI_ISP_Memncpy((XM_U8 *)&pstDef->stAgcTbl, (XM_U8 *)&g_stIspAgcTable,
                     sizeof(ISP_CMOS_AGC_TABLE_S));
  return 0;
}

static XM_VOID cmos_set_pixel_detect(XM_BOOL bEnable) { return; }

static XM_S32 cmos_set_mirror_flip(XM_U8 u8Mirror, XM_U8 u8Flip) {
  XM_U32 u32Val;
  XM_U16 u16OfstV;

  u32Val = sensor_read_register(0x3221);

  if (u8Mirror) {
    u32Val |= 0x06;
  } else {
    u32Val &= ~0x06;
  }

  if (u8Flip) {
    u32Val |= 0x60;
    u16OfstV = 0;
  } else {
    u32Val &= ~0x60;
    u16OfstV = 0;
  }
  sensor_write_register(0x3221, u32Val);
  VI_WinSet(1, u8Mirror, u8Flip, 0, u16OfstV);
  XM_MPI_MIPI_RefreshFV(100, 0);
  return XM_SUCCESS;
}

static XM_VOID cmos_again_calc_table(XM_U32 u32InTimes,
                                     AE_SENSOR_GAININFO_S *pstAeSnsGainInfo) {
  int i;
  if (XM_NULL == pstAeSnsGainInfo) {
    ERR("null pointer when get ae sensor gain info	value!\n");
    return;
  }

  pstAeSnsGainInfo->u32GainDb = 0;
  pstAeSnsGainInfo->u32SnsTimes = 1024;

  u32InTimes = u32InTimes / 32;
  u32InTimes = u32InTimes < 32 ? 32 : u32InTimes;

  for (i = 0; i < 4; i++) {
    if (u32InTimes < 64) {
      break;
    }
    u32InTimes >>= 1;
    pstAeSnsGainInfo->u32GainDb = (pstAeSnsGainInfo->u32GainDb << 1) | 1;
  }
  pstAeSnsGainInfo->u32GainDb = (pstAeSnsGainInfo->u32GainDb << 8) + u32InTimes;
  u32InTimes = u32InTimes << i;
  pstAeSnsGainInfo->u32SnsTimes = u32InTimes * 32;
  gu32AGainNow = pstAeSnsGainInfo->u32SnsTimes;
  return;
}

static XM_VOID cmos_dgain_calc_table(XM_U32 u32InTimes,
                                     AE_SENSOR_GAININFO_S *pstAeSnsGainInfo) {
  int i;
  if (XM_NULL == pstAeSnsGainInfo) {
    ERR("cmos_dgain_calc_table failed!\n");
    return;
  }
  pstAeSnsGainInfo->u32GainDb = 0;
  for (i = 0; i < 5; i++) {
    if (u32InTimes < 256) {
      break;
    }
    u32InTimes >>= 1;
    pstAeSnsGainInfo->u32GainDb = (pstAeSnsGainInfo->u32GainDb << 1) | 1;
  }
  pstAeSnsGainInfo->u32SnsTimes = u32InTimes << i;
  pstAeSnsGainInfo->u32GainDb = (pstAeSnsGainInfo->u32GainDb << 8) + u32InTimes;
  gu32DGainNow = pstAeSnsGainInfo->u32SnsTimes;
  return;
}

static XM_S32 cmos_get_ae_default(AE_SENSOR_DEFAULT_S *pstAeSnsDft) {
  if (XM_NULL == pstAeSnsDft) {
    ERR("null pointer when get ae default value!\n");
    return -1;
  }
  pstAeSnsDft->u32FullLinesStd = HD3MP_25P_LINES;
  pstAeSnsDft->u8AeCompensation = 0x39;
  pstAeSnsDft->u32LinesPer500ms = pstAeSnsDft->u32FullLinesStd * 25 / 2;
  pstAeSnsDft->u32FlickerFreq = 0;

  pstAeSnsDft->u32MaxIntTime = pstAeSnsDft->u32FullLinesStd - 5;
  pstAeSnsDft->u32MinIntTime = 2;

  pstAeSnsDft->u32MaxAgain = 16128;
  pstAeSnsDft->u32MinAgain = 1024;

  pstAeSnsDft->u32MaxDgain = 4032;
  pstAeSnsDft->u32MinDgain = 128;

  pstAeSnsDft->u32ISPDgainShift = 8;
  pstAeSnsDft->u32MaxISPDgain = 8 << pstAeSnsDft->u32ISPDgainShift;
  pstAeSnsDft->u32MinISPDgain = 1 << pstAeSnsDft->u32ISPDgainShift;

  pstAeSnsDft->bDelayCfg = XM_TRUE;

  gu32AGainNow = pstAeSnsDft->u32MinAgain;
  gu32DGainNow = pstAeSnsDft->u32MinDgain;
  return 0;
}

static XM_S32 cmos_get_sensor_max_resolution(
    ISP_CMOS_SENSOR_MAX_RESOLUTION *pstSensorMaxResolution) {
  if (XM_NULL == pstSensorMaxResolution) {
    ERR("null pointer when get sensor max resolution \n");
    return -1;
  }
  pstSensorMaxResolution->u32MaxWidth = 2304;
  pstSensorMaxResolution->u32MaxHeight = 1296;
  return 0;
}

STATIC XM_VOID cmos_inttime_update(XM_U32 u32IntTime) {
  if (gu32ShutNow == u32IntTime)
    return;
  gu32ShutNow = u32IntTime;
  u32IntTime = u32IntTime * 2;
  sensor_write_register(0x3e00, ((u32IntTime & 0xFF000) >> 12));
  sensor_write_register(0x3e01, ((u32IntTime & 0x0ff0) >> 4));
  sensor_write_register(0x3e02, ((u32IntTime & 0xf) << 4));
  return;
}

const static XM_U8 gau8Logic_sc3335[3][3] = {
    //  0x3632,0x3306,0x330b
    {0x18, 0x50, 0xd0},
    {0x58, 0x58, 0xd8},
    {0xd8, 0x5c, 0xdb}};
const static XM_U16 gau16LogicAddr_Mipi[3] = {0x3632, 0x3306, 0x330b};

static void gainLogic_sc3335(XM_U32 u32AllGain) {
  static XM_U8 su8Idx = 0xFF; //[bit0~bit3]:Vstd   [bit4~bit7]:Agc
  XM_U8 u8Idx2, u8i;
  u32AllGain = u32AllGain / 64; // *1024->*16
  if (u32AllGain < 32)
    u8Idx2 = 0;
  else if (u32AllGain < 128)
    u8Idx2 = 1;
  else
    u8Idx2 = 2;
  if (((su8Idx >> 4) & 0x0F) != u8Idx2) {
    su8Idx = ((u8Idx2 & 0x0F) << 4);
    sensor_write_register(0x3812, 0x00);
    for (u8i = 0; u8i < 3; u8i++) {
      sensor_write_register((XM_U32)gau16LogicAddr_Mipi[u8i],
                            (XM_U32)gau8Logic_sc3335[u8Idx2][u8i]);
    }
    sensor_write_register(0x3812, 0x30);
  }
}
static XM_VOID cmos_gains_update(XM_U32 u32Again, XM_U32 u32Dgain) {
  static XM_U32 su32AGain = 0xFFFFFFF;
  static XM_U32 su32DGain = 0xFFFFFFF;
  unsigned int u32Tmp, tmp[4];
  gau32AllGain = (XM_U64)gu32AGainNow * gu32DGainNow / 128;
  gainLogic_sc3335(gau32AllGain);
  if ((su32AGain != u32Again) || (su32DGain != u32Dgain)) {
    su32AGain = u32Again;
    su32DGain = u32Dgain;
    // 2.GainUpdate
    tmp[0] = u32Again & 0xFF;
    u32Tmp = (u32Again >> 8) & 0xFF;
    tmp[1] = 0x03 | (u32Tmp << 2);

    tmp[2] = u32Dgain & 0xFF;
    tmp[3] = (u32Dgain >> 8) & 0xFF;
    sensor_write_register(0x3e08, tmp[1]);
    sensor_write_register(0x3e09, tmp[0]);
    sensor_write_register(0x3e06, tmp[3]);
    sensor_write_register(0x3e07, tmp[2]);
  }
  return;
}

/* the function of sensor set fps */
static XM_VOID cmos_fps_set(XM_U8 u8Fps, AE_SENSOR_DEFAULT_S *pstAeSnsDft) {
  static XM_U8 su8Mode = 0xFF;
  XM_U32 u32Pixs = 2880;
  XM_U32 u32TotalSizeV;
  XM_U32 u32ExpNow;
  XM_U8 u8Mode;
  u32ExpNow = sensor_read_register(0x3e00);
  u32ExpNow = (u32ExpNow << 8) | sensor_read_register(0x3e01);
  u32Pixs = sensor_read_register(0x3e02);
  u32ExpNow = (u32ExpNow << 4) | ((u32Pixs >> 4) & 0x0F);
  switch (u8Fps) {
  case 30:
    u32Pixs = 2400;
    break;
  case 25:
    u32Pixs = 2880;
    break;
  case 20:
    u32Pixs = 3600;
    break;
  case 15:
    u32Pixs = 4800;
    break;

  default:
    return;
    break;
  }
  u8Mode = u8Fps;
  if (su8Mode == u8Mode) {
    return;
  }
  su8Mode = u8Mode;

  u32TotalSizeV = HD3MP_25P_LINES;

  if (pstAeSnsDft != NULL) {
    pstAeSnsDft->u32FullLinesStd = u32TotalSizeV;
    pstAeSnsDft->u32MaxIntTime = pstAeSnsDft->u32FullLinesStd - 4;
    pstAeSnsDft->u32LinesPer500ms = pstAeSnsDft->u32FullLinesStd * u8Fps / 2;
  }
  if (u32ExpNow > (u32TotalSizeV - 4)) {
    u32ExpNow = u32TotalSizeV - 4;
    cmos_inttime_update(u32ExpNow);
  }

  u32Pixs = u32Pixs >> 1;
  sensor_write_register(0x320c, (u32Pixs >> 8) & 0xFF);
  sensor_write_register(0x320d, u32Pixs & 0xFF);
  sensor_write_register(0x320e, (u32TotalSizeV >> 8) & 0xFF);
  sensor_write_register(0x320f, u32TotalSizeV & 0xFF);
  gu8Fps = u8Fps;

  SysDelay_ms(20);
  return;
}

static XM_VOID cmos_slow_framerate_set(XM_U16 u16FullLines,
                                       AE_SENSOR_DEFAULT_S *pstAeSnsDft) {
  return;
}

/****************************************************************************
 * AWB
 ****************************************************************************/
const static ISP_COLORMATRIX_AUTO_S g_stAwbCcm = {
    5000, {0x000, 180, 30, 46, 0x000, -22, 230, 48, 0x000, -2, -78, 336},
    4000, {0x000, 215, -61, 102, 0x000, -7, 142, 121, 0x000, 4, -136, 388},
    2800, {0x000, 189, -85, 152, 0x000, -40, 105, 192, 0x000, -58, -284, 598}};

const static ISP_AWB_CALIBRATION_V2_S gstAwbCal = {
    {0, 0, 4096, 2499, 3127, 2234, 3619, 4096},
    {4096, 3779, 0, 0, 4096, 2469, 4096, 1874},
    {-782, -4096, -1385, -4096, -3530, -4096, -3819, -2926},
    213,
    0,
    1533,
    0,
    2786,
    {0, 738, 1082, 1317, 1388, 1445, 1704, 1757, 2786, 0, 0, 0, 0, 0, 0, 0},
    {2000, 2150, 2800, 4000, 4150, 5000, 6500, 7500, 12000, 0, 0, 0, 0, 0, 0,
     0},
    {1396, 1024, 1582, 0}};

static XM_S32 cmos_get_awb_default(AWB_SENSOR_DEFAULT_S *pstAwbSnsDft) {
  if (XM_NULL == pstAwbSnsDft) {
    ERR("null pointer when get awb default value!\n");
    return XM_FAILURE;
  }
  pstAwbSnsDft->pstRbTable = (const AWB_COEF_TABLE_S *)(&gstAwbCal);
  // CCM
  XM_MPI_ISP_Memncpy((XM_U8 *)&(pstAwbSnsDft->stCcm), (XM_U8 *)&g_stAwbCcm,
                     sizeof(ISP_COLORMATRIX_AUTO_S));
  return XM_SUCCESS;
}

XM_S32
cmos_init_sensor_exp_function_sc3335(ISP_SENSOR_EXP_FUNC_S *pstSensorExpFunc) {
  pstSensorExpFunc->pfn_cmos_sensor_init = NULL;
  pstSensorExpFunc->pfn_cmos_get_isp_default = cmos_get_isp_default;
  pstSensorExpFunc->pfn_cmos_set_pixel_detect = cmos_set_pixel_detect;
  pstSensorExpFunc->pfn_cmos_get_sensor_max_resolution =
      cmos_get_sensor_max_resolution;
  pstSensorExpFunc->pfn_cmos_set_mirror_flip = cmos_set_mirror_flip;
  return 0;
}

XM_S32 cmos_init_ae_exp_function_sc3335(AE_SENSOR_EXP_FUNC_S *pstExpFuncs) {
  //	  XM_MPI_ISP_Memset((char *)pstExpFuncs, 0,
  // sizeof(AE_SENSOR_EXP_FUNC_S));
  pstExpFuncs->pfn_cmos_fps_get = NULL;
  pstExpFuncs->pfn_cmos_get_ae_default = cmos_get_ae_default;
  pstExpFuncs->pfn_cmos_fps_set = cmos_fps_set;
  pstExpFuncs->pfn_cmos_slow_framerate_set = cmos_slow_framerate_set;
  pstExpFuncs->pfn_cmos_inttime_update = cmos_inttime_update;
  pstExpFuncs->pfn_cmos_gains_update = cmos_gains_update;
  pstExpFuncs->pfn_cmos_again_calc_table = cmos_again_calc_table;
  pstExpFuncs->pfn_cmos_dgain_calc_table = cmos_dgain_calc_table;
  pstExpFuncs->pfn_cmos_shut_calc_table = NULL;
  return 0;
}

XM_S32 cmos_init_awb_exp_function_sc3335(AWB_SENSOR_EXP_FUNC_S *pstExpFuncs) {
  pstExpFuncs->pfn_cmos_get_awb_default = cmos_get_awb_default;
  return 0;
}