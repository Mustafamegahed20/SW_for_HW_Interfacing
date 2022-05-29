/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
//#include "gpio.h"
#include "7_seg.h"
#include "stm32f4xx.h"
void ISR_OF_EXTI0(void);
//void (*ptrToFunction)(void)= 0x00000058;

signed char counter=0;
			

int main(void)
{

	// set pins from 0 to 6 as a output and enable port A

	Seg_Init();


	// set pins 7 & 8 as a input

	for(unsigned char j = 0; j <2; j++){
		GPIO_Init(GPIOB, j, 0, 1);    //input
	}

//	GPIOB->PUPDR |=(1<<0);   //  pin 0 button set as PULL UP
//
//	GPIOB->PUPDR |=(1<<1);   //  pin 1 button set as PULL UP


	// Enable clock access to sysconf
	RCC->APB2ENR|=(1u<<14);

	// Set Selection lines of EXTI0
	SYSCFG->EXTICR[0] |=(1u<<0);
	// Set Selection lines of EXTI1
	SYSCFG->EXTICR[0] |=(1u<<4);

	// Configure the mask bit of exti0
	EXTI->IMR |=(1u<<0);
	EXTI->IMR |=(1u<<1);

	// Configure the Trigger  as falling trigger
	EXTI->FTSR |=(1u<<0);
	EXTI->FTSR |=(1u<<1);

	// enable EXTI0 interrupt from NVIC
	NVIC->ISER[0]|=(1u<<6);
	NVIC->ISER[0]|=(1u<<7);

	//NVIC->ICER[0]|=(1u<<6);

	while(1)
	{

		  if(counter > 9||counter<0){
				  counter = 0;
			  }
		  Seg_Write(counter);
	}

}
void ISR_OF_EXTI0(void)
{
	counter++;
}


void ISR_OF_EXTI1(void)
{
	counter--;
}

void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0();
}

void EXTI1_IRQHandler(void){
	ISR_OF_EXTI1();
}




