/******************************************************************************
 *
 * Module: TIMER0_PWM
 *
 * File Name: pwm_timer0.h
 *
 * Description: Header file for the ATmega32 Timer0 PWM driver
 *
 * Author: Omar Rizk
 *
 *******************************************************************************/

#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_

#include"../../std_types.h"

/*
 * [Function Name]	: PWM_Timer0_Start
 * [Description]	: This Function is responsible for initializing Timer0 PWM Mode.
 * [Args]		    :
 * [In] unit8 duty_cycle : This Arg shall indicate duty cycle of generated PWM signal.
 * [Return]		    : Void.
 */
void PWM_Timer0_start(uint8 duty_cycle);

#endif
