/*
 * main.c
 *
 *  Created on: Mar 18, 2023
 *  Author: Mohamed Wageh
 */


#include "adc.h"
#include "lcd.h"

volatile uint16 g_adcData; /*global varible to read ADC register data from ISR */

int main(void){

	/* Enable global interrupts */
	SREG|=(1<<7);

	/*initialize adc driver */
	ADC_init();

	/*initialize lcd driver */
	LCD_init();
	LCD_clearScreen();   /* clear LCD at the beginning */
	LCD_displayString("ADC Value = "); /* display this string "ADC Value = " only once at LCD */

	while(1){

		LCD_goToRowColumn(0,12); /* display the number every time at this position */
		ADC_readChannel(0);    /*read channel zero where the potentiometer is connect*/
		LCD_intgerToString(g_adcData); /*display the ADC value on LCD screen */

	}
	return 0;
}

