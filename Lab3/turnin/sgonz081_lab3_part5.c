/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #3  Exercise #5
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
	DDRD = 0x00;	PORTD = 0xFF;	//Inputs
	DDRB = 0xFE;	PORTB = 0x01;	//Ouputs & Input for B0
    /* Insert your solution below */
	unsigned char totalWeight, /*tempB*/ result;
    while (1) {
	totalWeight = (PIND << 1) | (PINB & 0x01);
	if( totalWeight >= 70 ){
		result = 0x02;
	}
	else if( totalWeight > 5 && totalWeight < 70){
		result = 0x04;
	}
	else{
		result = 0x00;
	}
	PORTB = result; 	
    }
    return 1;
}
