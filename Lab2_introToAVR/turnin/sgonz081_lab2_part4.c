/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab # 2  Exercise # 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0X00;	PORTA = 0XFF; //inputs
	DDRB = 0X00;	PORTB = 0XFF; //inputs
	DDRC = 0X00;	PORTC = 0XFF; //inputs
	DDRD = 0XFF;	PORTD = 0X00; //outputs
	unsigned char totalWeight;
	
    /* Insert your solution below */
    while (1) {
	totalWeight = PINA + PINB + PINC;
	PORTD = totalWeight;
	if(totalWeight > 140){
		PORTD = PORTD | (0x01 << 0);
	}
	else{
		PORTD = PORTD & ~(0x01 << 0);
	}
	if((PINA - PINC) > 80){
		PORTD = PORTD | (0x01 << 1);
	}
	else{
		PORTD = PORTD & ~(0x01 << 1);
	}	
    }
    return 1;
}
