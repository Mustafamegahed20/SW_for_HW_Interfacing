#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"
#include "7_seg.h"





int main(void)
{

	KeyPad_INIT();
	Seg_Init();
    while (1)
    {

    	KeyPad_MANAGE();
    }

  return 0;
}

