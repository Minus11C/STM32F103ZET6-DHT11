/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   dht11��ʪ�ȴ���������ʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� �Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "./systick/bsp_SysTick.h"
#include "./dht11/dht11.h"
#include "./usart/bsp_usart.h"

#define  Number_of_nodes     2


/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	DHT11_Data_TypeDef DHT11_Data[Number_of_nodes];
	
	
	/* ����SysTick Ϊ1us�ж�һ�� */
	SysTick_Init();

	USART_Config();//��ʼ������1
	printf("\r\n***������ϵͳ***\r\n");

	/*��ʼ��DTT11������*/
	DHT11_Init (&DHT11_Data[0]);
	
	while(1)
	{	
			/*����DHT11_Read_TempAndHumidity��ȡ��ʪ�ȣ����ɹ����������Ϣ*/
			if( DHT11_Read_TempAndHumidity ( & DHT11_Data[0] ) == SUCCESS)
			{
				printf("\r\n��ȡDHT11_1�ɹ�!\r\n\r\nʪ��Ϊ%d.%d ��RH ���¶�Ϊ %d.%d�� \r\n",\
				DHT11_Data[0].humi_int,DHT11_Data[0].humi_deci,DHT11_Data[0].temp_int,DHT11_Data[0].temp_deci);
			}
			if( DHT11_Read_TempAndHumidity ( & DHT11_Data[1] ) == SUCCESS)
			{
				printf("\r\n��ȡDHT11_2�ɹ�!\r\n\r\nʪ��Ϊ%d.%d ��RH ���¶�Ϊ %d.%d�� \r\n",\
				DHT11_Data[1].humi_int,DHT11_Data[1].humi_deci,DHT11_Data[1].temp_int,DHT11_Data[1].temp_deci);
			}			
			else
			{
				printf("Read DHT11 ERROR!\r\n");
			}
			
		 Delay_ms(1000);
	}

	
}
/*********************************************END OF FILE**********************/
