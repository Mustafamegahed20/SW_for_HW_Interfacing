
#include<stdint.h>

#define GPIOB_BASE (uint32_t) 0x40020400
#define MODER_OFFSET (uint32_t)0x00
#define MODER_ADD (*((uint32_t*)(GPIOB_BASE+MODER_OFFSET)))

#define PUPDR_OFFSET (uint32_t)0x0C
#define PUPDR_ADD (*((uint32_t*)(GPIOB_BASE+PUPDR_OFFSET)))

#define IDR_OFFSET (uint32_t)0x10
#define IDR_ADD (*((uint32_t*)(GPIOB_BASE+IDR_OFFSET)))

#define OUTPUTTYPE_OFFSET (uint32_t)0x04
#define OUTPUTTYPE_ADD (*((uint32_t*)(GPIOB_BASE+OUTPUTTYPE_OFFSET)))

#define OUTDATA_OFFSET (uint32_t)0x14
#define OUTDATA_ADD (*((uint32_t*)(GPIOB_BASE+OUTDATA_OFFSET)))

#define RCC_BASE (uint32_t)0x40023800
#define AHB1ENR_OFFSET (uint32_t)0x30
#define AHB1ENR_ADD (*((uint32_t*)(RCC_BASE+AHB1ENR_OFFSET)))

int main(void)
{

	AHB1ENR_ADD |=(1<<1); // Enable GPIOB

	MODER_ADD &=~(1<<6);  // pin 3 is input mode
	MODER_ADD &=~(1<<7);

	MODER_ADD |=(1<<10);  // pin 5 is output mode
	MODER_ADD &=~(1<<11);

	MODER_ADD |=(1<<12);   // pin 6 is output mode
	MODER_ADD &=~(1<<13);

	MODER_ADD |=(1<<14);   // pin 7 is output mode
	MODER_ADD &=~(1<<15);

	PUPDR_ADD |=(1<<6);   //  pin 3 button set as PULL UP
	PUPDR_ADD &=~(1<<7);

	OUTPUTTYPE_ADD &=~(1<<5);  // bin 5,6and 7 are push pull
	OUTPUTTYPE_ADD &=~(1<<6);
	OUTPUTTYPE_ADD &=~(1<<7);

	unsigned char count=0;

	while(1)
	{
		 while ((IDR_ADD & (1 << 3)) != 0);    // if the button not pressed, don't proceed

		for(int i=  0; i < 80000; i++){}    //	 delay in milliseconds for debouncing

		if(!(IDR_ADD&(1<<3))){

			OUTDATA_ADD=(count<<5);
			count++;

			while ((IDR_ADD & (1 << 3)) == 0); // if the button still pressed, don't proceed

		}



	}

}
