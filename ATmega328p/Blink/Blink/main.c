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
#include <math.h>		// Math is used for the sine wave modeling of the duty cycle.

// Global variable definitions.
const float DELAY_VAL_MS = 1000.00;	// This is how many milliseconds the delay function will delay.

/**
 * Takes the designated bit number (represented in hexidecimal) to be used with blinkOnBoardLED() and sets it as an output.
 *
 * @param pinNum char
 * @return void
 */
void blinkOnBoardLEDConfig(char bitNum) 
{	
	DDRB |= bitNum;
}

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
 * @param pinNum char
 * @return void
 */
void fastPWMModeCofig() 
{ 
	//PORTB |= (1 << (pinNum - 1));		This will be implemented in the future.
	// The frequency of the PWM signal can be calculated 
	// freq_pwm = (freq_clk)/(2*N*(1 + TOP))
	
	DDRB |= (1<<DDB2)|(1<<DDB1);
	// PB1 and PB2 is now an output
	
	ICR1 = 0xFFFF;
	// Set TOP to 16bit
	
	OCR1A = 0x3FFF;
	// set PWM for 25% duty cycle @ 16bit

	OCR1B = 0xBFFF;
	// set PWM for 75% duty cycle @ 16bit

	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
	// set none-inverting mode

	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12)|(1 << WGM13);
	// set Fast PWM mode using ICR1 as TOP
	    
	TCCR1B |= (1 << CS10);
	// START the timer with no prescaler.
		
}

// Main function
int main(void)
{
	char pin5 = 0x20; // This defines the DDRx Register for PORTB. This should be 0001 0000
	blinkOnBoardLEDConfig(pin5);
	fastPWMModeCofig();
	
    /* Replace with your application code */
    while (1) 
    {
		// This blinks an led on and off. Useful for debugging and testing of the MCU control
		//blinkOnBoardLED(pin5, DELAY_VAL_MS);
	}
	return 0;
}
