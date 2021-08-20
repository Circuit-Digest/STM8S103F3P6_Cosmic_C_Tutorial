/* Tutorial Number 5 - ADC on STM8S
 * website: https://circuitdigest.com/search/node/STM8S
 * Code by: Aswinth Raj
 */
 /*LCD --> STM8s
 * LCD_RS --> PA1
 * LCD_EN --> PA2
 * LCD_DB4 --> PD1
 * LCD_DB5 --> PD2
 * LCD_DB6 --> PD3
 * LCD_DB7 --> PD4
 */
 #define LCD_RS     GPIOA, GPIO_PIN_1
 #define LCD_EN     GPIOA, GPIO_PIN_2
 #define LCD_DB4    GPIOD, GPIO_PIN_1
 #define LCD_DB5    GPIOD, GPIO_PIN_2
 #define LCD_DB6    GPIOD, GPIO_PIN_3
 #define LCD_DB7    GPIOD, GPIO_PIN_4
 #include "STM8S.h"
 #include "stm8s103_LCD_16x2.h"
 #include "stm8s103_ADC.h"
void LCD_Print_Var (int var)
{
char d4,d3,d2,d1;
d4 = var%10 + '0';
d3 = (var/10)%10 + '0';
d2 = (var/100)%10 + '0';
d1 = (var/1000) + '0';
Lcd_Print_Char(d1);
Lcd_Print_Char(d2);
Lcd_Print_Char(d3);
Lcd_Print_Char(d4);
}
void main()
{
//Variable declarations
unsigned int ADC_value_1 = 0;
unsigned int ADC_value_2 = 0;
int ADC_voltage_1 = 0;
int ADC_voltage_2 = 0;
Lcd_Begin();
Lcd_Clear();
Lcd_Set_Cursor(1,1);
Lcd_Print_String("ADC on STM8S");
CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE); //Enable Peripheral Clock for ADC
GPIO_Init (GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_IT);
delay_ms(5000);
Lcd_Clear();
Lcd_Set_Cursor(1,1);
Lcd_Print_String("D1:    ->     mV");
Lcd_Set_Cursor(2,1);
Lcd_Print_String("D2:    ->     mV");
while (1)
{
ADC_value_1 = ADC_Read (AIN2);
ADC_value_2 = ADC_Read (AIN6);
ADC_voltage_1 = ADC_value_1 * (3.226); //(3300/1023 =~ 3.226)convert ADC value 1 to 0 to 3300mV
ADC_voltage_2 = ADC_value_2 * (3.226);  //convert ADC value 1 to 0 to 3300mV
Lcd_Set_Cursor(1,4);
LCD_Print_Var (ADC_value_1);
Lcd_Set_Cursor(1,11);
LCD_Print_Var (ADC_voltage_1);
Lcd_Set_Cursor(2,4);
LCD_Print_Var (ADC_value_2);
Lcd_Set_Cursor(2,11);
LCD_Print_Var (ADC_voltage_2);
delay_ms(500);
}
}
