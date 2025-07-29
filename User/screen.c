/*
screen.c		V1.0		20240630
oled屏幕驱动
*/

#include "screen.h"

Screen_Flag SCR_FLAG;
u8g2_t u8g2;

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    /* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
    static uint8_t buffer[128];
    static uint8_t buf_idx;
    uint8_t *data;

    switch (msg)
    {
    case U8X8_MSG_BYTE_INIT:
    {
        /* add your custom code to init i2c subsystem */
        MX_I2C2_Init(); // I2C初始化
    }
    break;

    case U8X8_MSG_BYTE_START_TRANSFER:
    {
        buf_idx = 0;
    }
    break;

    case U8X8_MSG_BYTE_SEND:
    {
        data = (uint8_t *)arg_ptr;

        while (arg_int > 0)
        {
            buffer[buf_idx++] = *data;
            data++;
            arg_int--;
        }
    }
    break;

    case U8X8_MSG_BYTE_END_TRANSFER:
    {
        if (HAL_I2C_Master_Transmit(&hi2c2, OLED_ADDRESS, buffer, buf_idx, 5) != HAL_OK)
//        if (HAL_I2C_Master_Transmit_IT(&hi2c1, OLED_ADDRESS, buffer, buf_idx) != HAL_OK)
            return 0;
    }
    break;

    case U8X8_MSG_BYTE_SET_DC:
        break;

    default:
        return 0;
    }

    return 1;
}

void delay_us(uint32_t time)
{
    uint32_t i = 8 * time;
    while (i--)
        ;
}

uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    switch (msg)
    {
    case U8X8_MSG_DELAY_100NANO: // delay arg_int * 100 nano seconds
        __NOP();
        break;
    case U8X8_MSG_DELAY_10MICRO: // delay arg_int * 10 micro seconds
        for (uint16_t n = 0; n < 320; n++)
        {
            __NOP();
        }
        break;
    case U8X8_MSG_DELAY_MILLI: // delay arg_int * 1 milli second
        HAL_Delay(1);
        break;
    case U8X8_MSG_DELAY_I2C: // arg_int is the I2C speed in 100KHz, e.g. 4 = 400 KHz
        delay_us(5);
        break;                    // arg_int=1: delay by 5us, arg_int = 4: delay by 1.25us
    case U8X8_MSG_GPIO_I2C_CLOCK: // arg_int=0: Output low at I2C clock pin
        break;                    // arg_int=1: Input dir with pullup high for I2C clock pin
    case U8X8_MSG_GPIO_I2C_DATA:  // arg_int=0: Output low at I2C data pin
        break;                    // arg_int=1: Input dir with pullup high for I2C data pin
    case U8X8_MSG_GPIO_MENU_SELECT:
        u8x8_SetGPIOResult(u8x8, /* get menu select pin state */ 0);
        break;
    case U8X8_MSG_GPIO_MENU_NEXT:
        u8x8_SetGPIOResult(u8x8, /* get menu next pin state */ 0);
        break;
    case U8X8_MSG_GPIO_MENU_PREV:
        u8x8_SetGPIOResult(u8x8, /* get menu prev pin state */ 0);
        break;
    case U8X8_MSG_GPIO_MENU_HOME:
        u8x8_SetGPIOResult(u8x8, /* get menu home pin state */ 0);
        break;
    default:
        u8x8_SetGPIOResult(u8x8, 1); // default return value
        break;
    }
    return 1;
}
void u8g2Init(u8g2_t *u8g2)
{
    u8g2_Setup_ssd1306_i2c_128x32_univision_f(u8g2, U8G2_R3, u8x8_byte_hw_i2c, u8x8_gpio_and_delay); // 设置屏幕
    u8g2_InitDisplay(u8g2);                                                                          // 初始化屏幕
    u8g2_SetPowerSave(u8g2, 0);                                                                      // 打开显示
    u8g2_ClearBuffer(u8g2);
}

void screen_show_str(u8g2_t *u8g2, const uint8_t  *font, u8g2_uint_t x, u8g2_uint_t y, uint8_t dir, const char *str)
{
	u8g2_ClearBuffer(u8g2);
	u8g2_SetFont(u8g2, font);
	u8g2_SetFontDirection(u8g2, dir);
	u8g2_DrawUTF8(u8g2, x, y, str);
	u8g2_SendBuffer(u8g2);
}


