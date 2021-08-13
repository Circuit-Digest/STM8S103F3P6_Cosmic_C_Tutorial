/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
 
 #define Green_LED GPIOA, GPIO_PIN_3
 #include "STM8S.h"
 
void delay (int ms) //Function Definition 
{
int i =0 ;
int j=0;
for (i=0; i<=ms; i++)
{
for (j=0; j<120; j++) // Nop = Fosc/4
_asm("nop"); //Perform no operation //assembly code 
}
}
 
main()
{
GPIO_DeInit(GPIOA); //prepare Port A for working 
GPIO_DeInit(GPIOB); // prepare Port B for working 
 
//Declare PA2  as input pull up pin
GPIO_Init (GPIOA, GPIO_PIN_2, GPIO_MODE_IN_PU_IT); 
 
//Declare PA3 as Push Pull Output pin
GPIO_Init (Green_LED, GPIO_MODE_OUT_PP_LOW_SLOW);
 
//Declare PB5 as push pull Output pin
GPIO_Init (GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
 
while (1)
{
if (GPIO_ReadInputPin(GPIOA, GPIO_PIN_2)) //if button pressed
GPIO_WriteLow(Green_LED); //LED ON
else
GPIO_WriteHigh(Green_LED); //LED OFF
GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
delay (100);
}
}
