/*
 * Lcd_Config.h
 *
 * Created: 3/29/2018 3:38:08 AM
 *  Author: Hatem Ali
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#define F_CPU 12000000UL
#include <avr/io.h>

#define DataPin1                4
#define DataPin1_Direction      DDRA
#define DataPin1_Output         PORTA

#define DataPin2                5
#define DataPin2_Direction      DDRA
#define DataPin2_Output         PORTA

#define DataPin3                6
#define DataPin3_Direction      DDRA
#define DataPin3_Output         PORTA

#define DataPin4                7
#define DataPin4_Direction      DDRA
#define DataPin4_Output         PORTA

#define RsPin                   1
#define RsPin_Direction         DDRB
#define RsPin_Output            PORTB

#define EnablePin               3
#define EnablePin_Direction     DDRB
#define EnablePin_Output        PORTB

#define RWPin                   2
#define RWPin_Direction         DDRB
#define RWPin_Output            PORTB                   



#endif /* LCD_CONFIG_H_ */