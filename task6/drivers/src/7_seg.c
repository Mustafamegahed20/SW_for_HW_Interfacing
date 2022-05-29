/*
 * 7_seg.c
 *
 *  Created on: May 16, 2022
 *      Author: soudy
 */
#include "stm32f4xx.h"
#include "gpio.h"
#include "7_seg.h"

void Seg_Write(unsigned char index){


	unsigned char seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
				                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	for (unsigned char i = 0; i < 7; i++)
	{
		  GPIO_Write(GPIOA, i, (seg[index] >> i) & 0x01);
	}

}


void Seg_Init(void){
	for(unsigned char i = 0; i < 7; i++)
		{
			GPIO_Init(GPIOA, i , 1 , 0);
	    }
}
