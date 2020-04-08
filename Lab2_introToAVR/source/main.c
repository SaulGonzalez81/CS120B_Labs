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

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
   return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
              //   Set bit to 1           Set bit to 0
}
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
	PORTD = totalWeight << 2;
	if(totalWeight > 140){
		SetBit(PORTD,0,1);
	}
	else{
		SetBit(PORTD,0,0);
	}
	if((PORTA - PORTC) > 80){
		SetBit(PORTD,1,1);
	}
	else{
		SetBit(PORTD,1,0);
	}	
    }
    return 1;
}
