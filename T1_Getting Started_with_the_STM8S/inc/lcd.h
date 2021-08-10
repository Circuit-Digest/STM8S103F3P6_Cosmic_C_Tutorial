#include "stm8s.h"
#include "PCF8574.h"
#define clear_display                                        0x01
#define goto_home                                            0x02
#define cursor_direction_inc                         (0x04 | 0x02)
#define cursor_direction_dec                         (0x04 | 0x00)
#define display_shift                                (0x04 | 0x01)
#define display_no_shift                             (0x04 | 0x00)
#define display_on                                   (0x08 | 0x04)
#define display_off                                  (0x08 | 0x02)
#define cursor_on                                    (0x08 | 0x02)
#define cursor_off                                   (0x08 | 0x00)
#define blink_on                                     (0x08 | 0x01)
#define blink_off                                    (0x08 | 0x00)
#define _8_pin_interface                             (0x20 | 0x10)
#define _4_pin_interface                             (0x20 | 0x00)
#define _2_row_display                               (0x20 | 0x08)
#define _1_row_display                               (0x20 | 0x00)
#define _5x10_dots                                   (0x20 | 0x40)
#define _5x7_dots                                    (0x20 | 0x00)
#define BL_ON                                                    1
#define BL_OFF                                                  0
#define dly                                                     2
#define DAT                                                       1
#define CMD                                                       0
extern unsigned char bl_state;
extern unsigned char data_value;
void LCD_init(void);
void LCD_toggle_EN(void);
void LCD_send(unsigned char value, unsigned char mode);
void LCD_4bit_send(unsigned char lcd_data);           
void LCD_putstr(char *lcd_string);
void LCD_putchar(char char_data);
void LCD_clear_home(void);
void LCD_goto(unsigned char x_pos, unsigned char y_pos);

void delay_ms (int ms) //Function Definition 
{
int i =0 ;
int j=0;
for (i=0; i<=ms; i++)
{
for (j=0; j<120; j++) // Nop = Fosc/4
_asm("nop"); //Perform no operation //assembly code 
}
}

void LCD_init(void)
{                      
    PCF8574_init();
    delay_ms(100);
    bl_state = BL_ON;
    data_value = 0x04;
    PCF8574_write(data_value);
    delay_ms(10);
    LCD_send(0x33, CMD);
    LCD_send(0x32, CMD);
    LCD_send((_4_pin_interface | _2_row_display | _5x7_dots), CMD);        
    LCD_send((display_on | cursor_off | blink_off), CMD);    
    LCD_send((clear_display), CMD);        
    LCD_send((cursor_direction_inc | display_no_shift), CMD);       
}  
void LCD_toggle_EN(void)
{
    data_value |= 0x04;
    PCF8574_write(data_value);
    delay_ms(dly);
    data_value &= 0xF9;
    PCF8574_write(data_value);
    delay_ms(dly);
}
void LCD_send(unsigned char value, unsigned char mode)
{
    switch(mode)
    {
       case CMD:
       {
            data_value &= 0xF4;
            break;
       }
       case DAT:
       {
           data_value |= 0x01;
           break;
       }
    }
    switch(bl_state)
    {
       case BL_ON:
       {
          data_value |= 0x08;
          break;
       }
       case BL_OFF:
       {
          data_value &= 0xF7;
          break;
       }
    }
    PCF8574_write(data_value);
    LCD_4bit_send(value);
    delay_ms(dly);
}
void LCD_4bit_send(unsigned char lcd_data)      
{
    unsigned char temp = 0x00;
    temp = (lcd_data & 0xF0);
    data_value &= 0x0F;
    data_value |= temp;
    PCF8574_write(data_value);
    LCD_toggle_EN();
    temp = (lcd_data & 0x0F);
    temp <<= 0x04;
    data_value &= 0x0F;
    data_value |= temp;
    PCF8574_write(data_value);
    LCD_toggle_EN();
} 
void LCD_putstr(char *lcd_string)
{
    do
    {
        LCD_putchar(*lcd_string++);
    }while(*lcd_string != '\0') ;
}
void LCD_putchar(char char_data)
{
    if((char_data >= 0x20) && (char_data <= 0x7F))
    {
       LCD_send(char_data, DAT);
    }
}
void LCD_clear_home(void)
{
    LCD_send(clear_display, CMD);
    LCD_send(goto_home, CMD);
}
void LCD_goto(unsigned char x_pos,unsigned char y_pos)
{                                                   
    if(y_pos == 0)   
    {                             
        LCD_send((0x80 | x_pos), CMD);
    }
    else
    {                                             
        LCD_send((0x80 | 0x40 | x_pos), CMD);
    }
}