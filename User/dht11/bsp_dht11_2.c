#include "./dht11/bsp_dht11_2.h"

void DHT11_2_GPIO_Config(void)
{
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure; 

	
	/*����DHT11_Dout_GPIO_PORT������ʱ��*/
    DHT11_2_Dout_SCK_APBxClock_FUN ( DHT11_2_Dout_GPIO_CLK, ENABLE );	
 
	/*ѡ��Ҫ���Ƶ�DHT11_Dout_GPIO_PORT����*/															   
  	GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��DHT11_2_Dout_GPIO_PORT*/
  	GPIO_Init ( DHT11_2_Dout_GPIO_PORT, &GPIO_InitStructure );		  

}

/*
 * ��������DHT11_2_Mode_Out_PP
 * ����  ��ʹDHT11-DATA���ű�Ϊ�������ģʽ
 * ����  ����
 * ���  ����
 */
void DHT11_2_Mode_Out_PP(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;

	 	/*ѡ��Ҫ���Ƶ�DHT11_2_Dout_GPIO_PORT����*/															   
  	GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/*���ÿ⺯������ʼ��DHT11_2_Dout_GPIO_PORT*/
  	GPIO_Init(DHT11_2_Dout_GPIO_PORT, &GPIO_InitStructure);	 	 
	
}

/*
 * ��������DHT11_2_Mode_IPU
 * ����  ��ʹDHT11-DATA���ű�Ϊ��������ģʽ
 * ����  ����
 * ���  ����
 */
void DHT11_2_Mode_IPU(void)
{
 	  GPIO_InitTypeDef GPIO_InitStructure;

	  	/*ѡ��Ҫ���Ƶ�DHT11_2_Dout_GPIO_PORT����*/	
	  GPIO_InitStructure.GPIO_Pin = DHT11_2_Dout_GPIO_PIN;

	   /*��������ģʽΪ��������ģʽ*/ 
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ; 

	  /*���ÿ⺯������ʼ��DHT11_2_Dout_GPIO_PORT*/
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
