/*	Author: sgonz081
 *  	Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab # 2  Exercise # 2
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
	DDRC = 0XFF;	PORTC = 0X00; //outputs
	unsigned char tempA, cntavail, mask;
	
    /* Insert your solution below */
    while (1) {
	cntavail = 0x00;
	mask = 0x01;
	int i;
	for(i = 0; i < 4; i++){
		tempA = PINA & mask;
		if(tempA == 0x00){
			cntavail++;
		}
		mask = mask << 1;	
	}	
	PORTC = cntavail;
    }
    return 1;
}
