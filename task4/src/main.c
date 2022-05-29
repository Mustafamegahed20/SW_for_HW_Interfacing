#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"




int main(void)
{



	GPIO_Init(GPIOB,7,0,1);
	for(unsigned char i = 0; i < 7; i++){
			GPIO_Init(GPIOB, i , 1 , 1);}

//	GPIOB->PUPDR |=(1<<14);   //  pin 7 button set as PULL UP
//	GPIOB->PUPDR &=~(1<<15);

	static unsigned char seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	unsigned char count=0;

	while(1)
	{

		while ((GPIO_read(GPIOB,7)) != 0);    // if the button not pressed, don't proceed

		for(int i=  0; i < 80000; i++){}    //	 delay in milliseconds for debouncing

		if(!((GPIO_read(GPIOB,7)))){


			if (count>9){
			  count=0;
			  }
			for(unsigned char i = 0; i < 7; i++){
							  GPIO_Write(GPIOB, i, (seg[count] >> i) & 0x01);
			}
			count++;

			while ((GPIO_read(GPIOB,7)) == 0);// if the button still pressed, don't proceed

		}
	}
}