void u8g2_test(u8g2_t *u8g2)
{
//	uint8_t i = 0;
//	do
//	{
//		u8g2_ClearBuffer(u8g2);
//		u8g2_DrawBox(u8g2, 0, 0, i++, 32);
//		u8g2_SendBuffer(u8g2);
//		HAL_Delay(10);
//	} while (i != 128);
//	HAL_Delay(2000);
//	u8g2_ClearBuffer(u8g2);
//	u8g2_SetFont(u8g2, u8g2_font_ncenB14_tf);
//	u8g2_SetFontDirection(u8g2, 0);
//	u8g2_DrawStr(u8g2, 15, 20, "Abc");
//	u8g2_SetFontDirection(u8g2, 1);
//	u8g2_DrawStr(u8g2, 15, 20, "Abc");
//	u8g2_SendBuffer(u8g2);
//	HAL_Delay(2000);
//	screen_clean(u8g2);
//	screen_show_str(u8g2, u8g2_font_ncenB14_tf, 0, 16, 0, "Hello World! ");
//	HAL_Delay(2000);
	screen_show_str(u8g2, u8g2_font_wqy14_t_chinese3, 16, 32, 1, "你好 ");
	HAL_Delay(2000);
	u8g2_ClearDisplay(u8g2);
}

//开机动画
void SYS_Open_show(u8g2_t *u8g2)
{
	uint8_t time = 15;
	for(uint8_t i = 0; i<18; i++)
	{
		u8g2_ClearBuffer(u8g2);
		u8g2_SetFontDirection(u8g2, 1);
//		u8g2_SetFont(u8g2, u8g2_font_streamline_all_t);
//		u8g2_DrawGlyph(u8g2, 5, i*3+2, 0x00DD);		//小风扇
		u8g2_SetFont(u8g2, u8g2_font_luBS18_tf );
		u8g2_DrawStr(u8g2, 5, i*3+2, "SC");
		u8g2_SendBuffer(u8g2);
		HAL_Delay(time);
	}
//	u8g2_ClearDisplay(u8g2);
	SCR_FLAG.Screen_show_Flag = 1;	//开启屏幕刷新
}

//关机动画
void SYS_Close_show(u8g2_t *u8g2)
{
	uint8_t time = 15;
	for(uint8_t i = 0; i<32; i++)
	{
		u8g2_ClearBuffer(u8g2);
		u8g2_SetFontDirection(u8g2, 1);
//		u8g2_SetFont(u8g2, u8g2_font_streamline_all_t);
//		u8g2_DrawGlyph(u8g2, 5, (i*3+65), 0x00DD);		//小风扇
		u8g2_SetFont(u8g2, u8g2_font_luBS18_tf );
		u8g2_DrawStr(u8g2, 5, i*3+56, "SC");
		u8g2_SendBuffer(u8g2);
		HAL_Delay(time);
	}
}

void Page_show(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2);
	u8g2_SetFontDirection(u8g2, 1);
	
	Screen_float(CS_Val.weight);
//	char t[10];
//	sprintf(t, "%d.%d g",CS_Val.weight_int, CS_Val.weight_float);
	u8g2_SetFont(u8g2, u8g2_font_battery19_tn);
	if(VAL_MONITER.Charge_Votage >= 4.0f)
	{
		u8g2_DrawGlyph(u8g2, 3, 115, 0x0036);			//充电指示
	}
	else																			//电量显示
	{
		if(VAL_MONITER.Battery_Voltage >= 4.10f)
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0035);		//5电指示
		else if(VAL_MONITER.Battery_Voltage >= 4.0f && VAL_MONITER.Battery_Voltage < 4.1f)
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0034);		//4电指示
		else if(VAL_MONITER.Battery_Voltage >= 3.8f && VAL_MONITER.Battery_Voltage < 4.0f)
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0033);		//3电指示
		else if(VAL_MONITER.Battery_Voltage >= 3.5f && VAL_MONITER.Battery_Voltage < 3.8f)
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0032);		//2电指示
		else if(VAL_MONITER.Battery_Voltage >= 3.2f && VAL_MONITER.Battery_Voltage < 3.5f)
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0031);		//1电指示
		else
			u8g2_DrawGlyph(u8g2, 3, 115, 0x0030);		//0电指示
	}
