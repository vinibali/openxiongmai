/******************************************************************************
 Copyright (C), 2015-2020, XM. Co., Ltd.
******************************************************************************
File Name	: xm530_isp.h
Version 		: Initial Draft
Author		: XM Isp software group
Created 		: 2017/5/11

Description 	: The common data type defination
Function List	:
History :
1.Date		: 2017/5/11
  Author		: Ganwencao
  Modification	: creat
******************************************************************************/
#ifndef _XM530_REG_
#define _XM530_REG_

#define DDR_BASE_ADDR			(0x80000000)
#define	ISP_BASE_ADDR			0x30000000

//GPIO
#define GPIO_BASE		(0x10020000)

#define GPIO_POC_18_SEL (GPIO_BASE+0x3C0)
#define GPIO_SEN1_MCLK	(GPIO_BASE+0x160)
#define GPIO_SEN1_PCLK	(GPIO_BASE+0x0D4)
#define GPIO_SEN1_HSYNC	(GPIO_BASE+0x0D8)
#define GPIO_SEN1_VSYNC	(GPIO_BASE+0x0DC)
#define GPIO_SEN1_DATE0	(GPIO_BASE+0x0E0)
#define GPIO_SEN1_DATE1	(GPIO_BASE+0x0E4)
#define GPIO_SEN1_DATE2	(GPIO_BASE+0x0E8)
#define GPIO_SEN1_DATE3	(GPIO_BASE+0x0EC)
#define GPIO_SEN1_DATE4	(GPIO_BASE+0x0F0)
#define GPIO_SEN1_DATE5	(GPIO_BASE+0x0F4)
#define GPIO_SEN1_DATE6	(GPIO_BASE+0x0F8)
#define GPIO_SEN1_DATE7	(GPIO_BASE+0x0FC)
#define GPIO_I2C1_SCL	(GPIO_BASE+0x014)
#define GPIO_I2C1_SDA	(GPIO_BASE+0x01C)
#define GPIO_PIN5_4		(GPIO_BASE+0x0D8)	

#define GPIO_I2C0_SDA	(GPIO_BASE+0x104)
#define GPIO_I2C0_SCL	(GPIO_BASE+0x10C)

#define GPIO_SEN0_MCLK	(GPIO_BASE+0x110)
#define GPIO_SEN0_VSYNC	(GPIO_BASE+0x114)
#define GPIO_SEN0_PCLK	(GPIO_BASE+0x118)
#define GPIO_SEN0_HSYNC	(GPIO_BASE+0x11C)
#define GPIO_SEN0_DATE0	(GPIO_BASE+0x120)
#define GPIO_SEN0_DATE1	(GPIO_BASE+0x124)
#define GPIO_SEN0_DATE2	(GPIO_BASE+0x128)
#define GPIO_SEN0_DATE3	(GPIO_BASE+0x12C)
#define GPIO_SEN0_DATE4	(GPIO_BASE+0x130)
#define GPIO_SEN0_DATE5	(GPIO_BASE+0x134)
#define GPIO_SEN0_DATE6	(GPIO_BASE+0x138)
#define GPIO_SEN0_DATE7	(GPIO_BASE+0x13C)
#define GPIO_SEN0_DATE8	(GPIO_BASE+0x140)
#define GPIO_SEN0_DATE9	(GPIO_BASE+0x144)
#define GPIO_SEN0_DATE10	(GPIO_BASE+0x148)
#define GPIO_SEN0_DATE11	(GPIO_BASE+0x14C)

/*************************************************************************************/
#define VIDEOMAIN_BASE			(0x300F0000)
#define VIDEOMAIN_AWBMODE		(0x300F0004)
#define VIDEOMAIN_RGBIR			(0x300F0008)
#define HDR_BYPASS_MODE			(0x300F000C)
#define FRONT_V_VIE_EN			(0x300F0040)
#define LUMA_V_VIE_EN			(0x300F0060)
#define ANALOG_CTRL				(VIDEOMAIN_BASE+0x1C)

//pre_video
#define VIDOEMODE_BASE			0x30000000
#define VIDOEMODE_DECODE_SEL	(VIDOEMODE_BASE+0x000)
#define VIDOEMODE_SLA_MAT_SEL 	(VIDOEMODE_BASE+0x004)
#define VIDOEMODE_DEC_DATA_SEL	(VIDOEMODE_BASE+0x008)
#define VI_VH_NUM				(VIDOEMODE_BASE+0x090)
#define VI_VH_ALL				(VIDOEMODE_BASE+0x094)
#define VI_CUT_BEGIN_H			(VIDOEMODE_BASE+0x098)
#define VI_CUT_END_H			(VIDOEMODE_BASE+0x09C)
#define VI_CUT_BEGIN_V			(VIDOEMODE_BASE+0x0A0)
#define VI_CUT_END_V			(VIDOEMODE_BASE+0x0A4)
#define VI_SYNC_HVALID_RECV		(VIDOEMODE_BASE+0x0C0)
#define VI_SYNC_HVALID_RECV_EN	(VIDOEMODE_BASE+0x0C4)


// DPC
#define SDPC_BASE				0x30001000
#define SDPC_CLK_SW				(SDPC_BASE+0x000)
#define SDPC_SRAMADDR_CLR		(SDPC_BASE+0x004)
#define SDPC_SRAMADDR_DAT		(SDPC_BASE+0x008)
#define SDPC_TEST_ENABLE		(SDPC_BASE+0x00C)


