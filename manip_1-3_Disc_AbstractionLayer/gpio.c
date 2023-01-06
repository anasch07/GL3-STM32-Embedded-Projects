#include <gpio.h>


int GPIO_TestPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
uint16_t isWorking=  GPIOx->IDR & GPIO_PIN;
	if ( isWorking ==0 )
		return 1;
	else
		return 0;

}

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	
		GPIOx->BSRR=GPIO_PIN;

}

void GPIO_ResetPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
		GPIOx->BRR=GPIO_PIN;	
}









