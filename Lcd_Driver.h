/*
 * Lcd_Driver.h
 *
 * Created: 3/29/2018 1:03:28 AM
 *  Author: Hatem Ali
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define Mask4Bits               0x0F
#define MaskBit1                0
#define MaskBit2                1  
#define MaskBit3                2   
#define MaskBit4                3  
#define INIT_POWER_ON_DELAY     15   //ms
#define INIT_DELAY1             10   //ms
#define INIT_DELAY2             200  //us
#define DEFAULT_DELAY           80   //us
#define Delay(n) switch(n){case INIT_DELAY1 :_delay_ms(INIT_DELAY1);break;case INIT_DELAY2:_delay_ms(INIT_DELAY2);break;\
	                                              case DEFAULT_DELAY:_delay_ms(DEFAULT_DELAY);break;   }
#include <stdint.h>
#include "Lcd_Config.h"
#include <util/delay.h>

void vInitFunc(void);
void vClearDisp(void);
 void vSendData (uint8_t xCommand);
void vSendString(char string[]);

#endif /* LCD_DRIVER_H_ */