#define DDPC_BASE				0x30035000
#define DDPC_MAX_THD			(DDPC_BASE+0x000)
#define DDPC_MIN_THD			(DDPC_BASE+0x004)
#define DDPC_DIFF_THD1			(DDPC_BASE+0x008)
#define DDPC_DIFF_THD2			(DDPC_BASE+0x00C)
#define DDPC_DIFF_DFTH1			(DDPC_BASE+0x010)
#define DDPC_DIFF_DFTH2			(DDPC_BASE+0x014)


//FPN
#define FPN_BASE				0x30002000
#define FPN_CLK_SW_REG			(FPN_BASE+0x000)
#define FPN_CPU_ADDR			(FPN_BASE+0x004)
#define FPN_CPU_DATA			(FPN_BASE+0x008)
#define FPN_CPU_RDSEL			(FPN_BASE+0x00C)
#define FPN_STREN				(FPN_BASE+0x010)
#define FPN_SEL					(FPN_BASE+0x014)
#define FPN_DET_MODE			(FPN_BASE+0x018)
#define FPN_DET_READY			(FPN_BASE+0x01C)
#define FPN_BYPASS				(FPN_BASE+0x020)

// BlackLevel
#define BLACKLEVEL_BASE			0x30004000

#define BLACKLEVEL_OFFSET_R		(BLACKLEVEL_BASE+0x000)
#define BLACKLEVEL_OFFSET_G		(BLACKLEVEL_BASE+0x004)
#define BLACKLEVEL_OFFSET_B		(BLACKLEVEL_BASE+0x008)
#define BLACKLEVEL_RGB_MAX		(BLACKLEVEL_BASE+0x00C)
#define BLACKLEVEL_RGB_MIN		(BLACKLEVEL_BASE+0x010)


// DIGTAL_GAIN
#define DIGITAL_GAIN			(0x30005000+0x000)
#define DIGITAL_RGBMAX			(0x30005000+0x004)


//LSC
#define LSC_BASE				0x30006000
#define LSC_CTRL				(LSC_BASE+0x000)


//HDR_DEC
#define DEC_BASE				0x30003000
#define DEC_BYPASS				(DEC_BASE+0x000)	
#define DEC_X1					(DEC_BASE+0x004)
#define DEC_RGB_MAX				(DEC_BASE+0x034)
#define DEC_RGB_MIN				(DEC_BASE+0x038)


//HDR
#define	HDR_BASE				(ISP_BASE_ADDR+0x8000)
#define HDR_R_GAIN				(HDR_BASE+0x0000)
#define HDR_G_GAIN				(HDR_BASE+0x0004)
#define HDR_B_GAIN				(HDR_BASE+0x0008)
#define HDR_RGB_MAX				(HDR_BASE+0x000C)
#define HDR_RGB_MIN				(HDR_BASE+0x0010)

#define HDR_CLIP_WT_MAX			(HDR_BASE+0x1000)
#define HDR_CLIP_WT_MIN			(HDR_BASE+0x1004)
#define HDR_MOTION_THR			(HDR_BASE+0x1008)
#define HDR_V_MAX				(HDR_BASE+0x100C)
#define HDR_LS_TIME_RATIO		(HDR_BASE+0x1010)
#define HDR_LE_WT_MIN			(HDR_BASE+0x1014)
#define HDR_SE_WT_RATIO			(HDR_BASE+0x1018)

#define HDR_DCTTAB_DAT0			(HDR_BASE+0x2040)

#define HDR_DS_WIDE				(HDR_BASE+0x3000)
#define HDR_DS_HEIGHT			(HDR_BASE+0x3004)
#define HDR_WIDE_DIVTAB			(HDR_BASE+0x3008)	
#define HDR_HEIGHT_DIVTAB		(HDR_BASE+0x300C)
#define HDR_AVG_DIVTAB1			(HDR_BASE+0x3010)

#define HDR_ADAWT				(HDR_BASE+0x3020)
#define HDR_DEHZAA				(HDR_BASE+0x3024)
#define HDR_USMINTENS			(HDR_BASE+0x3028)
#define HDR_FUSWT				(HDR_BASE+0x302C)

#define LTM_LUM_DARK00			(HDR_BASE+0x3200)
#define LTM_LUM_BRIG00			(HDR_BASE+0x3300)

//AWB
#define AWB_BASE				(0x30010000)

#define AWB_FRONTGAIN_R			(AWB_BASE+0x0000)
#define AWB_FRONTGAIN_G			(AWB_BASE+0x0004)
#define AWB_FRONTGAIN_B			(AWB_BASE+0x0008)
#define AWB_RGBMAX_REG			(AWB_BASE+0x000C)
#define AWB_RGBMIN_REG			(AWB_BASE+0x0010)

