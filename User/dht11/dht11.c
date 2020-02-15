
#include "./dht11/dht11.h"
#include "./systick/bsp_SysTick.h"
#include "./dht11/bsp_dht11_1.h"

/* 
 * ��DHT11��ȡһ���ֽڣ�MSB����
 */
static uint8_t DHT11_ReadByte (DHT11_Data_TypeDef * DHT11_Data )
{
	uint8_t i, temp=0;
	

	for(i=0;i<8;i++)    
	{	 
		/*ÿbit��50us�͵�ƽ���ÿ�ʼ����ѯֱ���ӻ����� ��50us �͵�ƽ ����*/  
		while(DHT11_Data->_DHT11_Dout_IN_()==Bit_RESET);

		/*DHT11 ��26~28us�ĸߵ�ƽ��ʾ��0������70us�ߵ�ƽ��ʾ��1����
		 *ͨ����� x us��ĵ�ƽ��������������״ ��x ���������ʱ 
		 */
		Delay_us(40); //��ʱx us �����ʱ��Ҫ��������0������ʱ�伴��	   	  

		if(DHT11_Data->_DHT11_Dout_IN_()==Bit_SET)/* x us����Ϊ�ߵ�ƽ��ʾ���ݡ�1�� */
		{
			/* �ȴ�����1�ĸߵ�ƽ���� */
			while(DHT11_Data->_DHT11_Dout_IN_()==Bit_SET);

			temp|=(uint8_t)(0x01<<(7-i));  //�ѵ�7-iλ��1��MSB���� 
		}
		else	 // x us��Ϊ�͵�ƽ��ʾ���ݡ�0��
		{			   
			temp&=(uint8_t)~(0x01<<(7-i)); //�ѵ�7-iλ��0��MSB����
		}
	}
	
	return temp;
	
}

/*
 * һ�����������ݴ���Ϊ40bit����λ�ȳ�
 * 8bit ʪ������ + 8bit ʪ��С�� + 8bit �¶����� + 8bit �¶�С�� + 8bit У��� 
 */
uint8_t DHT11_Read_TempAndHumidity(DHT11_Data_TypeDef *DHT11_Data)
{  
	/*���ģʽ*/
    DHT11_Data->_DHT11_Mode_Out_PP_();
	/*��������*/
	//DHT11_Dout_0;
    DHT11_Data->_DHT11_Dout_0_();
	/*��ʱ18ms*/
	Delay_ms(18);

	/*�������� ������ʱ30us*/
	//DHT11_Dout_1;
    DHT11_Data->_DHT11_Dout_1_();

	Delay_us(30);   //��ʱ30us

	/*������Ϊ���� �жϴӻ���Ӧ�ź�*/ 
    DHT11_Data->_DHT11_Mode_IPU_();

	/*�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������*/   
	if(DHT11_Data->_DHT11_Dout_IN_()==Bit_RESET)     
	{
		/*��ѯֱ���ӻ����� ��80us �͵�ƽ ��Ӧ�źŽ���*/  
		while(DHT11_Data->_DHT11_Dout_IN_()==Bit_RESET);

		/*��ѯֱ���ӻ������� 80us �ߵ�ƽ �����źŽ���*/
		while(DHT11_Data->_DHT11_Dout_IN_()==Bit_SET);

		/*��ʼ��������*/   
		DHT11_Data->humi_int= DHT11_ReadByte(DHT11_Data);

		DHT11_Data->humi_deci= DHT11_ReadByte(DHT11_Data);

		DHT11_Data->temp_int= DHT11_ReadByte(DHT11_Data);

		DHT11_Data->temp_deci= DHT11_ReadByte(DHT11_Data);

		DHT11_Data->check_sum= DHT11_ReadByte(DHT11_Data);


		/*��ȡ���������Ÿ�Ϊ���ģʽ*/
        DHT11_Data->_DHT11_Mode_Out_PP_();
		/*��������*/
		//DHT11_Dout_1;
        DHT11_Data->_DHT11_Dout_1_();

		/*����ȡ�������Ƿ���ȷ*/
		if(DHT11_Data->check_sum == DHT11_Data->humi_int + DHT11_Data->humi_deci + DHT11_Data->temp_int+ DHT11_Data->temp_deci)
			return SUCCESS;
		else 
			return ERROR;
	}
	
	else
		return ERROR;
	
}

 /**
  * @brief  DHT11 ��ʼ������
  * @param  ��
  * @retval ��
  */
void DHT11_Init (DHT11_Data_TypeDef * DHT11_Data)
{
    DHT11_Data->_DHT11_GPIO_Config_ = DHT11_1_GPIO_Config;
	DHT11_Data->_DHT11_GPIO_SetBits_ = DHT11_1_GPIO_SetBits;	
    DHT11_Data->_DHT11_Mode_Out_PP_ = DHT11_1_Mode_Out_PP;
    DHT11_Data->_DHT11_Mode_IPU_ = DHT11_1_Mode_IPU;
    DHT11_Data->_DHT11_Dout_0_ = DHT11_1_Dout_0;
    DHT11_Data->_DHT11_Dout_1_ = DHT11_1_Dout_1;
    DHT11_Data->_DHT11_Dout_IN_ = DHT11_1_Dout_IN;
    
    DHT11_Data->_DHT11_GPIO_Config_();
    DHT11_Data->_DHT11_GPIO_SetBits_();
}
	  


/*************************************END OF FILE******************************/
