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


enum States{Start, Wait, Increment_Pressed, Increment, Decrement_Pressed, Decrement, Reset_Count} state;
void Tick(){
	switch(state){	//transistions
		case Start:
			state = Wait;
			break;
		case Wait:
			if(PINA == 0x01){
				state = Increment;
			}
			else if(PINA == 0x02){
				state = Decrement;
			}
			else if(PINA == 0x03){
				state = Reset_Count;
			}
			else if(PINA == 0x00){
				state = Wait;
			}
			break;
		case Increment_Pressed:
			if(PINA == 0x01){
				state = Increment_Pressed;
			}
			else if(PINA == 0x03){
				state = Reset_Count;
			}
			else if(PINA == 0x00){
				state = Wait;
			}
			break;	
		case Increment:
			state = Increment_Pressed;
			break;
		case Decrement_Pressed:
			if(PINA == 0x02){
				state = Decrement_Pressed;
			}
			else if(PINA == 0x03){
				state = Reset_Count;
			}
			else if(PINA == 0x00){
				state = Wait;
			}
			break;
		case Decrement:
			state = Decrement_Pressed;
			break;
		case Reset_Count:
			state = Wait;
			break;
		default:
			state = Start;
			break;
	}
	switch(state){ //State Action
		case Increment_Pressed:
			break;
		case Increment:
			if(PORTC < 9){
				PORTC = PORTC + 1;
			}
			break;
		case Decrement_Pressed:
			break;
		case Decrement:
			if(PORTC > 0){
				PORTC = PORTC - 1;
			}
			break;
		case Reset_Count:
			PORTC = 0x00;
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PINA = 0xFF;	//Inputs
	DDRC = 0xFF;	PINC = 0x00;	//Outputs
    /* Insert your solution below */
	PORTC = 0x07;
	state = Start;
    while (1) {
	Tick();	
    }
    return 1;
}
