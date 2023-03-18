/*
 * Module: ADC
 * File name: adc.c
 * Description: source file for Atmega16 ADC driver using interrupt
 * Created on: Mar 18, 2023
 * Author: Mohamed Wageh
 */

#include "adc.h"

void ADC_init(){
	/* chose internal V_reference*/
	CLEAR_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);

	/*Enable ADC interrupt */
	SET_BIT(ADCSRA,ADIE);

	/* chose prescaler =128 F=8Mhz ==>> 8M/128 = 62.5 Khz*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	/* Enable ADC*/
	SET_BIT(ADCSRA,ADEN);
}

void ADC_readChannel(uint8 channel){
	ADMUX=((ADMUX & 0XE0)|(0X07 & channel));
	SET_BIT(ADCSRA,ADSC);
}

ISR(ADC_vect){
	/* Read the digital result after conversion */
	g_adcData=ADC;
}


