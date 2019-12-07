/*
 * Arduino_Test.c
 *
 * Created: 12/4/2019 20:41:15
 * Author : Christian
 */ 
#define F_CPU 16000000UL

//#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

// Main function
int main(void)
{
	const float delay_val_ms = 1000.00;	// This is how many milliseconds the delay function will delay.
	const float G = 127.5;				// This is the amplitude of the sine function
	DDRB |= 0x0C;						// This defines the DDRx Register for PORTB. This should be 0b00100000
	
    /* Replace with your application code */
    while (1) 
    {
		// This blinks an led on and off. Useful for debugging and testing of the MCU control
		//PORTB = 0x0C;
		//_delay_ms(delay_val);
		//PORTB = 0x00;
		//_delay_ms(delay_val);
		
		_delay_ms(delay_val_ms);
    }
}

