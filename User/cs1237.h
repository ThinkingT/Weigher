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

#define RefOut_OFF         0X40//�ر� REF �����
#define RefOut_ON          0X00//REF ���������

#define SpeedSelct_10HZ    0x00//ADC �������Ϊ 10Hz
#define SpeedSelct_40HZ    0x10//ADC �������Ϊ 40Hz
#define SpeedSelct_640HZ   0x20//ADC �������Ϊ 6400Hz
#define SpeedSelct_1280HZ  0x30//ADC �������Ϊ 12800Hz

#define PGA_1              0X00//�Ŵ�λ��ѡ��1
#define PGA_2              0X04//�Ŵ�λ��ѡ��2
#define PGA_64             0X08//�Ŵ�λ��ѡ��64
#define PGA_128            0X0C//�Ŵ�λ��ѡ��128

#define CH_A               0X00//����ͨ��ѡ��A
#define CH_Temp            0X02//����ͨ��ѡ���ڲ��¶Ȳ���
#define CH_Int             0X00//����ͨ��ѡ���ڲ���·

#define bili		36.37f		//��λ���ض�Ӧ��ADCֵ

typedef struct
{
	unsigned long adc_tmp_start;	//CS1237��׼ֵ
	unsigned long adc_tmp;				//CS1237ģ�������
	float weight;									//�������ˣ�
	int16_t weight_int;								//������������
	uint8_t weight_float;							//����С������
	char weight_str[20];								//�����ַ���
	long M;												//�м�ֵ
	uint8_t flag;									//��־
}CS1237;  
extern CS1237 CS_Val;


extern unsigned char PoolFlag;

//����CS1237оƬ
void Con_CS1237(unsigned char ch);
//��ȡоƬ����������
unsigned char Read_CON(void);
//��ȡADC����
unsigned long Read_CS1237(void);
//��ζ�ȡȡ��ֵ
unsigned long Read_CS1237_filter(void);
//��ȡ�¶�����
void CS1237ReadInterlTemp(void);
//��ȡ����
void Get_Weight(void);


#ifdef __cplusplus
}
#endif

#endif