#define AWB_WDW_PIXL0   		(AWB_BASE+0x1000)
#define AWB_WDW_PIXL1   		(AWB_BASE+0x1004)
#define AWB_WDW_PIXL2   		(AWB_BASE+0x1008)
#define AWB_WDW_PIXL3  			(AWB_BASE+0x100C)
#define AWB_WDW_PIXL4   		(AWB_BASE+0x1010)
#define AWB_WDW_PIXL5   		(AWB_BASE+0x1014)
#define AWB_WDW_PIXL6   		(AWB_BASE+0x1018)
#define AWB_WDW_PIXL7  			(AWB_BASE+0x101C)
#define AWB_WDW_PIXL8  			(AWB_BASE+0x1020)
#define AWB_WDW_PIXL9  			(AWB_BASE+0x1024)
#define AWB_WDW_PIXL10 			(AWB_BASE+0x1028)
#define AWB_WDW_PIXL11 			(AWB_BASE+0x102C)
#define AWB_WDW_PIXL12 			(AWB_BASE+0x1030)
#define AWB_WDW_PIXL13 			(AWB_BASE+0x1034)
#define AWB_WDW_PIXL14 			(AWB_BASE+0x1038)
#define AWB_WDW_PIXL15 			(AWB_BASE+0x103C)
#define AWB_WDW_PIXL16 			(AWB_BASE+0x1040)
#define AWB_WDW_PIXL17 			(AWB_BASE+0x1044)
#define AWB_WDW_PIXL18 			(AWB_BASE+0x1048)
#define AWB_WDW_PIXL19 			(AWB_BASE+0x104C)
#define AWB_WDW_PIXL20 			(AWB_BASE+0x1050)
#define AWB_WDW_PIXL21 			(AWB_BASE+0x1054)
#define AWB_WDW_PIXL22 			(AWB_BASE+0x1058)
#define AWB_WDW_PIXL23 			(AWB_BASE+0x105C)
#define AWB_WDW_PIXL24 			(AWB_BASE+0x1060)
#define AWB_WDW_PIXL25 			(AWB_BASE+0x1064)
#define AWB_WDW_PIXL26 			(AWB_BASE+0x1068)
#define AWB_WDW_PIXL27 			(AWB_BASE+0x106C)
#define AWB_WDW_PIXL28 			(AWB_BASE+0x1070)
#define AWB_WDW_PIXL29 			(AWB_BASE+0x1074)
#define AWB_WDW_PIXL30 			(AWB_BASE+0x1078)
#define AWB_WDW_PIXL31 			(AWB_BASE+0x107C)
#define AWB_WDW_PIXL32 			(AWB_BASE+0x1080)
                 
#define AWB_WDW_LINE0   		(AWB_BASE+0x10C0)
#define AWB_WDW_LINE1   		(AWB_BASE+0x10C4)
#define AWB_WDW_LINE2  			(AWB_BASE+0x10C8)
#define AWB_WDW_LINE3  			(AWB_BASE+0x10CC)
#define AWB_WDW_LINE4  			(AWB_BASE+0x10D0)
#define AWB_WDW_LINE5  			(AWB_BASE+0x10D4)
#define AWB_WDW_LINE6  			(AWB_BASE+0x10D8)
#define AWB_WDW_LINE7  			(AWB_BASE+0x10DC)
#define AWB_WDW_LINE8  			(AWB_BASE+0x10E0)
#define AWB_WDW_LINE9  			(AWB_BASE+0x10E4)
#define AWB_WDW_LINE10 			(AWB_BASE+0x10E8)
#define AWB_WDW_LINE11 			(AWB_BASE+0x10EC)
#define AWB_WDW_LINE12 			(AWB_BASE+0x10F0)
#define AWB_WDW_LINE13 			(AWB_BASE+0x10F4)
#define AWB_WDW_LINE14 			(AWB_BASE+0x10F8)
#define AWB_WDW_LINE15 			(AWB_BASE+0x10FC)
#define AWB_WDW_LINE16 			(AWB_BASE+0x1100)
                 
#define AWB_SRAM_ADDR_RC		(AWB_BASE+0x1140)
#define AWB_SRAM_RD_EN  		(AWB_BASE+0x1144)
#define AWB_R_INTG      		(AWB_BASE+0x1148)
#define AWB_G_INTG      		(AWB_BASE+0x114C)
#define AWB_B_INTG      		(AWB_BASE+0x1150)

#define AWB_HIST_RGB_SEL      	(AWB_BASE+0x2000)

#define AWB_HIST_CNT0      		(AWB_BASE+0x2040)
#define AWB_HIST_CNT1      		(AWB_BASE+0x2044)
#define AWB_HIST_CNT2      		(AWB_BASE+0x2048)
#define AWB_HIST_CNT3      		(AWB_BASE+0x204C)
#define AWB_HIST_CNT4      		(AWB_BASE+0x2050)
#define AWB_HIST_CNT5      		(AWB_BASE+0x2054)
#define AWB_HIST_CNT6     	 	(AWB_BASE+0x2058)
#define AWB_HIST_CNT7     	 	(AWB_BASE+0x205C)
#define AWB_HIST_CNT8      		(AWB_BASE+0x2060)
#define AWB_HIST_CNT9      		(AWB_BASE+0x2064)
#define AWB_HIST_CNT10      	(AWB_BASE+0x2068)
#define AWB_HIST_CNT11      	(AWB_BASE+0x206C)
#define AWB_HIST_CNT12      	(AWB_BASE+0x2070)
#define AWB_HIST_CNT13      	(AWB_BASE+0x2074)
#define AWB_HIST_CNT14      	(AWB_BASE+0x2078)
#define AWB_HIST_CNT15    		(AWB_BASE+0x207C)
#define AWB_HIST_CNT16    		(AWB_BASE+0x2080)
#define AWB_HIST_CNT17    		(AWB_BASE+0x2084)
#define AWB_HIST_CNT18    		(AWB_BASE+0x2088)
#define AWB_HIST_CNT19    		(AWB_BASE+0x208C)
#define AWB_HIST_CNT20    		(AWB_BASE+0x2090)
#define AWB_HIST_CNT21    		(AWB_BASE+0x2094)
#define AWB_HIST_CNT22    		(AWB_BASE+0x2098)
#define AWB_HIST_CNT23    		(AWB_BASE+0x209C)
#define AWB_HIST_CNT24    		(AWB_BASE+0x20A0)
#define AWB_HIST_CNT25    		(AWB_BASE+0x20A4)
#define AWB_HIST_CNT26    		(AWB_BASE+0x20A8)
#define AWB_HIST_CNT27    		(AWB_BASE+0x20AC)
#define AWB_HIST_CNT28    		(AWB_BASE+0x20B0)
#define AWB_HIST_CNT29    		(AWB_BASE+0x20B4)
#define AWB_HIST_CNT30 			(AWB_BASE+0x20B8)
#define AWB_HIST_CNT31 	  		(AWB_BASE+0x20BC)

