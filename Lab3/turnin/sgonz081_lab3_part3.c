/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #3  Exercise #3
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
	unsigned char temp, temp2, result;
    while (1) {	
	temp = PINA & 0x0F;
	temp2 = PINA & 0xF0;
	if((temp <= 15) && (temp >= 13)){
		result = 0x3F;
	}
	else if((temp <= 12) && (temp >= 10)){
		result = 0x3E;
	}
	else if((temp <= 9) && (temp >= 7)){
		result = 0x3C;
	}
	else if((temp <= 6) && (temp >= 5)){
		result = 0x38;
	}
	else if((temp <= 4) && (temp >= 3)){
		result = 0x70;
	}
	else if((temp <= 2) && (temp >= 1)){
		result = 0xC0;
	}
	else{
		result = 0x00;
	}
	if(temp2 == 0x30){
		result = result | (0x01 << 7);
	}
	PORTC = result;
    }
    return 1;
}
