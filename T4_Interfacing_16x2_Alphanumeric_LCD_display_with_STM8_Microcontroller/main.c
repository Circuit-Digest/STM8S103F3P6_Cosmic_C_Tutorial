/*Tutorial Number:4 Interfcaing 16x2 LCD with STM8s103F3
 * Website: https://circuitdigest.com/search/node/STM8S
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
main()
 
{
 
//Variable declarations
 
int test_var = 0;
char d4,d3,d2,d1;
Lcd_Begin();
Lcd_Clear();
Lcd_Set_Cursor(1,1);
Lcd_Print_String("STM8S103F3P3 LCD");
 
delay_ms(5000);
Lcd_Clear();
Lcd_Set_Cursor(1,1);
Lcd_Print_String("Circuit Digest");
Lcd_Set_Cursor(2,1);
Lcd_Print_String("Test: ");
 
while (1)
{
d4 = test_var%10 + '0';
d3 = (test_var/10)%10 + '0';
d2 = (test_var/100)%10 + '0';
d1 = (test_var/1000) + '0';
 
Lcd_Set_Cursor(2,6);
Lcd_Print_Char(d1);
Lcd_Print_Char(d2);
Lcd_Print_Char(d3);
Lcd_Print_Char(d4);
delay_ms(1000);
test_var++;
}
}
