#define LCD_RS     GPIOA, GPIO_PIN_1
#define LCD_EN      GPIOA, GPIO_PIN_2
#define LCD_DB4    GPIOD, GPIO_PIN_1
#define LCD_DB5    GPIOD, GPIO_PIN_2
#define LCD_DB6    GPIOD, GPIO_PIN_3
#define LCD_DB7    GPIOD, GPIO_PIN_4
#include "stm8s.h"
#include "stm8s_i2c.h"
#include "stm8s_gpio.h"
#include "stm8s103_lcd_16x2.h" 
#include "stm8s103_i2c.h"

 

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
void GPIO_setup(void)
{   
    	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOD);
    GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_OUT_OD_HIZ_FAST);
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_OD_HIZ_FAST);
}

/*
Function: readTemperature
Description: Takes the register address and return the temperatur value.

*/

uint16_t readTemperature(uint8_t a) {
   uint16_t res;
  
  
  res = I2C_ByteRead(MLX90614_I2CADDR,a);


  return res;
}

void MLX90614_Read(void){
	
		uint16_t	temperature1;
		uint16_t	temperature2;
	
	temperature1 = readTemperature(MLX90614_TA);
	delay_ms(20);
  temperature2 = readTemperature(MLX90614_TOBJ1);


		Lcd_Set_Cursor(1,10);
		LCD_Print_Int(temperature1);

		Lcd_Set_Cursor(2,10);
		LCD_Print_Int(temperature2);
		delay_ms(2000);

}


main()
{
	/* Deinitializing the GPIOs and I2C */
	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOD);
	I2C_DeInit();
	
/* Initializing the I2C */
I2C_Setup();

	/* Initializing te LCD */
  Lcd_Begin();
	Lcd_Clear();
	Lcd_Set_Cursor(1,1);
	Lcd_Print_String("Initializing");
	Lcd_Set_Cursor(2,1);
	Lcd_Print_String("Wait...");
	delay_ms(1000);
		
		Lcd_Clear();
		Lcd_Set_Cursor(1,1);
		Lcd_Print_String("Ambient:      F");

		Lcd_Set_Cursor(2,1);
		Lcd_Print_String("Object :      F");
		delay_ms(100);
		
	while (1){
			MLX90614_Read();
			delay_ms(4000);
	}
	
	
}