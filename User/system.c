/*
system.c		V1.0		20240630
负责系统初始化及正常运行
*/

#include "system.h"

System_Flag SYS_FLAG;
CS1237 CS_Val;
ADC_VAL VAL_MONITER;

uint16_t Serial_Num = 0; // 串口信息输出频率计数

/*************************系统相关函数*************************************/
void system_Init(void) // 系统初始化
{
	HAL_GPIO_WritePin(PWR_ON_GPIO_Port, PWR_ON_Pin, GPIO_PIN_SET); //打开电源
	HAL_TIM_Base_Start_IT(&htim1);				//定时器任务开启
	u8g2Init(&u8g2);					  					//u8g2库初始化
	SYS_Open_show(&u8g2);									//开机图片
	SYS_FLAG.CS_Flag = 1;								//读取CS1237
	SYS_FLAG.ADC_CHK_Flag = 1;						//读取ADC
	Con_CS1237(RefOut_ON | SpeedSelct_640HZ | PGA_1 | CH_A);//配置CS1237芯片
	HAL_Delay(100);
//	CS_Val.adc_tmp_start = Read_CS1237();
	CS_Val.adc_tmp_start = Read_CS1237_filter();
	SYS_FLAG.CS_Flag = 2;
}

/*************************系统循环函数*********************************/
void system_GO(void)
{
	//屏幕刷新
	if(SCR_FLAG.Screen_refresh_Flag && (!SYS_FLAG.SYS_PWR_OFF_Flag))
	{
		Page_show(&u8g2);		//屏幕刷新函数
		SCR_FLAG.Screen_refresh_Flag = 0;
	}
	
	if(!SCR_FLAG.Screen_show_Flag)
	{
		u8g2_ClearDisplay(&u8g2);	//清屏
	}
	//关机
	if(SYS_FLAG.SYS_PWR_OFF_Flag)	
	{
		SYS_FLAG.SYS_PWR_OFF_Flag = 0;	//清除标志
		SYS_FLAG.CS_Flag = 0;					//取消读取CS1237
		SYS_Close_show(&u8g2);					//显示关机动画
		HAL_GPIO_WritePin(PWR_ON_GPIO_Port, PWR_ON_Pin, GPIO_PIN_RESET); //关闭电源
	}
	//读取CS1237
	if(SYS_FLAG.CS_Flag && CS_Val.flag){
		if(SYS_FLAG.CS_Flag == 1){
//			CS_Val.adc_tmp_start = Read_CS1237();
			CS_Val.adc_tmp_start = Read_CS1237_filter();
			SYS_FLAG.CS_Flag = 2;
		}
		else if(SYS_FLAG.CS_Flag == 2){
			Get_Weight();
		}
	}
	
}

/*************************TIM中断回调函数*********************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == (&htim1))
	{ // 系统定时器10ms时基
		//串口数据发送
		if ((Serial_Num % SERIAL_TIME) == 0)
		{
			usb_printf("[OK]	Battery_Voltage = %.2fV  Charge_Votage = %.2f\r\n", VAL_MONITER.Battery_Voltage, VAL_MONITER.Charge_Votage);

//			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);; 
		}
		//刷新屏幕标志
		if((Serial_Num % SCREEN_ref_TIME == 0) && SCR_FLAG.Screen_show_Flag)
		{
			SCR_FLAG.Screen_refresh_Flag = 1;
		}
//		//屏幕显示计时
//		if(SCR_FLAG.Screen_show_Flag)
//		{
//			if(SCR_FLAG.Screen_show_num >= SCREEN_show_TIME)
//			{
//				SCR_FLAG.Screen_show_num = 0;
//				SCR_FLAG.Screen_show_Flag = 0;	//到达息屏时间
//			}
//			else
//			SCR_FLAG.Screen_show_num++;	//屏幕显示计数，屏幕显示时间单独模拟计时器
//		}
		//ADC监控
		if (SYS_FLAG.ADC_CHK_Flag && ((Serial_Num % ADC_CHK_TIME) == 0))
		{
			ADC_GetValue();
		}
		//计数器
		if (Serial_Num >= 2000)
		{
			Serial_Num = 0;
		}
//		else
			Serial_Num++;
	}
}

/*************************ADC数据读取*********************************/
void ADC_GetValue(void)
{
	int16_t ADC_VAL = 0;
	SYS_FLAG.ADC_CHK_Flag = 0;
	
	//开启ADC校准
	HAL_ADCEx_Calibration_Start(&hadc1);	//校准ADC
	
	//开启ADC转换 电池电压	BAT_VOL
	HAL_ADC_Start(&hadc1);										//第1次
	if(HAL_ADC_PollForConversion(&hadc1, 100)== HAL_OK)//等待ADC转换完成，超时为100ms
	{
		//判断ADC是否转换成功
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
		{
			ADC_VAL = HAL_ADC_GetValue(&hadc1);
			VAL_MONITER.Battery_Voltage = (float)(Ref_vol*ADC_VAL/4096*2);
//			usb_printf("[TEST]	Battery_Voltage = %d\r\n", ADC_VAL);
			if(VAL_MONITER.Battery_Voltage <= BAT_Low_Vol)	//电压过低关机
				PWR_OFF_SW_Trigger();
		}
	}
	
	//开启ADC转换 充电电压	CHG_VOL
	HAL_ADC_Start(&hadc1);										//第2次
	//等待ADC转换完成，超时为100ms
	if(HAL_ADC_PollForConversion(&hadc1, 100)== HAL_OK)
	{
		//判断ADC是否转换成功
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
		{
			ADC_VAL = HAL_ADC_GetValue(&hadc1);
			VAL_MONITER.Charge_Votage = (float)(Ref_vol*ADC_VAL/4096*2);		
//			usb_printf("[TEST]	Charge_Votage = %d\r\n", ADC_VAL);		
		}
	}
	
	//停止ADC转换
	HAL_ADC_Stop(&hadc1);										//stop conv
	SYS_FLAG.ADC_CHK_Flag = 1;
}


