/******************************************************************************
 *
 * [Module]: DC MOTOR
 *
 * [Author]: Omar Rizk
 *
 * File Name: dcmotor.C
 *
 * Description: Source file for the DC MOTOR driver
 *
 *******************************************************************************/

#include "dcmotor.h"                   			 /* Include DC Motor driver header file */
#include "../../MCAL/gpio/gpio.h"       		 /* Include GPIO driver header file */
#include "../../MCAL/pwm_timer0/pwm_timer0.h"    /* Include PWM Timer0 driver header file */

/*******************************************************************************
 *                            Functions Definitions                            *
 *******************************************************************************/

/*
 * [Function Name]   : DcMotor_init
 * [Description]     : This Function is responsible for initializing DC motor pins.
 * [Args]            : Void.
 * [Return]          : Void.
 */
void DcMotor_init(void)
{
    /* Configure L298 direction pins as output pin */
    GPIO_setupPinDirection(DCMOTOR_PORT, DCMOTOR_IN1, PIN_OUTPUT);
    GPIO_setupPinDirection(DCMOTOR_PORT, DCMOTOR_IN2, PIN_OUTPUT);

    /* Configure L298 enable pin as output pin */
    GPIO_setupPinDirection(DCMOTOR_PORT, DCMOTOR_ENABLE, PIN_OUTPUT);

    /* Stop at the DC-Motor at the beginning */
    GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN1, LOGIC_LOW);
    GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN2, LOGIC_LOW);
}

/*
 * [Function Name]   			: DcMotor_Rotate
 * [Description]     			: This function is responsible for controlling motor rotation & speed.
 * [Args]            			:
 * [In] DCMOTOR_STATE rotation  : This Arg shall indicate rotation direction  of the dc motor.
 * [In] uint8         speed     : This Arg shall indicate required duty cycle of the dc motor.
 * [Return]          			: Void.
 */
void DcMotor_Rotate(DCMOTOR_STATE rotation, uint8 speed)
{
    uint8 duty_cycle = 0;   /* Initialize duty-cycle value */

    /* Convert received percentage into duty-cycle value */
    duty_cycle = (uint8) ((uint16) (speed * 255) / 100);

    /* Control the motor as required */
    switch (rotation)
    {
    case STOP:
        PWM_Timer0_start(0); /* Stop PWM speed control */
        /* Stop motor rotation */
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN1, LOGIC_LOW);
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN2, LOGIC_LOW);
        return;
    case CLOCKWISE:
        PWM_Timer0_start(duty_cycle); /* Start PWM speed control */
        /* Rotate motor clock-wise direction */
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN1, LOGIC_HIGH);
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN2, LOGIC_LOW);
        return;
    case COUNTER_CLOCKWISE:
        PWM_Timer0_start(duty_cycle); /* Start PWM speed control */
        /* Rotate motor counter clock-wise direction */
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN1, LOGIC_LOW);
        GPIO_writePin(DCMOTOR_PORT, DCMOTOR_IN2, LOGIC_HIGH);
        return;
    }
}
