/*
 * Blink.c
 *
 * Created: 12/7/2019 15:45:20
 * Author : Christian
 */ 
#define F_CPU 16000000UL

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

/* 
 * PB1(PCINT1/OC1A) --> OC1A
 * PB2(PCINT2/SS/OC1B)	 --> OC1B
 */

// Main function
int main(void)
{
	const float delay_val_ms = 1000.00;	// This is how many milliseconds the delay function will delay.
	unsigned char G = 127;				// This is the amplitude of the sine function
	DDRB |= 0x0C;						// This defines the DDRx Register for PORTB. This should be 0b0001100
	
    /* Replace with your application code */
    while (1) 
    {
		// This blinks an led on and off. Useful for debugging and testing of the MCU control
		PORTB |= (1 << 3);
		_delay_ms(delay_val_ms);
		PORTB |= (1 << 2);
		_delay_ms(delay_val_ms);
		
		printf("The output data is %c", x);
	}
}


// 0b0000 0000
// 0b0000 0011
//---------
// 0b0000 0011