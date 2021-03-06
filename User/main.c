/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   dht11温湿度传感器测试实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "./systick/bsp_SysTick.h"
#include "./dht11/dht11.h"
#include "./usart/bsp_usart.h"

#define  Number_of_nodes     2


/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	DHT11_Data_TypeDef DHT11_Data[Number_of_nodes];
	int ch;
	
	/* 配置SysTick 为1us中断一次 */
	SysTick_Init();

	USART_Config();//初始化串口1
	DHT11_Init (&DHT11_Data[0]);/*初始化DTT11的引脚*/
    
	printf("\r\n***多点测温系统***\r\n");
    if( DHT11_Read_TempAndHumidity ( & DHT11_Data[0] ) == SUCCESS)
	{
		printf("\r\n读取DHT11_1成功!  湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
		DHT11_Data[0].humi_int,DHT11_Data[0].humi_deci,DHT11_Data[0].temp_int,DHT11_Data[0].temp_deci);
	}
	if( DHT11_Read_TempAndHumidity ( & DHT11_Data[1] ) == SUCCESS)
	{
		printf("\r\n读取DHT11_2成功!  湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
		DHT11_Data[1].humi_int,DHT11_Data[1].humi_deci,DHT11_Data[1].temp_int,DHT11_Data[1].temp_deci);
	}	
	
    printf("\r\n请输入要查找的测温节点:\r\n");
	while(1)
	{	
             ch = getchar();
            if(ch == 49)    //1的assic码为 49
			{
                if( DHT11_Read_TempAndHumidity ( & DHT11_Data[1] ) == SUCCESS)
                    printf("\r\n读取DHT11_1成功!\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
                    DHT11_Data[0].humi_int,DHT11_Data[0].humi_deci,DHT11_Data[0].temp_int,DHT11_Data[0].temp_deci);
			}
            else if(ch == 50) //2的assic码为 50
            {
                if( DHT11_Read_TempAndHumidity ( & DHT11_Data[1] ) == SUCCESS)
                    printf("\r\n读取DHT11_2成功!\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
                    DHT11_Data[1].humi_int,DHT11_Data[1].humi_deci,DHT11_Data[1].temp_int,DHT11_Data[1].temp_deci);
			}			
			else
			{
				printf("还没有此节点\r\n");
			}
			
		 Delay_ms(1000);
	}

	
}
/*********************************************END OF FILE**********************/
