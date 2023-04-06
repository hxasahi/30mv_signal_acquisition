
// ADC 6ͨ���ɼ�ʵ��

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"

// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[NOFCHANEL];        

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{		
	// ���ô���
	USART_Config();
	
	// ADC ��ʼ��
	ADCx_Init();
	
	printf("\r\n ----����һ��ADC��ͨ���ɼ�ʵ��----\r\n");
	
	while (1)
	{	
    
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;

			printf("\r\n CH0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
			printf("\r\n CH1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
		
			printf("\r\n\r\n");
			Delay(0xffffee);		 
	}
}
/*********************************************END OF FILE**********************/

