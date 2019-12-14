# AVR Exploration

This is a project that is inteded to explore some of the more advanced features that the Atmega328p offeres by programming this in Embedded C. I am using the Arduino Uno Rev3 as a development board because of how easily accessible it is. I have also purchased an Atmel ICE to program the chip through its ICSP header using SPI. I am using Atmel Studio 7 as the development enviroment and the following datasheets for reference material.

* [Arduino Uno Schematic](https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf)
* [Atmel-ICE User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-ICE_UserGuide.pdf)
* [ATmega382p Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
* [ATtiny85-20P Datasheet](https://www.mouser.com/datasheet/2/268/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATti-1315542.pdf)


## ATmega328p/Blink Project Notes:

### PWM Clear Timer on Compare Match (CTC) Mode:
The pins listed below are the pins we will be using for the waveform generation of the PWM signal of two different color LED's.  
*NOTE: These value where determined from the datasheets referenced above.*

* **PB1** (PCINT1/OC1A)
* **PB2** (PCINT2/SS/OC1B)

These pins are both on **PORTB** which means to use these pins as ouputs, we need to toggle their value in the Data Direction Register for PORTB (**DDRB**) high (logic 1).
This can be done with the following statement: 

```c
DDRB |= 0x06 // This is equivalent to 0000 0110
```

