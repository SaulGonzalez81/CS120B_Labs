/*	Author: sgonz081
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
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
	DDRC = 0xFF;	PORTC = 0x00;	//Outputs
    /* Insert your solution below */
	unsigned char result;
    while (1) {	
	if((PINA <= 15) && (PINA >= 13)){
		result = 0x3F;
	}
	else if((PINA <= 12) && (PINA >= 10)){
		result = 0x3E;
	}
	else if((PINA <= 9) && (PINA >= 7)){
		result = 0x3C;
	}
	else if((PINA <= 6) && (PINA >= 5)){
		result = 0x38;
	}
	else if((PINA <= 4) && (PINA >= 3)){
		result = 0x70;
	}
	else if((PINA <= 2) && (PINA >= 1)){
		result = 0xC0;
	}
	else{
		result = 0x00;
	}
	PORTC = result;
    }
    return 1;
}