//NIR
#define NIR_BASE				(0x30030000)
#define NIR_HIR_COEF1			(NIR_BASE + 0x0018)
#define NIR_HIR_COEF2			(NIR_BASE + 0x001C)
#define NIR_HIR_COEF3			(NIR_BASE + 0x0020)

#define NIR_CC_MODE				(NIR_BASE + 0x1000)
#define NIR_RS_RAT				(NIR_BASE + 0x1004)
#define NIR_GS_RAT				(NIR_BASE + 0x1008)
#define NIR_BS_RAT				(NIR_BASE + 0x100C)
#define NIR_CC_COEF11			(NIR_BASE + 0x1040)
#define NIR_CC_COEF12			(NIR_BASE + 0x1044)
#define NIR_CC_COEF13			(NIR_BASE + 0x1048)
#define NIR_CC_COEF14			(NIR_BASE + 0x104C)
#define NIR_CC_COEF21			(NIR_BASE + 0x1050)
#define NIR_CC_COEF22			(NIR_BASE + 0x1054)
#define NIR_CC_COEF23			(NIR_BASE + 0x1058)
#define NIR_CC_COEF24			(NIR_BASE + 0x105C)
#define NIR_CC_COEF31			(NIR_BASE + 0x1060)
#define NIR_CC_COEF32			(NIR_BASE + 0x1064)
#define NIR_CC_COEF33			(NIR_BASE + 0x1068)
#define NIR_CC_COEF34			(NIR_BASE + 0x106C)

#define NIR_CRT_LUMLUT0			(NIR_BASE + 0x1080)



#define NIR_IR_INTG				(NIR_BASE + 0x2000)
#define NIR_R_INTG				(NIR_BASE + 0x2004)
#define NIR_G_INTG				(NIR_BASE + 0x2008)
#define NIR_B_INTG				(NIR_BASE + 0x200C)
#define NIR_RGB_INTG			(NIR_BASE + 0x2010)

#define NIR_FUS_LUMLUT0			(NIR_BASE + 0x3080)

//NR_2D
#define NR_2D_BASE				0x30036000
#define NR_2D_THDL_REG			(NR_2D_BASE + 0x000)
#define NR_2D_THDH_REG			(NR_2D_BASE + 0x004)
#define NR_2D_COEF_REG			(NR_2D_BASE + 0x008)
#define NR_2D_GMIN_REG			(NR_2D_BASE + 0x00C)
#define NR_2D_DELTA_THD			(NR_2D_BASE + 0x010)
#define NR_2D_G_COEF1			(NR_2D_BASE + 0x014)
#define NR_2D_G_COEF2			(NR_2D_BASE + 0x018)
#define NR_2D_G_COEF3			(NR_2D_BASE + 0x01C)
#define NR_2D_G_COEF4			(NR_2D_BASE + 0x020)
#define NR_2D_RB_COEF1			(NR_2D_BASE + 0x024)
#define NR_2D_RB_COEF2			(NR_2D_BASE + 0x028)
#define NR_2D_RB_COEF3			(NR_2D_BASE + 0x02C)
#define NR_2D_H_SEL				(NR_2D_BASE + 0x030)
#define NR_2D_FLT_EN			(NR_2D_BASE + 0x034)

//BAYER_GAIN
#define BAYER_GAIN_BASE			0x30037000
#define NIR_R_GAIN_REG		(BAYER_GAIN_BASE+0x000)
#define NIR_G_GAIN_REG		(BAYER_GAIN_BASE+0x004)
#define NIR_B_GAIN_REG		(BAYER_GAIN_BASE+0x008)
#define NIR_RGBMAX_REG		(BAYER_GAIN_BASE+0x00C)
#define NIR_RGBMIN_REG		(BAYER_GAIN_BASE+0x010)

////AF
//#define AF_BASE					0x30021000
//#define AF_WDW0_VBEGIN			(AF_BASE + 0x000)
//#define AF_WDW0_VEND			(AF_BASE + 0x004)
//#define AF_WDW0_HBEGIN			(AF_BASE + 0x008)
//#define AF_WDW0_HEND			(AF_BASE + 0x00C)
//
//#define AF_WDW0_HZ				(AF_BASE + 0x094)

#if 1		//XM530
//NR_3D
#define NR_3D_BASE				0x30040000
#define NR_3D_DENOSIE_CTL		(NR_3D_BASE + 0x000)
#define NR_3D_ERR_SFT			(NR_3D_BASE + 0x014)

#define NR_3D_RAMP				(NR_3D_BASE + 0x004)
#define NR_3D_G1AMP				(NR_3D_BASE + 0x008)
#define NR_3D_G2AMP				(NR_3D_BASE + 0x00C)
#define NR_3D_BAMP				(NR_3D_BASE + 0x010)

#define NR_3D_YFLD_SPACE		(NR_3D_BASE + 0x030)
#define NR_3D_BFLD_SPACE		(NR_3D_BASE + 0x034)
#define NR_3D_DFT_YSADDR0		(NR_3D_BASE + 0x038)
#define NR_3D_DFT_ESADDR0		(NR_3D_BASE + 0x03C)

