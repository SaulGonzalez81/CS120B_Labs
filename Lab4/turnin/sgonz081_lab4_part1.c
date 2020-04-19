/*	Author: sgonz081
 * 	 Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States{Start, LED1_Released, LED1_Pressed, LED2_Released, LED2_Pressed} state;
void Tick(){
	switch(state){	//transistions
		case Start:
			state = LED1_Released;
			break;
		case LED1_Released:
			if(PINA == 0x01){
				state = LED2_Pressed;
			}
			else{
				state = LED1_Released;
			}
			break;
		case LED1_Pressed:
			if(PINA == 0x01){
				state = LED1_Pressed;
			}
			else{
				state = LED1_Released;
			}
			break;	
		case LED2_Released:
			if(PINA == 0x01){
				state = LED1_Pressed;
			}
			else{
				state = LED2_Released;
			}
			break;
		case LED2_Pressed:
			if(PINA == 0x01){
				state = LED2_Pressed;
			}
			else{
				state = LED2_Released;
			}
			break;
		default:
			state = Start;
			break;
	}
	switch(state){ //State Action
		case LED1_Released:
			PORTB = 0x01;
			break;
		case LED1_Pressed:
			PORTB = 0x01;
			break;
		case LED2_Released:
			PORTB = 0x02;
			break;
		case LED2_Pressed:
			PORTB = 0x02;
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PINA = 0xFF;	//Inputs
	DDRB = 0xFF;	PINB = 0x00;	//Outputs
    /* Insert your solution below */
	state = Start;
    while (1) {
	Tick();	
    }
    return 1;
}
