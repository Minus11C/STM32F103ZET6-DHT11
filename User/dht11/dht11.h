#ifndef __DHT11_H
#define	__DHT11_H

#include "stm32f10x.h"

/************************** DHT11 数据类型定义********************************/
typedef struct
{
	uint8_t  humi_int;		//湿度的整数部分
	uint8_t  humi_deci;	 	//湿度的小数部分
	uint8_t  temp_int;	 	//温度的整数部分
	uint8_t  temp_deci;	 	//温度的小数部分
	uint8_t  check_sum;	 	//校验和
    void (* _DHT11_GPIO_Config_)( void );
    void (* _DHT11_GPIO_SetBits_)(void);
    void (* _DHT11_Mode_Out_PP_)(void);
    void (* _DHT11_Mode_IPU_)(void);
    void (* _DHT11_Dout_0_)(void);
    void (* _DHT11_Dout_1_)(void);
    uint8_t (* _DHT11_Dout_IN_)(void);
    
} DHT11_Data_TypeDef;

/************************** DHT11 函数声明 ********************************/
void                     DHT11_Init                      ( DHT11_Data_TypeDef * DHT11_Data );
uint8_t                  DHT11_Read_TempAndHumidity      ( DHT11_Data_TypeDef * DHT11_Data );

#endif /* __DHT11_H */







