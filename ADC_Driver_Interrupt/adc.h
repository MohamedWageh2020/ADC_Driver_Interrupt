/*
 * Module: ADC
 * File name: adc.h
 * Description: header file for Atmega16 ADC driver using interrupt
 * Created on: Mar 18, 2023
 * Author: Mohamed Wageh
 */

#ifndef ADC_H_
#define ADC_H_

/* ******************************************************************
 *                               COMMON HEADER FILES
 ********************************************************************/

#include "micro_config.h"
#include "common_macros.h"
#include "std_types.h"


/* Extern global variables*/

extern volatile uint16 g_adcData;

/************************************************************************
 *                        Function prototypes
 ***********************************************************************/

/*
 * Description:
 * function responsible for initialize the ADC driver
 *
 * */
void ADC_init(void);

/*
 * Description:
 * Function responsible for read analog data from a specific ADC channel and
 * convert it to digital using ADC driver
 * */
void ADC_readChannel(uint8 channel_num);

/* **********************************************************************
 *                             Macros
 ***********************************************************************/



#endif /* ADC_H_ */
