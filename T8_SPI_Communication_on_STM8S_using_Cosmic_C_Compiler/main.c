#include "STM8S.h"
#include "stm8s103_SPI.h"
#include "stm8s_max72xx.h"

void clock_setup(void);
void GPIO_setup(void);

 
void main()
{

const char input_string2[] = "CIRCUITDIGEST";
                
    clock_setup();
    GPIO_setup();
		SPI_init();
    MAX7219_init();
		display_clear(); //Clearing the display
		delay_ms(1000);
		display_char(char_C); // Displaying A character
    while(TRUE)
    {	

		/*
		display_clear(); //Clearing the Display
		display_string(input_string2);  //Displaying a String
		delay_ms(1000); 
		*/
    };
}
 
 
void clock_setup(void)
{
     CLK_DeInit();
                
 
     CLK_HSICmd(ENABLE);
     while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY) == FALSE);
     CLK_ClockSwitchCmd(ENABLE);
     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
     CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);                
     CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, 
     DISABLE, CLK_CURRENTCLOCKSTATE_ENABLE);
                
     CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, ENABLE);
 
}
 
 
void GPIO_setup(void)
{
     GPIO_DeInit(GPIOC);
     GPIO_Init(GPIOC, ((GPIO_Pin_TypeDef)GPIO_PIN_5 | GPIO_PIN_6), 
               GPIO_MODE_OUT_PP_HIGH_FAST);
}
 
 
