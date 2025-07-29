/*
cs1237.c		V1.0		20250710
cs1237称重模块驱动
根据正点原子例程修改
SCK   PB9	（可自定义）
SDI/O PB8
*/

#include "cs1237.h"


#define ADC_Bit  20 //ADC有效位数，带符号位 最高24位
#define SCK_1  HAL_GPIO_WritePin(M_CLK_GPIO_Port,M_CLK_Pin, GPIO_PIN_SET)//SCLK = 1
#define SCK_0  HAL_GPIO_WritePin(M_CLK_GPIO_Port,M_CLK_Pin, GPIO_PIN_RESET)//SCLK = 0
#define DAT_1  HAL_GPIO_WritePin(M_SDA_GPIO_Port,M_SDA_Pin, GPIO_PIN_SET)//DOUT = 1
#define DAT_0  HAL_GPIO_WritePin(M_SDA_GPIO_Port,M_SDA_Pin, GPIO_PIN_RESET)//DOUT = 0

#define	NOP_5()		delay_us(5);
#define	NOP30()		delay_us(30);
#define	NOP40()		delay_us(5);
#define One_CLK  SCK_1;NOP40();SCK_0;NOP40();
#define CS_CON  0X00   //芯片地配置 内部REF 输出40HZ PGA=128 通道A 0X1C   

unsigned char PoolFlag;


uint8_t GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

//SDA设置为输入
void CS1237_SDA_SetInput(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	GPIO_InitStruct.Pin = M_SDA_Pin;				 //PB8
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;           
  GPIO_InitStruct.Pull = GPIO_PULLUP;				//上拉输入
//	GPIO_InitStruct.Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	HAL_GPIO_Init(M_SDA_GPIO_Port, &GPIO_InitStruct);					 //根据设定参数初始化PB8
}

//SDA设置为输出
void CS1237_SDA_SetOutput(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	GPIO_InitStruct.Pin = M_SDA_Pin;				 //PB8
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
//	GPIO_InitStruct.Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	HAL_GPIO_Init(M_SDA_GPIO_Port, &GPIO_InitStruct);					 //根据设定参数初始化PB8
}

//延时500US 25MHZ
void delay_500us(unsigned char a)
{	
	unsigned char i,j,b;
	for(b=0;b<a;b++)
	{
		i = 13;
		j = 37;
		do
		{
			while (--j);
		} while (--i);
	}
}

//配置CS1237芯片
void Con_CS1237(unsigned char ConfigDat)
{
	CS_Val.flag = 0;
	unsigned char i;
	unsigned char dat;
	unsigned char count_i=0;//溢出计时器
	
	dat = ConfigDat;
	SCK_0;//时钟拉低
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//芯片准备好数据输出  时钟已经为0，数据也需要等CS1237全部拉低为0才算都准备好
	{
		delay_500us(10);
		count_i++;
		if(count_i > 150)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return;//超时，则直接退出程序
		}
	}
	for(i=0;i<29;i++)// 1 - 29
	{
//		One_CLK;
		SCK_1;
		NOP40();
		SCK_0;
		NOP40();
	}
	CS1237_SDA_SetOutput();
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//30
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//31
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//32
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//33
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//34
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//35
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//36
//	DAT_0;
	One_CLK;//37     写入了0x65
	for(i=0;i<8;i++)// 38 - 45个脉冲了，写8位数据
	{
		
		if(dat&0x80)
			DAT_1;
		else
			DAT_0;
		dat <<= 1;
		SCK_1;
		NOP40();
		SCK_0;
		NOP40();
	}
	One_CLK;//46个脉冲拉高数据引脚
	CS_Val.flag = 1;
}

//读取芯片的配置数据
unsigned char Read_CON(void)
{
	CS_Val.flag = 0;
	unsigned char i;
	unsigned char dat=0;//读取到的数据
	unsigned char count_i=0;//溢出计时器
//	unsigned char k=0,j=0;//中间变量
	
	SCK_0;//时钟拉低
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//芯片准备好数据输出  时钟已经为0，数据也需要等CS1237全部拉低为0才算都准备好
	{
		delay_500us(10);
		count_i++;
		if(count_i > 150)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return 1;//超时，则直接退出程序
		}
	}
	CS1237_SDA_SetOutput();
	for(i=0;i<29;i++)// 1 - 29
	{
		One_CLK;
	}
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//30
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//31
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//32
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//33
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//34
	DAT_1;SCK_1;NOP30();SCK_0;NOP30();//35
	DAT_0;SCK_1;NOP30();SCK_0;NOP30();//36
	DAT_1;
	One_CLK;//37     写入了0x56
