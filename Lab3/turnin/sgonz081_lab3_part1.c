/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00;	PORTB = 0xFF;	//Inputs
	DDRC = 0xFF;	PORTC = 0x00;	//Outputs
    /* Insert your solution below */
	unsigned char count, mask, temp;
    while (1) {	
	int i;
	mask = 0x01;
	count = 0x00;
	for(i=0; i < 8; i++){
		temp = PINA & mask;
		if(temp == mask){
			count++;
		}
		mask = mask << 1;
	}  
	mask = 0x01;
	for(i=0; i < 8; i++){
		temp = PINB & mask;
		if(temp == mask){
			count++;
		}
		mask = mask << 1;
	}
	PORTC = count;
    }
    return 1;
}
