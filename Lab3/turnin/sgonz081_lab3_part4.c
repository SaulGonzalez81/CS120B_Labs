/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #3  Exercise #4
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
	DDRA = 0x00;	PORTA = 0xFF;	//Inputs
	DDRB = 0XFF;	PORTB = 0X00;	//Outputs
	DDRC = 0xFF;	PORTC = 0x00;	//Outputs
    /* Insert your solution below */
	unsigned char upperA, lowerA;
    while (1) {
	upperA = PINA & 0xF0;
	lowerA = PINA & 0x0F;
	PORTB = upperA >> 4;
	PORTC = lowerA << 4;	
    }
    return 1;
}