/*************************按键事件*********************************/
//去皮操作
void ZERO_SW_Trigger(void){
	SYS_FLAG.CS_Flag = 1;	//去皮
}
//模式切换
void MOD_SW_Trigger(void){
}
//关机模式
void PWR_OFF_SW_Trigger(void){
	HAL_TIM_Base_Stop_IT(&htim1);				// 定时器任务关闭
	SCR_FLAG.Screen_refresh_Flag = 0;		//清除屏屏幕刷新标志
	SYS_FLAG.SYS_PWR_OFF_Flag = 1;			//系统关机
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == PWR_OFF_CHK_Pin)
  {
    if(HAL_GPIO_ReadPin(PWR_OFF_CHK_GPIO_Port, PWR_OFF_CHK_Pin) == GPIO_PIN_RESET)
    {
			PWR_OFF_SW_Trigger();
    }
	}
	if(GPIO_Pin == ZERO_SW_Pin)
  {
    if(HAL_GPIO_ReadPin(ZERO_SW_GPIO_Port, ZERO_SW_Pin) == GPIO_PIN_RESET)
    {
			ZERO_SW_Trigger();
    }
	}
	if(GPIO_Pin == MOD_SW_Pin)
  {
    if(HAL_GPIO_ReadPin(MOD_SW_GPIO_Port, MOD_SW_Pin) == GPIO_PIN_RESET)
    {
//			MOD_SW_Trigger();
    }
	}
}


//将USB-P拉低，再拉高，以模拟重新拔插的过程
//注意，此函数需要放在USB初始化函数的前面，否则不会生效
void LL_usb_reload(void)  
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
  HAL_Delay(500);    
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
  HAL_Delay(500);    
}

/*************************串口收发相关参数*********************************/
//int fputc(int ch, FILE *f)
//{
//	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff); // huart1需要根据你的配置修改
//	return ch;
//}
//int fgetc(FILE *f)
//{
//	uint8_t ch = 0;
//	while (HAL_UART_Receive(&huart1, &ch, 1, 0xffff) != HAL_OK)
//		;
//	return ch;
//}
 
void usb_printf(const char *format, ...)
{
	va_list args;
	uint32_t length;
	static uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];
//    
//    va_start(args, format);
//    // 确保不超过缓冲区大小
//    length = vsnprintf((char *)UserTxBufferFS, 
//                      APP_TX_DATA_SIZE - 1,  // 留出一个空字符位置
//                      format,                // 移除不必要的(char *)转换
//                      args);
//    va_end(args);

//    // 确保以NULL结尾
//    UserTxBufferFS[length] = '\0';
//    
//    // 检查是否有有效数据
//    if (length > 0)
//    {
//        // 添加传输状态检查
//        USBD_StatusTypeDef status;
//        do {
//            status = CDC_Transmit_FS(UserTxBufferFS, length);
//            // 如果USB忙，添加适当延迟或使用RTOS任务延时
//            if(status == USBD_BUSY) {
//                HAL_Delay(1);
//            }
//        } while(status == USBD_BUSY);
//    }
 
    va_start(args, format);
    length = vsnprintf((char *)UserTxBufferFS, APP_TX_DATA_SIZE, (char *)format, args);
    va_end(args);
    CDC_Transmit_FS(UserTxBufferFS, length);
}
