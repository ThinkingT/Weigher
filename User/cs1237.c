/*
cs1237.c		V1.0		20250710
cs1237����ģ������
��������ԭ�������޸�
SCK   PB9	�����Զ��壩
SDI/O PB8
*/

#include "cs1237.h"


#define ADC_Bit  20 //ADC��Чλ����������λ ���24λ
#define SCK_1  HAL_GPIO_WritePin(M_CLK_GPIO_Port,M_CLK_Pin, GPIO_PIN_SET)//SCLK = 1
#define SCK_0  HAL_GPIO_WritePin(M_CLK_GPIO_Port,M_CLK_Pin, GPIO_PIN_RESET)//SCLK = 0
#define DAT_1  HAL_GPIO_WritePin(M_SDA_GPIO_Port,M_SDA_Pin, GPIO_PIN_SET)//DOUT = 1
#define DAT_0  HAL_GPIO_WritePin(M_SDA_GPIO_Port,M_SDA_Pin, GPIO_PIN_RESET)//DOUT = 0

#define	NOP_5()		delay_us(5);
#define	NOP30()		delay_us(30);
#define	NOP40()		delay_us(5);
#define One_CLK  SCK_1;NOP40();SCK_0;NOP40();
#define CS_CON  0X00   //оƬ������ �ڲ�REF ���40HZ PGA=128 ͨ��A 0X1C   

unsigned char PoolFlag;


uint8_t GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

//SDA����Ϊ����
void CS1237_SDA_SetInput(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	GPIO_InitStruct.Pin = M_SDA_Pin;				 //PB8
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;           
  GPIO_InitStruct.Pull = GPIO_PULLUP;				//��������
//	GPIO_InitStruct.Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	HAL_GPIO_Init(M_SDA_GPIO_Port, &GPIO_InitStruct);					 //�����趨������ʼ��PB8
}

//SDA����Ϊ���
void CS1237_SDA_SetOutput(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	GPIO_InitStruct.Pin = M_SDA_Pin;				 //PB8
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
//	GPIO_InitStruct.Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	HAL_GPIO_Init(M_SDA_GPIO_Port, &GPIO_InitStruct);					 //�����趨������ʼ��PB8
}

//��ʱ500US 25MHZ
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

//����CS1237оƬ
void Con_CS1237(unsigned char ConfigDat)
{
	CS_Val.flag = 0;
	unsigned char i;
	unsigned char dat;
	unsigned char count_i=0;//�����ʱ��
	
	dat = ConfigDat;
	SCK_0;//ʱ������
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//оƬ׼�����������  ʱ���Ѿ�Ϊ0������Ҳ��Ҫ��CS1237ȫ������Ϊ0���㶼׼����
	{
		delay_500us(10);
		count_i++;
		if(count_i > 150)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return;//��ʱ����ֱ���˳�����
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
	One_CLK;//37     д����0x65
	for(i=0;i<8;i++)// 38 - 45�������ˣ�д8λ����
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
	One_CLK;//46������������������
	CS_Val.flag = 1;
}

//��ȡоƬ����������
unsigned char Read_CON(void)
{
	CS_Val.flag = 0;
	unsigned char i;
	unsigned char dat=0;//��ȡ��������
	unsigned char count_i=0;//�����ʱ��
//	unsigned char k=0,j=0;//�м����
	
	SCK_0;//ʱ������
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//оƬ׼�����������  ʱ���Ѿ�Ϊ0������Ҳ��Ҫ��CS1237ȫ������Ϊ0���㶼׼����
	{
		delay_500us(10);
		count_i++;
		if(count_i > 150)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return 1;//��ʱ����ֱ���˳�����
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
	One_CLK;//37     д����0x56
//	DAT_0;
	CS1237_SDA_SetInput();
	for(i=0;i<8;i++)// 38 - 45�������ˣ���ȡ����
	{
		One_CLK;
		dat <<= 1;
		if(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))
			dat++;
	}
	One_CLK;//46������������������
	CS1237_SDA_SetOutput();
	DAT_1;
	
	CS_Val.flag = 1;
	return dat;
}

//��ȡADC���ݣ����ص���һ���з�������
unsigned long Read_CS1237(void)
{
	CS_Val.flag = 0;
	unsigned char i;
//	unsigned long dat=0;//��ȡ��������
	long dat=0;//��ȡ��������
	unsigned char count_i=0;//�����ʱ��
	DAT_1;//�˿�����1��51�ر�
	SCK_0;//ʱ������
	CS1237_SDA_SetInput();
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin) == 0);
	while(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))//оƬ׼�����������  ʱ���Ѿ�Ϊ0������Ҳ��Ҫ��CS1237����Ϊ0���㶼׼����
	{
		delay_500us(10);
		count_i++;
		if(count_i > 300)
		{
			CS1237_SDA_SetOutput();
			SCK_1;
			DAT_1;
			return 0;//��ʱ����ֱ���˳�����
		}
	}
	DAT_1;//�˿�����1��51�ر�
	dat=0;
	CS1237_SDA_SetInput();
	for(i=0;i<24;i++)//��ȡ24λ��Чת��
	{
		SCK_1;
		NOP40();
		dat <<= 1;
		if(GPIO_Read(M_SDA_GPIO_Port,M_SDA_Pin))
			dat ++;
		SCK_0;
		NOP40();	
	}
//	for(i=0;i<3;i++)//һ������27������
//	{
//		One_CLK;
//	}
	CS1237_SDA_SetOutput();
	DAT_1;
	
//	Uart_send_hex_to_txt(dat>>16);
//	Uart_send_hex_to_txt(dat>>8);
//	Uart_send_hex_to_txt(dat);
	
//	if((dat&0x800000) == 0x800000)	//���λΪ1����ʾ����Ϊ��ֵ
//	{
//		dat = ~dat;
//		dat =dat+1;
//		dat =dat&0xffffff;
//		PoolFlag = 1;
////		UART_Send_Byte(0x2D);				// - ��
//	}
//	else 
//	{
//		PoolFlag = 0;
////		UART_Send_Byte(0x2B);				//+  ��
//	}
		
	
//	printf("ad val=%10X \r\n",dat);//unsigned long 0��4294967295
//	usb_printf("ad val=%10X \r\n",dat);
//	usb_printf("%ld \r\n",dat);
		
	//�ȸ��ݺ궨���������Чλ������һЩ����
//	i = 24 - ADC_Bit;//i��ʾ��Ҫ������λ��
//	dat >>= i;//���������λ��
	
	dat = dat / 10;
	CS_Val.flag = 1;
	return dat;
}

//��ζ�ȡȡ��ֵ
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
// ��ȡCS1237���ڲ��¶�
//----------------------------------------------------------------------------------
void CS1237ReadInterlTemp(void)
{
	uint8_t config;
	
	Con_CS1237(RefOut_OFF | SpeedSelct_640HZ | PGA_1 | CH_Temp);//����CS1237оƬ
	HAL_Delay(500);
	
	
	while(1)
	{
		Read_CS1237();
		HAL_Delay(1);
	}
	
	Con_CS1237(RefOut_ON | SpeedSelct_640HZ | PGA_1 | CH_A);//�ָ�����
}

//��ȡ����
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


