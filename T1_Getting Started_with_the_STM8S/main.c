/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#define LED_1 GPIOA, GPIO_PIN_3
#define INBUILTLED GPIOB, GPIO_PIN_5


#include "stm8s.h"

void delay(int ms){
	int i = 0; int j = 0;
	for(i=0; i<=ms; i++){
		for(j=0; j<120;j++){
			_asm("nop");
		}
	}
}

main()
{
	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_Init(LED_1, GPIO_MODE_OUT_PP_HIGH_SLOW);
GPIO_Init(INBUILTLED, GPIO_MODE_OUT_PP_HIGH_SLOW);
while (1){
GPIO_WriteHigh(LED_1);
delay(100);
GPIO_WriteLow(LED_1);
GPIO_WriteHigh(INBUILTLED);
delay(100);
GPIO_WriteLow(INBUILTLED);
}
}