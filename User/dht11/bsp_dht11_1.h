#ifndef __BSP_DHT11_1_H
#define __BSP_DHT11_1_H

#include "stm32f10x.h"

/************************** DHT11_1 连接引脚定义********************************/
#define      DHT11_Dout_SCK_APBxClock_FUN              RCC_APB2PeriphClockCmd
#define      DHT11_Dout_GPIO_CLK                       RCC_APB2Periph_GPIOB

#define      DHT11_Dout_GPIO_PORT                      GPIOB
#define      DHT11_Dout_GPIO_PIN                       GPIO_Pin_12

void DHT11_1_GPIO_Config(void);
void DHT11_1_GPIO_SetBits(void);
void DHT11_1_Mode_Out_PP(void);
void DHT11_1_Mode_IPU(void);
void DHT11_1_Dout_0(void);
void DHT11_1_Dout_1(void);
uint8_t DHT11_1_Dout_IN(void);

#endif