#define NR_3D_DIG_E1			(NR_3D_BASE + 0x020)
#define NR_3D_DIG_E2			(NR_3D_BASE + 0x024)
#define NR_3D_DIG_E3			(NR_3D_BASE + 0x028)

#define NR_3D_ERR_PAR			(NR_3D_BASE + 0x040)
#define NR_3D_BAYER_PAR			(NR_3D_BASE + 0x050)
#define NR_3D_NOISE_REG			(NR_3D_BASE + 0x060)

#define NR_3D_DFT_BSADDR0		(NR_3D_BASE + 0x0A0)
#define NR_3D_DFT_BSADDR1		(NR_3D_BASE + 0x0A4)
#define NR_3D_DFT_BSADDR2		(NR_3D_BASE + 0x0A8)
#define NR_3D_DFT_BSADDR3		(NR_3D_BASE + 0x0AC)
#define NR_3D_DFT_BSADDR4		(NR_3D_BASE + 0x0B0)
#define NR_3D_DFT_BSADDR5		(NR_3D_BASE + 0x0B4)
#define NR_3D_DFT_BSADDR6		(NR_3D_BASE + 0x0B8)
#define NR_3D_DFT_BSADDR7		(NR_3D_BASE + 0x0BC)

#define NR_3D_DDR_BHNUM			(NR_3D_BASE + 0x0C8)
#define NR_3D_DDR_YHNUM			(NR_3D_BASE + 0x0CC)
#define NR_3D_DDR_EHNUM			(NR_3D_BASE + 0x0D0)
#define NR_3D_ACTIVE_HNUM		(NR_3D_BASE + 0x0D4)
#define NR_3D_ACTIVE_VNUM		(NR_3D_BASE + 0x0D8)

#define NR_3D_WINERR_HBEGIN     (NR_3D_BASE + 0x120)
#define NR_3D_WINERR_HEND		(NR_3D_BASE + 0x124)
#define NR_3D_WINERR_VBEGIN     (NR_3D_BASE + 0x128)
#define NR_3D_WINERR_VEND		(NR_3D_BASE + 0x12C)

#define NR_3D_2D_NOISE_THR		(NR_3D_BASE + 0x130)
#define NR_3D_FIT2D2_WEIGHT1	(NR_3D_BASE + 0x134)
#define NR_3D_FIT2D2_WEIGHT2	(NR_3D_BASE + 0x138)

#define NR_3D_NOISE_MAP			(NR_3D_BASE + 0x144)
#define NR_3D_CHANGE_POINT		(NR_3D_BASE + 0x148)
#define NR_3D_FLT2D_PAR			(NR_3D_BASE + 0x14C)

#else// This is XM510 code,just for test

//NR_3D
#define NR_3D_BASE				0x30040000
#define NR_3D_DENOSIE_CTL		(NR_3D_BASE + 0x000)
#define NR_3D_ERR_SFT			(NR_3D_BASE + 0x014)
#define NR_3D_NR_LEVEL			(NR_3D_BASE + 0x018)

#define NR_3D_YFLD_SPACE		(NR_3D_BASE + 0x030)
#define NR_3D_BFLD_SPACE		(NR_3D_BASE + 0x034)
#define NR_3D_DFT_YSADDR0		(NR_3D_BASE + 0x038)
#define NR_3D_DFT_ESADDR0		(NR_3D_BASE + 0x03C)

#define NR_3D_DIG_E1			(NR_3D_BASE + 0x020)
#define NR_3D_DIG_E2			(NR_3D_BASE + 0x024)
#define NR_3D_DIG_E3			(NR_3D_BASE + 0x028)

#define NR_3D_ERR_PAR			(NR_3D_BASE + 0x040)
#define NR_3D_BAYER_PAR			(NR_3D_BASE + 0x050)
#define NR_3D_DDR_HNUM			(NR_3D_BASE + 0x0D0)
#define NR_3D_ACTIVE_HNUM		(NR_3D_BASE + 0x0D4)
#define NR_3D_YCTRL_ERR70		(NR_3D_BASE + 0x0D8)
#define NR_3D_YCTRL_ERRF8		(NR_3D_BASE + 0x0DC)

#define NR_3D_DFT_BSADDR0		(NR_3D_BASE + 0x0A0)
#define NR_3D_DFT_BSADDR1		(NR_3D_BASE + 0x0A4)
#define NR_3D_DFT_BSADDR2		(NR_3D_BASE + 0x0A8)
#define NR_3D_DFT_BSADDR3		(NR_3D_BASE + 0x0AC)
#define NR_3D_DFT_BSADDR4		(NR_3D_BASE + 0x0B0)
#define NR_3D_DFT_BSADDR5		(NR_3D_BASE + 0x0B4)
#define NR_3D_DFT_BSADDR6		(NR_3D_BASE + 0x0B8)
#define NR_3D_DFT_BSADDR7		(NR_3D_BASE + 0x0BC)

#define NR_3D_WINERR_HBEGIN     (NR_3D_BASE + 0x120)
#define NR_3D_WINERR_HEND		(NR_3D_BASE + 0x124)
#define NR_3D_WINERR_VBEGIN     (NR_3D_BASE + 0x128)
#define NR_3D_WINERR_VEND		(NR_3D_BASE + 0x12C)

#define NR_3D_WINERR_RSHIFT		(NR_3D_BASE + 0x140)
#define NR_3D_WINERR_LEVEL		(NR_3D_BASE + 0x144)
#define NR_3D_CHANGE_POINT		(NR_3D_BASE + 0x148)
#define NR_3D_FLT2D_PAR			(NR_3D_BASE + 0x14C)

