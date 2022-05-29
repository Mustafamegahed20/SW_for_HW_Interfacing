#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"
#include "7_seg.h"

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};// fill the array


char currentvalue;

void KeyPad_INIT(void)
{
	// set input and ouput pins
		// get pins from raw and set it as input
		// get pins from cols and set it as output
	// hint use gpio driver functions
	for(unsigned char i = 0; i < 3; i++){
		GPIO_Init(GPIOA, i, 1, 0);    //output
	}

	for(unsigned char j = 3; j < 7; j++){
	    GPIO_Init(GPIOA, j, 0, 0); //input
	}

}

void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
		for (int j = 0; j < 3; j++)
				{
					GPIO_Write(GPIOA, j,0);
					for (int i = 0; i < 4; i++)
					{
						  if(GPIO_read(GPIOA, i+3)==0)
						  {

						       for(int k=0;k<30000;k++);  // check for valid button press only (debouncing)

						       if(GPIO_read(GPIOA, i+3)==0)
								   {
									  currentvalue = lookupTable[i][j];
									  while ((GPIO_read(GPIOA,i+3)) == 0);  // if the button still pressed, don't proceed
									  KeypadCallouts_KeyPressNotificaton();

								   }

						  }
					}
					GPIO_Write(GPIOA, j,1);
				}
}
unsigned char KeyPad_GET_VALUE(void)
{
		return currentvalue;

}

void KeypadCallouts_KeyPressNotificaton(void)
{

	unsigned char key_value;
	key_value=KeyPad_GET_VALUE();
	Seg_Write(key_value);


}

