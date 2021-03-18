/*
 * CFile1.c
 *
 * Created: 3/29/2018 1:02:05 AM
 *  Author: Hatem Ali
 */ 
// 6 pins as output 4 data 1 enable 1 rs
//init  send command(static)(high then low 0x28 0x2 then 0x8     send data       send string (one charachter only)      lcd clear display static in the driver (function to clear) (for ex LcdClear()) this funtion uses send command function to clear
//function send four bits used in send command and send data
//use predefined delay function
//============
//initialize pins as output 6 pins
//send 4 bit function 
// init function

#include "Lcd_Driver.h"
static void vSend4Bits(uint8_t);
static void vSendCommand (uint8_t xCommand);
//static void vSendData (uint8_t xCommand);

void vInitFunc(void) //init function
{
	
//initialize all bins as output
DataPin1_Direction  |= (1U<< DataPin1);
DataPin2_Direction  |= (1U<< DataPin2);
DataPin3_Direction  |= (1U<< DataPin3);
DataPin4_Direction  |= (1U<< DataPin4);
RsPin_Direction     |= (1U<< RsPin   );
EnablePin_Direction |= (1U<<EnablePin);
RWPin_Direction     |= (1U<<RWPin);
//set RS,Enable and RW  to 0 
RsPin_Output&=~(1U<<RsPin);
EnablePin_Output &=~(1U<<EnablePin);
RWPin_Output &=~(1U<<RWPin);

_delay_ms(INIT_POWER_ON_DELAY);
//vSend4Bits(0x3);
//Delay(INIT_DELAY1);
//vSend4Bits(0x3);
//Delay(INIT_DELAY2);
vSendCommand(0x33);
vSendCommand(0x32);
vSendCommand(0x28);//4 bit mode & no. of lines is 2   page 46 data sheet
//disp off > disp clear > entry mode set > disp on
vSendCommand(0x0E); //disp clear
vSendCommand(0x01); // disp on cursor on
vSendCommand(0x06); // increment cursor 
vSendCommand(0x80);//row 1 col 1

}

static void vSend4Bits(uint8_t xData)
{
	//REG = (REG & ~(1 << pin)) | (value << pin);
	DataPin1_Output = (DataPin1_Output & ~(1U<<DataPin1))|(((xData>>MaskBit1)&(1U))<<DataPin1); // (bit low)|(bit data)
	DataPin1_Output = (DataPin1_Output & ~(1U<<DataPin2))|(((xData>>MaskBit2)&(1U))<<DataPin2);
	DataPin1_Output = (DataPin1_Output & ~(1U<<DataPin3))|(((xData>>MaskBit3)&(1U))<<DataPin3);
	DataPin1_Output = (DataPin1_Output & ~(1U<<DataPin4))|(((xData>>MaskBit4)&(1U))<<DataPin4);
}

static void vSendCommand (uint8_t xCommand)
{
	
	RsPin_Output &=~(1U<<RsPin);
	vSend4Bits((xCommand >> 4) & Mask4Bits);
	EnablePin_Output |=(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
	EnablePin_Output &=~(1U<<EnablePin);
	vSend4Bits(xCommand & Mask4Bits);
	EnablePin_Output |=(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
	EnablePin_Output &=~(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
}


 void vSendData (uint8_t xCommand)
{
	RsPin_Output |=(1U<<RsPin);
	vSend4Bits((xCommand >> 4) & Mask4Bits);
	EnablePin_Output |=(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
	EnablePin_Output &=~(1U<<EnablePin);
	vSend4Bits(xCommand & Mask4Bits);
	EnablePin_Output |=(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
	EnablePin_Output &=~(1U<<EnablePin);
	Delay(DEFAULT_DELAY);
}

void vClearDisp(void)
{
	vSendCommand(0x0E);
}

void vSendString(char string[])
{
	short counter=0;
	while(string[counter]!=0)
	{   
		vSendData(string[counter]);
		counter++;
	}
} 