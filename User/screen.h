#ifndef __SCREEN_H__
#define 	__SCREEN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <math.h>
#include <string.h>
#include "system.h"
#include "i2c.h"
#include "u8g2.h"



#define u8       			unsigned char  //unsigned char
#define MAX_LEN    		128  		//
#define OLED_ADDRESS  0x78 		// oled模块从机地址
#define OLED_CMD   		0x00  	// 写命令
#define OLED_DATA  		0x40  	// 写数据

extern u8g2_t u8g2;

typedef struct
{
	uint8_t Screen_refresh_Flag;	//屏幕刷新标志
	uint8_t Screen_show_Flag;			//屏幕显示标志
	uint16_t Screen_show_num;			//屏幕显示时间计数
	int8_t NUM[5];								//屏幕数字显示
}Screen_Flag;  
extern Screen_Flag SCR_FLAG;

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
void u8g2Init(u8g2_t *u8g2);
void u8g2_test(u8g2_t *u8g2);
void screen_show_str(u8g2_t *u8g2, const uint8_t  *font, u8g2_uint_t x, u8g2_uint_t y, uint8_t dir, const char *str);
void SYS_Open_show(u8g2_t *u8g2);
void SYS_Close_show(u8g2_t *u8g2);
void Page_show(u8g2_t *u8g2);
void nonCircularRightShift(char* str, int n, char fillChar);
void Screen_float(float num);

#ifdef __cplusplus
}
#endif

#endif
