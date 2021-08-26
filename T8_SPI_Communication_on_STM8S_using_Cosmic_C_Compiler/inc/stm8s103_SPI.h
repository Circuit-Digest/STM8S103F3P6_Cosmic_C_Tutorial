/*
Header Name: stm8s103_SPI.h
*/


#include "STM8S.h"

#define ChipSelect_pin  GPIO_PIN_4
#define ChipSelect_port GPIOC



/*
Function Name: delay_ms
Description: It can be used to provide delay in Micro Seconds.
type: void.
*/

void delay_ms(int ms) //Function Definition 
{
int i =0 ;
int j=0;
for (i=0; i<=ms; i++)
{
for (j=0; j<120; j++) // Nop = Fosc/4
_asm("nop"); //Perform no operation 
}
}

/*
Function Name: SPI_setup
Description: It can be used to Initiate the SPI communication.
type: void.
*/

void SPI_setup(void)
{
     SPI_DeInit();
     SPI_Init(SPI_FIRSTBIT_MSB, 
              SPI_BAUDRATEPRESCALER_2, 
              SPI_MODE_MASTER, 
              SPI_CLOCKPOLARITY_HIGH, 
              SPI_CLOCKPHASE_1EDGE, 
              SPI_DATADIRECTION_1LINE_TX, 
              SPI_NSS_SOFT, 
              0x00);
     SPI_Cmd(ENABLE);
}



 

/*
Function Name: SPI_write
Description: It can be used to write on the specific slave register.
type: void.
*/

void SPI_write(unsigned char slave_address, unsigned char value)
{
    while(SPI_GetFlagStatus(SPI_FLAG_BSY));
    GPIO_WriteLow(ChipSelect_port, ChipSelect_pin);
                
    SPI_SendData(slave_address);
    while(!SPI_GetFlagStatus(SPI_FLAG_TXE));
                
    SPI_SendData(value);
    while(!SPI_GetFlagStatus(SPI_FLAG_TXE));
                
    GPIO_WriteHigh(ChipSelect_port, ChipSelect_pin);
}



