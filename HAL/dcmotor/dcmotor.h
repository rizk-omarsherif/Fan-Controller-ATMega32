/******************************************************************************
 *
 * [Module]: DC MOTOR
 *
 * [Author]: Omar Rizk
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the DC MOTOR driver
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "../../std_types.h"            /* Include standard defined types header file */
#include "../../MCAL/gpio/gpio.h"       /* Include GPIO driver header file */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* DC motor Port and Pins IDs */
#define DCMOTOR_PORT            PORTB_ID
#define DCMOTOR_IN1             PIN1_ID
#define DCMOTOR_IN2             PIN2_ID
#define DCMOTOR_ENABLE          PIN3_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    STOP, CLOCKWISE, COUNTER_CLOCKWISE
} DCMOTOR_STATE;

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/

/*
 * [Function Name]   : DcMotor_init
 * [Description]     : This Function is responsible for initializing DC motor pins.
 * [Args]            : Void.
 * [Return]          : Void.
 */
void DcMotor_init(void);


/*
 * [Function Name]   			: DcMotor_Rotate
 * [Description]     			: This function is responsible for controlling motor rotation & speed.
 * [Args]            			:
 * [In] DCMOTOR_STATE rotation  : This Arg shall indicate rotation direction  of the dc motor.
 * [In] uint8		  speed     : This Arg shall indicate required duty cycle of the dc motor.
 * [Return]          			: Void.
 */
void DcMotor_Rotate(DCMOTOR_STATE rotation, uint8 speed);

#endif /* DCMOTOR_H_ */
