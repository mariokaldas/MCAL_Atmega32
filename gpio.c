/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: mario kaldas
 *
 *******************************************************************************/

#include "../MCAL_Atmega32/gpio.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include "../MCAL_Atmega32/common_macros.h" /* To use the macros like SET_BIT */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else{
		switch(port_num){

		case PORTA_ID:
			if(value == HIGH){
				SET_BIT(PORTA,pin_num);
			}
			else{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;

		case PORTB_ID:
			if(value == HIGH)
				SET_BIT(PORTB,pin_num);
			else
				CLEAR_BIT(PORTB,pin_num);
			break;

		case PORTC_ID:
			if(value == HIGH)
				SET_BIT(PORTC,pin_num);
			else
				CLEAR_BIT(PORTC,pin_num);
			break;

		case PORTD_ID:
			if(value == HIGH)
				SET_BIT(PORTD,pin_num);
			else
				CLEAR_BIT(PORTD,pin_num);
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		return 0;
	}

	switch(port_num){

	case PORTA_ID:
		if(GET_BIT(PINA,pin_num))
			return 1;
		else
			return 0;
		break;

	case PORTB_ID:
		if(GET_BIT(PINB,pin_num))
			return 1;
		else
			return 0;
		break;

	case PORTC_ID:
		if(GET_BIT(PINC,pin_num))
			return 1;
		else
			return 0;
		break;

	case PORTD_ID:
		if(GET_BIT(PIND,pin_num))
			return 1;
		else
			return 0;
		break;
	}
	return 0;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}

	else{

		switch(port_num){

		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	if(port_num >= NUM_OF_PORTS)
	{
		return 0;
	}

	switch(port_num){

	case PORTA_ID:
		return PINA;
		break;
	case PORTB_ID:
		return PINB;
		break;
	case PORTC_ID:
		return PINC;
		break;
	case PORTD_ID:
		return PIND;
		break;
	}
	return 0;
}
