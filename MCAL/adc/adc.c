/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Omar Rizk
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "../../common_macros.h" /* To use macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
    /* ADMUX Register Bits Description:
     * REFS1:0 = 00 to choose to connect external reference voltage by inputting this voltage through AREF pin
     * ADLAR   = 0 right adjusted
     * MUX4:0  = 00000 to choose channel 0 as initialization
     */
    ADMUX = (ADMUX & 0x3F) | (Config_Ptr->ref_volt << 6);

    /* ADCSRA Register Bits Description:
     * ADEN    = 1 Enable ADC
     * ADIE    = 0 Disable ADC Interrupt
     * ADATE   = 0 Disable Auto Trigger
     */
    ADCSRA = (0x78 & ADCSRA) | (1 << ADEN) | (Config_Ptr->prescaler);
}

uint16 ADC_readChannel(uint8 channel_num)
{
    channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
    ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before setting the required channel */
    ADMUX |= channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
    SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
    while (BIT_IS_CLEAR(ADCSRA, ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
    SET_BIT(ADCSRA, ADIF); /* Clear ADIF by writing '1' to it */
    return ADC; /* Read the digital value from the data register */
}
