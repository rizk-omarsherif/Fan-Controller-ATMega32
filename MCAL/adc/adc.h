/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Omar Rizk
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                                Types Declaration                           *
 *******************************************************************************/

typedef enum {
    ADC_AREF,
    ADC_AVCC,
    ADC_INTERNAL_REF = 3
} ADC_ReferenceVoltage;

typedef enum {
    ADC_PRESCALER_FCPU_2 = 1,
    ADC_PRESCALER_FCPU_4,
    ADC_PRESCALER_FCPU_8,
    ADC_PRESCALER_FCPU_16,
    ADC_PRESCALER_FCPU_32,
    ADC_PRESCALER_FCPU_64,
    ADC_PRESCALER_FCPU_128
} ADC_Prescaler;

typedef struct {
    ADC_ReferenceVoltage ref_volt;
    ADC_Prescaler prescaler;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for reading analog data from a certain ADC channel
 * and converting it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
