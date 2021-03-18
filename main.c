/*
 * LCD_driver.c
 *
 * Created: 3/28/2018 4:48:06 PM
 * Author : Hatem Ali
 */ 

#include "Lcd_Driver.h"

int main(void)
{
    /* Replace with your application code */
	char name[]="HATEM";
	vInitFunc();
	vSendString(name);
	
	
}

