/*	Author: sgonz081
 * 	 Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States{Start, Locked, NumPressed, NumReleased, Unlocked, NumPressedR, NumReleasedR} state;
void Tick(){
	switch(state){	//transistions
		case Start:
			state = Locked;
			break;
		case Locked:
			if(PINA == 0x04){
				state = NumPressed;
			}
			else{
				state = Locked;
			}
			break;
		case NumPressed:
			if(PINA == 0x00){
				state = NumReleased;
			}
			else if(PINA == 0x80){
				state = Locked;
			}
			else{
				state = NumPressed;
			}
			break;
		case NumReleased:
			if(PINA == 0x02){
				state = Unlocked;
			}
			else if(PINA == 0x80){
				state = Locked;
			}
			else{
				state = NumReleased;
			}
			break;
		case Unlocked:
			if(PINA == 0x80){
				state = Locked;
			}
			else if(PINA == 0x04){
				state = NumPressedR;
			}
			else{
				state = Unlocked;
			}
			break;
		case NumPressedR:
			if(PINA == 0x00){
				state = NumReleasedR;
			}
			else if(PINA == 0x80){
				state = Locked;
			}
			else{
				state = NumPressedR;
			}
			break;
		case NumReleasedR:
			if(PINA == 0x02){
				state = Locked;
			}
			else if(PINA == 0x08){
				state = Locked;
			}
			else{
				state = NumReleasedR;
			}
			break;
		default:
			state = Start;
			break;
	}
	switch(state){ //State Action
		case Locked:
			PORTB = 0x00;
			PORTC = 0x01;
			break;
		case NumPressed:
			PORTC = 0x02;
			break;
		case NumReleased:
			PORTC = 0x03;
			break;
		case Unlocked:
			PORTC = 0x04;
			PORTB = 0x01;
			break;
		case NumPressedR:
			PORTC = 0x05;
			PORTB = 0x01;
			break;
		case NumReleasedR:
			PORTC = 0x06;
			PORTB = 0x01;
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PINA = 0xFF;	//Inputs
	DDRB = 0xFF;	PINB = 0x00;	//Outputs
	DDRC = 0xFF;	PINC = 0x00;	//Outputs
    /* Insert your solution below */
	PORTB = 0x00;
	PORTC = 0x00;
	state = Start;
    while (1) {
	Tick();	
    }
    return 1;
}
