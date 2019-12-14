/*
 * Blink.c
 *
 * Created: 12/7/2019 15:45:20
 * Author : Christian
 */ 
// Macro Definitions
#define F_CPU 16000000UL

// Includes
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

// Global variable definitions.
const float DELAY_VAL_MS = 1000.00;	// This is how many milliseconds the delay function will delay.

/**
 * Takes the designated pin number and toggles it on and off dictated by the defined parameter for delay.
 *
 * @param pinNum char
 * @param delay float
 * @return void
 */
void blinkOnBoardLED(char pinNum, float delay) 
{ 
	if (DELAY_VAL_MS)
		delay = DELAY_VAL_MS ;		// This immediately assigns the value of delay to the globally defined value to avoid compilation errors.
	else
		delay = 1000.0;		// The default value for delay is 1ms = 1000.0
		
	PORTB |= pinNum; 
	_delay_ms(delay);
	PORTB = 0x00;
	_delay_ms(delay);
}

/**
 * Sets proper registers for Fast-PWM mode .
 *
 * 
 * @return void
 */
void fastPWMCofig(char pinNum) 
{ 
	PORTB |= (1 << 3);
	PORTB |= (1 << 2);
}

// Main function
int main(void)
{
	DDRB |= 0x06;						// This defines the DDRx Register for PORTB. This should be 0000 0110
	//DDRB |= 0x20;						// This defines the DDRx Register for PORTB. This should be 0001 0000
	char pin5 = 0x20;
	
    /* Replace with your application code */
    while (1) 
    {
		// This blinks an led on and off. Useful for debugging and testing of the MCU control
		blinkOnBoardLED(pin5, DELAY_VAL_MS);
	}
	return 0;
}