//	u8g2_SetFont(u8g2, u8g2_font_ncenB18_tf);
//	u8g2_SetFont(u8g2, u8g2_font_luBS18_tf );
	u8g2_SetFont(u8g2, u8g2_font_fub17_tf   );
	u8g2_DrawStr(u8g2, 2, 5, CS_Val.weight_str);
//	u8g2_SetFont(u8g2, u8g2_font_fub17_tf   );
	u8g2_DrawStr(u8g2, 7, 90, "g");
//	u8g2_SetFontDirection(u8g2, 0);
//	if(dht20_data.data_OK_Flag)								//温湿度切换显示
//	{
//		char t[4];
//		if(dht20_data.data_show_Flag)						//显示温度
//		{
//			sprintf(t, "%d",(int8_t)dht20_data.temperature);
//			u8g2_SetFont(u8g2, u8g2_font_ncenB12_tf);
//			u8g2_DrawStr(u8g2, 2, 30, t);
//			u8g2_SetFont(u8g2, u8g2_font_9x15_t_symbols);
//			u8g2_DrawGlyph(u8g2, 22, 30, 0x2103);		//℃
//		}
//		else
//		{
//			sprintf(t, "%d",(int8_t)dht20_data.humidity);
//			u8g2_SetFont(u8g2, u8g2_font_ncenB12_tf);
//			u8g2_DrawStr(u8g2, 0, 30, t);
//			u8g2_SetFont(u8g2, u8g2_font_9x15_t_symbols);
//			u8g2_DrawGlyph(u8g2, 22, 30, 0x0025);		//%
//		}
//	}
//	else
//	{
//		u8g2_SetFont(u8g2, u8g2_font_9x15_t_symbols);
//		u8g2_DrawGlyph(u8g2, 2, 30, 0x002D);		//-
//		u8g2_DrawGlyph(u8g2, 14, 30, 0x002D);		//-
//	}
//	u8g2_SetFont(u8g2, u8g2_font_streamline_all_t);
//	u8g2_DrawGlyph(u8g2, 5, 65, 0x00DD);		//小风扇图标
//	switch(SYS_FLAG.Fan_speed_Flag)					//风量显示
//	{
//		case 0:
//			u8g2_DrawGlyph(u8g2, 5, 90, 0x0193);		//0%
//		break;
//		case 1:
//			u8g2_DrawGlyph(u8g2, 6, 90, 0x0198);		//20%
//		break;
//		case 2:
//			u8g2_DrawGlyph(u8g2, 6, 90, 0x0199);		//50%
//		break;
//		case 3:
//			u8g2_DrawGlyph(u8g2, 5, 90, 0x019B);		//75%
//		break;
//		case 4:
//			u8g2_DrawGlyph(u8g2, 5, 90, 0x0195);		//100%
//		break;
//	}
//	u8g2_DrawGlyph(u8g2, 5, 120, 0x01ed);		//循环图标
	u8g2_SendBuffer(u8g2);
}

//非循环右移字符串
void nonCircularRightShift(char* str, int n, char fillChar){
	if (!str || n <= 0) return;
	
	int len = strlen(str);
	if (n >= len) {
		memset(str, fillChar, len);
		return;
	}
	memmove(str + n, str, len - n);  // 移动前部分到后面
	memset(str, fillChar, n);         // 填充移出部分的空位
}

//屏幕需要显示的浮点数
void Screen_float(float num){
	sprintf(CS_Val.weight_str, "%d.%d \r\n",CS_Val.weight_int, CS_Val.weight_float);
//	usb_printf("%f\r\n", num);
//	usb_printf("%s\r\n", CS_Val.weight_str);
	if(fabs(num) >= 1000){
//		usb_printf("%s\r\n", CS_Val.weight_str);
		return;
	}
	else if(fabs(num) >= 100){
		nonCircularRightShift(CS_Val.weight_str, 1, '	');
//		usb_printf("%s\r\n", CS_Val.weight_str);
		return;
	}
	else if(fabs(num) >= 10){
		nonCircularRightShift(CS_Val.weight_str, 2, '	');
//		usb_printf("%s\r\n", CS_Val.weight_str);
		return;
	}
	else if(fabs(num) >= 1){
		nonCircularRightShift(CS_Val.weight_str, 3, '	');
//		usb_printf("%s\r\n", CS_Val.weight_str);
		return;
	}
	else if(fabs(num) >= 0){
		nonCircularRightShift(CS_Val.weight_str, 3, '	');
//		usb_printf("%s\r\n", CS_Val.weight_str);
		return;
	}
}

