/******************************************************************************
 *
 * Module: TIMER0_PWM
 *
 * File Name: pwm_timer0.c
 *
 * Description: Source file for the ATmega32 Timer0 PWM driver
 *
 * Author: Omar Rizk
 *
 *******************************************************************************/

#include "../pwm_timer0/pwm_timer0.h"

#include<avr/io.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * [Function Name]	: PWM_Timer0_Start
 * [Description]	: This Function is responsible for Starting Timer0 PWM Mode.
 * [Args]		    :
 * [In] unit8 duty_cycle : This Arg shall indicate duty cycle of generated pwm signal.
 * [Return]		    : Void.
 */
void PWM_Timer0_start(uint8 duty_cycle)
{
	/* Setting timer value to 0 */
	TCNT0 = 0;

	/* Setting Compare value to PWM duty cycle value */
	OCR0  = duty_cycle;

	/* Setting PB3/OC0 as output pin */
	DDRB  = DDRB | (1<<PB3);

	/* Configure timer control register TCCR0
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