#endif
// Demosaic_cut_f
#define DMSC_CUT			0x30051000
#define DMSC_CUT_H_BEGIN	(DMSC_CUT+0x0)			
#define DMSC_CUT_H_END		(DMSC_CUT+0x4)			
#define DMSC_CUT_V_BEGIN	(DMSC_CUT+0x8)			
#define DMSC_CUT_V_END		(DMSC_CUT+0xC)			

// Demosaic
#define DEMOSAIC_BASE			0x30050000
#define DEMOSAIC_G_HOFST		(DEMOSAIC_BASE + 0x000)
#define DEMOSAIC_DHV_OFST		(DEMOSAIC_BASE + 0x004)
#define DEMOSAIC_DHV_K			(DEMOSAIC_BASE + 0x008)
#define DEMOSAIC_GCALC_MODE		(DEMOSAIC_BASE + 0x00C)
#define DEMOSAIC_THRMAIN		(DEMOSAIC_BASE + 0x010)
#define DEMOSAIC_THRSUB 		(DEMOSAIC_BASE + 0x014)

// CSM
#define CSM_BASE				0x30060000

#define CSM_RGB_MAX				(CSM_BASE+0x000)
#define CSM_RGB_MIN				(CSM_BASE+0x004)

#define CSM_R_OFST_REG			(CSM_BASE+0x040)
#define CSM_R1_COEF_REG			(CSM_BASE+0x044)
#define CSM_R2_COEF_REG			(CSM_BASE+0x048)
#define CSM_R3_COEF_REG			(CSM_BASE+0x04C)
#define CSM_G_OFST_REG			(CSM_BASE+0x050)
#define CSM_G1_COEF_REG			(CSM_BASE+0x054)
#define CSM_G2_COEF_REG			(CSM_BASE+0x058)
#define CSM_G3_COEF_REG			(CSM_BASE+0x05C)
#define CSM_B_OFST_REG			(CSM_BASE+0x060)
#define CSM_B1_COEF_REG			(CSM_BASE+0x064)
#define CSM_B2_COEF_REG			(CSM_BASE+0x068)
#define CSM_B3_COEF_REG			(CSM_BASE+0x06C)

// Gamma96
#define GAMMA96_BASE			0x30061000
#define GAMMA96_LINE0_DAT0 		(GAMMA96_BASE+0x000)

// RGB2YC
#define RGB2YC_BASE				0x30062000	


// Demoire
#define DEMOIRE_BASE			0x30063000
#define DEMOIRE_V_THD			(DEMOIRE_BASE+0x000)
#define DEMOIRE_KV				(DEMOIRE_BASE+0x004)
#define DEMOIRE_DF_THD_MAX		(DEMOIRE_BASE+0x008)
#define DEMOIRE_DF_THD_MIN		(DEMOIRE_BASE+0x00C)
#define DEMOIRE_GAIN_MIN		(DEMOIRE_BASE+0x010)
#define DEMOIRE_KC				(DEMOIRE_BASE+0x014)
#define DEMOIRE_BYPASS			(DEMOIRE_BASE+0x018)

// CC
#define CC_BASE					0x30071000
#define CC_EN_REG				(CC_BASE+0x000)
#define CC_HUE_OFST				(CC_BASE+0x018)
#define CC_YS_TRAN_DAT0			(CC_BASE+0x040)
#define CC_S_TRAN_DAT0			(CC_BASE+0x084)
#define CC_HS_TRAN_DAT0			(CC_BASE+0x0E4)
#define CC_HH_H1_SATRT			(CC_BASE+0x200)
#define CC_HH_H1_END			(CC_BASE+0x204)
#define CC_HH_H1_MAX1			(CC_BASE+0x208)
#define CC_HH_H1_MAX2			(CC_BASE+0x20C)
#define CC_HH_H1_DMAX			(CC_BASE+0x210)
#define CC_HH_H1_K1				(CC_BASE+0x214)
#define CC_HH_H1_K2				(CC_BASE+0x218)

#define CC_HH_H2_SATRT			(CC_BASE+0x21C)
#define CC_HH_H2_END			(CC_BASE+0x220)
#define CC_HH_H2_MAX1			(CC_BASE+0x224)
#define CC_HH_H2_MAX2			(CC_BASE+0x228)
#define CC_HH_H2_DMAX			(CC_BASE+0x22C)
#define CC_HH_H2_K1				(CC_BASE+0x230)
#define CC_HH_H2_K2				(CC_BASE+0x234)

#define CC_HH_H3_SATRT			(CC_BASE+0x240)
#define CC_HH_H3_END			(CC_BASE+0x244)
#define CC_HH_H3_MAX1			(CC_BASE+0x248)
#define CC_HH_H3_MAX2			(CC_BASE+0x24C)
#define CC_HH_H3_DMAX			(CC_BASE+0x250)
#define CC_HH_H3_K1				(CC_BASE+0x254)
#define CC_HH_H3_K2				(CC_BASE+0x258)