//	DAT_0;
	CS1237_SDA_SetInput();
	for(i=0;i<8;i++)// 38 - 45个脉冲了，读取数据
	{
		One_CLK;
		dat <<= 1;
		if(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))
			dat++;
	}
	One_CLK;//46个脉冲拉高数据引脚
	CS1237_SDA_SetOutput();
	DAT_1;
	
	CS_Val.flag = 1;
	return dat;
}

//读取ADC数据，返回的是一个有符号数据
unsigned long Read_CS1237(void)
{
	CS_Val.flag = 0;
	unsigned char i;
//	unsigned long dat=0;//读取到的数据
	long dat=0;//读取到的数据
	unsigned char count_i=0;//溢出计时器
	DAT_1;//端口锁存1，51必备
	SCK_0;//时钟拉低
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin) == 0);
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//芯片准备好数据输出  时钟已经为0，数据也需要等CS1237拉低为0才算都准备好
	{
		delay_500us(10);
		count_i++;
		if(count_i > 300)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return 0;//超时，则直接退出程序
		}
	}
	DAT_1;//端口锁存1，51必备
	dat=0;
	CS1237_SDA_SetInput();
	for(i=0;i<24;i++)//获取24位有效转换
	{
		SCK_1;
		NOP40();
		dat <<= 1;
		if(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))
			dat ++;
		SCK_0;
		NOP40();	
	}
//	for(i=0;i<3;i++)//一共输入27个脉冲
//	{
//		One_CLK;
//	}
	CS1237_SDA_SetOutput();
	DAT_1;
	
//	Uart_send_hex_to_txt(dat>>16);
//	Uart_send_hex_to_txt(dat>>8);
//	Uart_send_hex_to_txt(dat);
	
//	if((dat&0x800000) == 0x800000)	//最高位为1，表示输入为负值
//	{
//		dat = ~dat;
//		dat =dat+1;
//		dat =dat&0xffffff;
//		PoolFlag = 1;
////		UART_Send_Byte(0x2D);				// - 号
//	}
//	else 
//	{
//		PoolFlag = 0;
////		UART_Send_Byte(0x2B);				//+  号
//	}
		
	
//	printf("ad val=%10X \r\n",dat);//unsigned long 0～4294967295
//	usb_printf("ad val=%10X \r\n",dat);
//	usb_printf("%ld \r\n",dat);
		
	//先根据宏定义里面的有效位，丢弃一些数据
//	i = 24 - ADC_Bit;//i表示将要丢弃的位数
//	dat >>= i;//丢弃多余的位数
	
	dat = dat / 10;
	CS_Val.flag = 1;
	return dat;
}

//多次读取取均值
unsigned long Read_CS1237_filter(void)
{
	uint32_t CS1237_temp = 0;
	for(uint8_t i = 0; i < 20; i++){
		CS1237_temp += Read_CS1237();
		HAL_Delay(1);
	}
	return (CS1237_temp/20);
}

//
//----------------------------------------------------------------------------------
// 读取CS1237的内部温度
//----------------------------------------------------------------------------------
void CS1237ReadInterlTemp(void)
{
	uint8_t config;
	
	Con_CS1237(RefOut_OFF | SpeedSelct_640HZ | PGA_1 | CH_Temp);//配置CS1237芯片
	HAL_Delay(500);
	
	
	while(1)
	{
		Read_CS1237();
		HAL_Delay(1);
	}
	
	Con_CS1237(RefOut_ON | SpeedSelct_640HZ | PGA_1 | CH_A);//恢复配置
}

//获取重量
void Get_Weight(void){
	CS_Val.adc_tmp = Read_CS1237();
//	CS_Val.weight = (CS_Val.adc_tmp_start - CS_Val.adc_tmp) / bili;
	CS_Val.M = CS_Val.adc_tmp_start - CS_Val.adc_tmp;
	CS_Val.weight = CS_Val.M / bili;
	if(CS_Val.weight < 0){
		CS_Val.weight = 0 - CS_Val.weight;
		CS_Val.weight_int = (int16_t)CS_Val.weight;
		CS_Val.weight_float = (uint16_t)((CS_Val.weight - CS_Val.weight_int) * 10);
		CS_Val.weight_int = 0 - CS_Val.weight_int;
	}
	else{
		CS_Val.weight_int = (int16_t)CS_Val.weight;
		CS_Val.weight_float = (uint16_t)((CS_Val.weight - CS_Val.weight_int) * 10);
	}
//	CS_Val.weight_int = (int16_t)CS_Val.weight;
//	CS_Val.weight_float = (uint16_t)((CS_Val.weight - CS_Val.weight_int) * 10);
//	usb_printf("%f, %d, %d\r\n",CS_Val.weight,CS_Val.weight_int, CS_Val.weight_float);
}


