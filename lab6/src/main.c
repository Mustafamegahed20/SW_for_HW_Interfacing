/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f4xx_it.h"
#include "stm32f4xx.h"
void ISR_OF_EXTI0(void);
//void (*ptrToFunction)(void)= 0x00000058;

			

int main(void)
{


	// Enable clock Access to GPIOA,GPIOB

	RCC->AHB1ENR|=(1u<<0);
	RCC->AHB1ENR|=(1u<<1);

	//Set pin 0 port B as input
	GPIOB->MODER &=~(1u<<0);
	GPIOB->MODER &=~(1u<<1);

	////Set pin 0 port B into pull up mode
	GPIOB->PUPDR |=(1u<<0);

	// set pin 1 port A as output
	GPIOA->MODER |=(1u<<2);

	// Enable clock access to sysconf
	RCC->APB2ENR|=(1u<<14);

	// Set Selection lines of EXTI0
	SYSCFG->EXTICR[0] |=(1u<<0);
	SYSCFG->EXTICR[0] &=~(1u<<1);
	SYSCFG->EXTICR[0] &=~(1u<<2);
	SYSCFG->EXTICR[0] &=~(1u<<3);

	// Configure the mask bit of exti0
	EXTI->IMR |=(1u<<0);
	// Configure the Trigger  as falling trigger
	EXTI->FTSR |=(1u<<0);

	// enable EXTI0 interrupt from NVIC
	NVIC->ISER[0]|=(1u<<6);
	//NVIC->ICER[0]|=(1u<<6);

	while(1)
	{

	}


}



void ISR_OF_EXTI0(void)
{
	GPIOA->ODR ^= (1u<<1);
}
void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0();
}