//#define CC_HH_H4_SATRT			(CC_BASE+0x25C)
//#define CC_HH_H4_END			(CC_BASE+0x260)
//#define CC_HH_H4_MAX1			(CC_BASE+0x264)
//#define CC_HH_H4_MAX2			(CC_BASE+0x268)
//#define CC_HH_H4_DMAX			(CC_BASE+0x26C)
//#define CC_HH_H4_K1				(CC_BASE+0x270)
//#define CC_HH_H4_K2				(CC_BASE+0x274)
//
//#define CC_HH_H5_SATRT			(CC_BASE+0x280)
//#define CC_HH_H5_END			(CC_BASE+0x284)
//#define CC_HH_H5_MAX1			(CC_BASE+0x288)
//#define CC_HH_H5_MAX2			(CC_BASE+0x28C)
//#define CC_HH_H5_DMAX			(CC_BASE+0x290)
//#define CC_HH_H5_K1				(CC_BASE+0x294)
//#define CC_HH_H5_K2				(CC_BASE+0x298)
//
//#define CC_HH_H6_SATRT			(CC_BASE+0x29C)
//#define CC_HH_H6_END			(CC_BASE+0x2A0)
//#define CC_HH_H6_MAX1			(CC_BASE+0x2A4)
//#define CC_HH_H6_MAX2			(CC_BASE+0x2A8)
//#define CC_HH_H6_DMAX			(CC_BASE+0x2AC)
//#define CC_HH_H6_K1				(CC_BASE+0x2B0)
//#define CC_HH_H6_K2				(CC_BASE+0x2B4)




// Y_Gamma
#define YGAMMA_BASE				0x30072000
#define YGAMMA_LINE0_DAT0 		(YGAMMA_BASE+0x000)

//Y_hist
#define YHIST_BASE				0x30073000
#define YHIST_CNT0				(YHIST_BASE+0x000)

//C_tran
#define CTRAN_BASE				0x30074000
#define TRAN_LINE0_DAT0			(CTRAN_BASE+0x000)
#define TRAN_LINE0_DAT7			(CTRAN_BASE+0x01C)
#define TRAN_LINE0_DAT8			(CTRAN_BASE+0x020)

// Sharpness
#define SHARPEN_BASE			0x30075000

#define SHARPEN_YMTH1			(SHARPEN_BASE+0x000)
#define SHARPEN_YMTH2			(SHARPEN_BASE+0x004)
#define SHARPEN_YM_K			(SHARPEN_BASE+0x008)
#define SHARPEN_KM0				(SHARPEN_BASE+0x00C)
#define SHARPEN_WM0				(SHARPEN_BASE+0x010)
#define SHARPEN_WM1				(SHARPEN_BASE+0x014)
#define SHARPEN_WM2				(SHARPEN_BASE+0x018)
#define SHARPEN_WM3				(SHARPEN_BASE+0x01C)
#define SHARPEN_WM4				(SHARPEN_BASE+0x020)
#define SHARPEN_WM5				(SHARPEN_BASE+0x024)

#define SHARPEN_YMDTH1			(SHARPEN_BASE+0x040)
#define SHARPEN_YMDTH2			(SHARPEN_BASE+0x044)
#define SHARPEN_YMD_K			(SHARPEN_BASE+0x048)
#define SHARPEN_KMD_MAX			(SHARPEN_BASE+0x04C)
#define SHARPEN_WMD0			(SHARPEN_BASE+0x050)
#define SHARPEN_WMD1			(SHARPEN_BASE+0x054)
#define SHARPEN_WMD2			(SHARPEN_BASE+0x058)
#define SHARPEN_WMD3			(SHARPEN_BASE+0x05C)
#define SHARPEN_WMD4			(SHARPEN_BASE+0x060)
#define SHARPEN_WMD5			(SHARPEN_BASE+0x064)

#define SHARPEN_YHTH1			(SHARPEN_BASE+0x080)
#define SHARPEN_YHTH2			(SHARPEN_BASE+0x084)
#define SHARPEN_YH_K			(SHARPEN_BASE+0x088)
#define SHARPEN_KH0				(SHARPEN_BASE+0x08C)
#define SHARPEN_WH0				(SHARPEN_BASE+0x090)
#define SHARPEN_WH1				(SHARPEN_BASE+0x094)
#define SHARPEN_WH2				(SHARPEN_BASE+0x098)
#define SHARPEN_WH3				(SHARPEN_BASE+0x09C)
#define SHARPEN_WH4				(SHARPEN_BASE+0x0A0)
#define SHARPEN_WH5				(SHARPEN_BASE+0x0A4)

#define SHARPEN_YHDTH1			(SHARPEN_BASE+0x0C0)
#define SHARPEN_YHDTH2			(SHARPEN_BASE+0x0C4)
#define SHARPEN_YHD_K			(SHARPEN_BASE+0x0C8)
#define SHARPEN_KHD_MAX			(SHARPEN_BASE+0x0CC)
#define SHARPEN_WHD0			(SHARPEN_BASE+0x0D0)
#define SHARPEN_WHD1			(SHARPEN_BASE+0x0D4)
#define SHARPEN_WHD2			(SHARPEN_BASE+0x0D8)
#define SHARPEN_WHD3			(SHARPEN_BASE+0x0DC)
#define SHARPEN_WHD4			(SHARPEN_BASE+0x0E0)
#define SHARPEN_WHD5			(SHARPEN_BASE+0x0E4)

#define SHARPEN_KH00			(SHARPEN_BASE+0x100)
#define SHARPEN_KH01			(SHARPEN_BASE+0x104)
#define SHARPEN_KL00			(SHARPEN_BASE+0x108)
#define SHARPEN_KL01			(SHARPEN_BASE+0x10C)
#define SHARPEN_KH1				(SHARPEN_BASE+0x110)
#define SHARPEN_KL1				(SHARPEN_BASE+0x114)
#define SHARPEN_DLTMAX			(SHARPEN_BASE+0x118)

#define SHARPEN_DFKD			(SHARPEN_BASE+0x11C)
#define SHARPEN_DFMAX			(SHARPEN_BASE+0x120)

