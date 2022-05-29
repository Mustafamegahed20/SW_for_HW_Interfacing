/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include<stdint.h>

#define GPIOA_BASE (uint32_t)0x40020000
#define MODER_OFFSET (uint32_t) 0x00
#define MODER_ADD (*((uint32_t*)(GPIOA_BASE+MODER_OFFSET)))
#define OUTPUTTYPE_OFFSET(uint32_t) 0x04
#define OUTPUTTYPE_ADD (*((uint32_t*) (GPIOA_BASE+OUTPUTTYPE_OFFSET)))
#define OUTDATA_OFFSET (uint32_t) 0x14
#define OUTDATA_ADD (*((uint32_t*) (GPIOA_BASE+OUTDATA_OFFSET)))
#define RCC_BASE (uint32_t) 0x40023800
#define AHB1ENR_OFFSET (uint32_t) 0x30
#define AHB1ENR_ADD (*((uint32_t*) (RCC_BASE+AHB1ENR_OFFSET)))

int main(void)
{	AHB1ENR_ADD |=(1<<0);
	MODER_ADD |=(1<<8);
	MODER_ADD &=~(1<<9);
	OUTDATA_ADD |=(1<<4);
	while(1)
	{
		OUTDATA_ADD |=(1<<4);
		for(int i=0;i<5000000;i++){}
		OUTDATA_ADD &=~(1<<4);
		for(int i=0;i<5000000;i++){}


	}

}
