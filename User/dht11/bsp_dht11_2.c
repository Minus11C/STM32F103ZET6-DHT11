#include "./dht11/bsp_dht11_2.h"

void DHT11_2_GPIO_Config(void)
{
    /*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure; 

	
	/*开启DHT11_Dout_GPIO_PORT的外设时钟*/
    DHT11_2_Dout_SCK_APBxClock_FUN ( DHT11_2_Dout_GPIO_CLK, ENABLE );	
 
	/*选择要控制的DHT11_Dout_GPIO_PORT引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;	

	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*调用库函数，初始化DHT11_2_Dout_GPIO_PORT*/
  	GPIO_Init ( DHT11_2_Dout_GPIO_PORT, &GPIO_InitStructure );		  

}

/*
 * 函数名：DHT11_2_Mode_Out_PP
 * 描述  ：使DHT11-DATA引脚变为推挽输出模式
 * 输入  ：无
 * 输出  ：无
 */
void DHT11_2_Mode_Out_PP(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;

	 	/*选择要控制的DHT11_2_Dout_GPIO_PORT引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;	

	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/*调用库函数，初始化DHT11_2_Dout_GPIO_PORT*/
  	GPIO_Init(DHT11_2_Dout_GPIO_PORT, &GPIO_InitStructure);	 	 
	
}

/*
 * 函数名：DHT11_2_Mode_IPU
 * 描述  ：使DHT11-DATA引脚变为上拉输入模式
 * 输入  ：无
 * 输出  ：无
 */
void DHT11_2_Mode_IPU(void)
{
 	  GPIO_InitTypeDef GPIO_InitStructure;

	  	/*选择要控制的DHT11_2_Dout_GPIO_PORT引脚*/	
	  GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;

	   /*设置引脚模式为浮空输入模式*/ 
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ; 

	  /*调用库函数，初始化DHT11_2_Dout_GPIO_PORT*/
	  GPIO_Init(DHT11_2_Dout_GPIO_PORT, &GPIO_InitStructure);	 
}


void DHT11_2_Dout_0(void)
{
    GPIO_ResetBits ( DHT11_2_Dout_GPIO_PORT, DHT11_2_Dout_GPIO_PIN);
}

void DHT11_2_Dout_1(void)
{
    GPIO_SetBits ( DHT11_2_Dout_GPIO_PORT, DHT11_2_Dout_GPIO_PIN );
}

uint8_t DHT11_2_Dout_IN(void)
{
    return  GPIO_ReadInputDataBit ( DHT11_2_Dout_GPIO_PORT, DHT11_2_Dout_GPIO_PIN );
}

void DHT11_2_GPIO_SetBits(void)
{
    GPIO_SetBits(DHT11_2_Dout_GPIO_PORT, DHT11_2_Dout_GPIO_PIN);
}