#define SHARPEN_ENH_STREN		(SHARPEN_BASE+0x130)
#define SHARPEN_ENH_THR			(SHARPEN_BASE+0x134)
#define SHARPEN_ENH_GMAX		(SHARPEN_BASE+0x138)

#define SHARPEN_TRAN_DAT0		(SHARPEN_BASE+0x140)

#define SHARPEN_C_COEF1			(SHARPEN_BASE+0x1C0)
#define SHARPEN_C_COEF2			(SHARPEN_BASE+0x1C4)
#define SHARPEN_C_COEF3			(SHARPEN_BASE+0x1C8)
#define SHARPEN_C_FLT_SEL		(SHARPEN_BASE+0x1CC)
//#define SHARPEN_C_KR1			(SHARPEN_BASE+0x1C0)
//#define SHARPEN_C_KR2			(SHARPEN_BASE+0x1C4)
//#define SHARPEN_C_KG1			(SHARPEN_BASE+0x1C8)
//#define SHARPEN_C_KG2			(SHARPEN_BASE+0x1CC)
//#define SHARPEN_C_KB1			(SHARPEN_BASE+0x1D0)
//#define SHARPEN_C_KB2			(SHARPEN_BASE+0x1D4)
//#define SHARPEN_C_ZONE_EN		(SHARPEN_BASE+0x1D8)
//#define SHARPEN_C_COEF1			(SHARPEN_BASE+0x1DC)
//#define SHARPEN_C_COEF2			(SHARPEN_BASE+0x1E0)
//#define SHARPEN_C_COEF3			(SHARPEN_BASE+0x1E4)

//#define SHARPEN_C_SAT_DAT0		(SHARPEN_BASE+0x200)

#define SHARPEN_EN				(SHARPEN_BASE+0x240)
#define SHARPEN_DENOISE_EN		(SHARPEN_BASE+0x248)
#define SHARPEN_NOISETHR		(SHARPEN_BASE+0x250)

// YC_Gain
#define YC_GAIN_BASE			0x30076000
#define Y_GAIN					(YC_GAIN_BASE+(0x000))
#define CB_GAIN					(YC_GAIN_BASE+(0x004))
#define CR_GAIN					(YC_GAIN_BASE+(0x008))
#define Y_OFST					(YC_GAIN_BASE+(0x00C))
#define Y_MAX_THD				(YC_GAIN_BASE+(0x010))
#define Y_MIN_THD				(YC_GAIN_BASE+(0x014))


//PLL use to upscaler
#define PLL_BASE  				0x20000000
#define PLL_SYSCTRLREG_LOCK		(PLL_BASE+0x0000)

#define PLLB1_CTRL				(PLL_BASE+0x0010)
#define PLLB2_CTRL				(PLL_BASE+0x0014)
#define PLL_SENCLK_CTRL 		(PLL_BASE+0x003C)
#define PLL_ISPCLK_CTRL 		(PLL_BASE+0x0040)
#define PLL_LCDCLK_CTRL 		(PLL_BASE+0x0044)
#define PLL_ISPBUSCLK_CTRL		(PLL_BASE+0x0048)
#define PLL_VENCCLK_CTRL		(PLL_BASE+0x004C)



//Luma(BT1120)
#define LUM_VI_BASE			0x300E0000
#define LUM_DEC_SYNC_CTRL	(LUM_VI_BASE+0x00C) 
#define LUM_DEC_HEAD_DAT1	(LUM_VI_BASE+0x010)
#define LUM_DEC_HEAD_MSK1 	(LUM_VI_BASE+0x01C)
#define LUM_DEC_HEAD_MSK2 	(LUM_VI_BASE+0x020)
#define LUM_DEC_HEAD_MSK3 	(LUM_VI_BASE+0x024)
#define LUM_DEC_SOL_DAT 	(LUM_VI_BASE+0x028)
#define LUM_DEC_EOL_DAT 	(LUM_VI_BASE+0x02C)
#define LUM_DEC_SOF_DAT 	(LUM_VI_BASE+0x030)
#define LUM_DEC_EOF_DAT 	(LUM_VI_BASE+0x034)

#define LUM_DEC_SOL_MSK 	(LUM_VI_BASE+0x038)
#define LUM_DEC_EOL_MSK 	(LUM_VI_BASE+0x03C)
#define LUM_DEC_SOF_MSK 	(LUM_VI_BASE+0x040)
#define LUM_DEC_EOF_MSK 	(LUM_VI_BASE+0x044)

#define LUM_TST_TOTALSIZE_H			(LUM_VI_BASE+0x080)
#define LUM_TST_TOTALSIZE_V			(LUM_VI_BASE+0x084)
#define LUM_TST_ACTIVESIZE_H		(LUM_VI_BASE+0x088)
#define LUM_TST_ACTIVESIZE_V		(LUM_VI_BASE+0x08C)

#define LUM_CUT_BEGIN_H			(LUM_VI_BASE+0x098)
#define LUM_CUT_END_H			(LUM_VI_BASE+0x09C)
#define LUM_CUT_BEGIN_V			(LUM_VI_BASE+0x0A0)
#define LUM_CUT_END_V			(LUM_VI_BASE+0x0A4)


//Video Store
#define VSTORE_BASE				0x30084000
#define VSTORE_EN_CH0			(VSTORE_BASE+0x0034)
#define VSTORE_EN_CH1			(VSTORE_BASE+0x1034)
#define VSTORE_EN_CH2			(VSTORE_BASE+0x2034)
#define VSTORE_EN_CH3			(VSTORE_BASE+0x3034)

#endif





