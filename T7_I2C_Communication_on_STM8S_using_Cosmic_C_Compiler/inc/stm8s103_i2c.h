#ifndef __I2C_ACC_H
#define __I2C_ACC_H

#include "stm8s.h"


#define I2C_Speed  100000


#define MLX90614_I2CADDR 0xB5 //for write B4 For read B5 (We are performing only read operation

// RAM ADRESSES MLX90614
#define MLX90614_RAWIR1 0x04
#define MLX90614_RAWIR2 0x05
#define MLX90614_TA 0x06
#define MLX90614_TOBJ1 0x07
#define MLX90614_TOBJ2 0x08

#endif /* __I2C_EE_H */

/*****************************
* Function Name: I2C_ACC_Init
* Description:
******************************/


	
void I2C_Setup(void)
{
	u8 Input_Clock = 0;//CPU clock

   Input_Clock = CLK_GetClockFreq()/1000000;


  I2C_Init(I2C_Speed, MLX90614_I2CADDR, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, Input_Clock);//I2C initialization
   
}

/*****************************
* Function Name: I2C_ByteWrite
******************************/

void I2C_ByteWrite(u8 I2C_Slave_Address, u8 iData)
{
	I2C_GenerateSTART(ENABLE);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C_Slave_Address, I2C_DIRECTION_TX);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	I2C_SendData(iData);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	
	I2C_GenerateSTOP(ENABLE);

}



/*****************************
* Function Name: I2C_ByteRead
* Description:
******************************/

u8 I2C_ByteRead(uint8_t I2C_Slave_Address, uint8_t ReadAddr)
{
	u16 pBuffer;
	while(I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
	
	I2C_GenerateSTART(ENABLE);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	
	
	I2C_Send7bitAddress(I2C_Slave_Address, I2C_DIRECTION_TX);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	
	I2C_SendData((u8)(ReadAddr));
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	I2C_GenerateSTART(ENABLE);

	while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
	
	I2C_Send7bitAddress(I2C_Slave_Address, I2C_DIRECTION_RX);
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	
	while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_RECEIVED));
	
	pBuffer = I2C_ReceiveData();
	
	I2C_AcknowledgeConfig(I2C_ACK_NONE);
	
	I2C_GenerateSTOP(ENABLE);
	
	return pBuffer;
}



