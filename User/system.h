#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "tim.h"
#include "adc.h"
#include "usbd_cdc_if.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdarg.h>
#include "screen.h"
#include "cs1237.h"

/*复用定时器中断
	设置不同的定时时长（定时时间为复用定时器时基倍数）
	以下宏定义皆为时基倍数
*/
#define time_base			10		//系统时基
	
#define SERIAL_TIME  			(1000/time_base)		//串口发送数据，1s定时
#define ADC_CHK_TIME			(200/time_base)			//ADC转换，100ms定时
#define SERVO_TIME				(20/time_base)			//舵机运动，50ms定时
#define SCREEN_ref_TIME		(100/time_base)			//屏幕刷新，100ms定时
#define SCREEN_show_TIME	(20000/time_base)		//屏幕息屏，20s定时
#define DHT20_TIME				(1000/time_base)		//温湿度传感器检测，1s定时
#define T_D_Show_TIME			(3000/time_base)		//温湿度显示转换，3s定时
	
#define ERR 0
#define OK 1

#define Ref_vol  			3.45f
#define BAT_Low_Vol 	3.0f

typedef struct
{
	uint8_t SYS_PWR_OFF_Flag;	//系统关机标志
	uint8_t ADC_CHK_Flag;			//ADC监视开启标志
	uint8_t ADC_ERR_CHK_FLAG;	//ADC错误监控开启标志
	uint8_t DCDC_EN_Flag;			//DCDC电源开启标志
	uint8_t Fan_speed_Flag;		//风扇速度标志
	uint8_t CS_Flag;						//cs1237读取标志（0为不工作，1为角度增加，2为角度减少）
}System_Flag;  
extern System_Flag SYS_FLAG;

typedef struct
{
	float Battery_CR;				//电池放电电流
  float Battery_Voltage;		//电池电压
	float Charge_Votage;			//充电电压
	float Charge_CR;					//充电电流
}ADC_VAL;  
extern ADC_VAL VAL_MONITER;


void system_Init(void);	//系统初始化
void system_GO(void);		//系统执行流程
void ADC_GetValue(void);
void ZERO_SW_Trigger(void);
void MOD_SW_Trigger(void);
void PWR_OFF_SW_Trigger(void);

void LL_usb_reload(void);
	
void usb_printf(const char *format, ...);






#ifdef __cplusplus
}
#endif

#endif
