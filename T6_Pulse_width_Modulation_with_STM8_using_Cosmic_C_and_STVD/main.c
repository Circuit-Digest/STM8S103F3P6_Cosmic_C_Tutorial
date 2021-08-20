#include "STM8S.h"
signed int pwm_duty = 0;
void delay_ms (int ms) //Function Definition 
{
for (int i=0; i<=ms; i++)
for (int j=0; j<120; j++) // Nop = Fosc/4
_asm("nop"); //Perform no operation //assembly code 
}
void main(void)
{
  GPIO_DeInit(GPIOD);
TIM2_DeInit();
GPIO_Init(GPIOD,GPIO_PIN_4,GPIO_MODE_OUT_PP_HIGH_FAST);
TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 1000, 
                   TIM2_OCPOLARITY_HIGH);
TIM2_TimeBaseInit(TIM2_PRESCALER_1, 500);
TIM2_Cmd(ENABLE);          
  while(TRUE){
    for(pwm_duty = 0; pwm_duty < 1000; pwm_duty += 2){ // loop through 
      TIM2_SetCompare1(pwm_duty); //set capture compair for Timer2
      delay_ms(10); //delay for 10ms
}
    for(pwm_duty = 1000; pwm_duty > 0; pwm_duty -= 2){
      TIM2_SetCompare1(pwm_duty);
      delay_ms(10);
    }
  }
}