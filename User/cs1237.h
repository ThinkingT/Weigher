#ifndef __CS1237_H
#define __CS1237_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "gpio.h"
#include "system.h"

#define M_SDA_Pin GPIO_PIN_8
#define M_SDA_GPIO_Port GPIOB

#define RefOut_OFF         0X40//关闭 REF 输出。
#define RefOut_ON          0X00//REF 正常输出。

#define SpeedSelct_10HZ    0x00//ADC 输出速率为 10Hz
#define SpeedSelct_40HZ    0x10//ADC 输出速率为 40Hz
#define SpeedSelct_640HZ   0x20//ADC 输出速率为 6400Hz
#define SpeedSelct_1280HZ  0x30//ADC 输出速率为 12800Hz

#define PGA_1              0X00//放大位数选择1
#define PGA_2              0X04//放大位数选择2
#define PGA_64             0X08//放大位数选择64
#define PGA_128            0X0C//放大位数选择128

#define CH_A               0X00//输入通道选择A
#define CH_Temp            0X02//输入通道选择内部温度测试
#define CH_Int             0X00//输入通道选择内部短路

#define bili		36.37f		//单位克重对应的ADC值

typedef struct
{
	unsigned long adc_tmp_start;	//CS1237基准值
	unsigned long adc_tmp;				//CS1237模块的数据
	float weight;									//重量（克）
	int16_t weight_int;								//重量整数部分
	uint8_t weight_float;							//重量小数部分
	char weight_str[20];								//浮点字符串
	long M;												//中间值
	uint8_t flag;									//标志
}CS1237;  
extern CS1237 CS_Val;


extern unsigned char PoolFlag;

//配置CS1237芯片
void Con_CS1237(unsigned char ch);
//读取芯片的配置数据
unsigned char Read_CON(void);
//读取ADC数据
unsigned long Read_CS1237(void);
//多次读取取均值
unsigned long Read_CS1237_filter(void);
//获取温度数据
void CS1237ReadInterlTemp(void);
//获取重量
void Get_Weight(void);


#ifdef __cplusplus
}
#endif

#endif
