/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab # 2  Exercise # 1
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
	DDRB = 0XFF;	PORTB = 0X00; //outputs

	unsigned char tempA, tempB;
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0X03;
	tempB = 0x00;
	if(tempA == 0x01){
		tempB = 0x01;
	}
	PORTB = tempB;
    }
    return 1;
}
