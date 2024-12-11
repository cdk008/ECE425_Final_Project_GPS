/*
 * @file main.c
 *
 * @brief Main source code for the UART GPS program.
 *
 * This file contains the main entry point and function definitions for the UART program.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author Cody Krueger
 */

#include "TM4C123GH6PM.h"

#include "SysTick_Delay.h"
#include "UART0.h"
#include "GPIO.h"
#include "string.h"

#include "UART1.h"

int main(void)
{
	SysTick_Delay_Init();
	
	UART1_Init();
	
	UART0_Init();
	
	
	while(1)
	{
		char str_buffer[128];
		UART1_Input_String(str_buffer, 128);		

		UART0_Output_String(str_buffer);
		UART0_Output_Character(UART0_CR);

	}
}
