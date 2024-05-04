/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: fan_controller.c
 *
 * Description: Source file for Fan Controller System Project
 *
 * Author: Omar Rizk
 *
 ******************************************************************************/


/* MCAL Layer Libraries */
#include "../MCAL/adc/adc.h"                    /* Include ADC driver header file */
#include "../MCAL/pwm_timer0/pwm_timer0.h"      /* Include PWM Timer0 driver header file */

/* HAL Layer Libraries */
#include "../HAL/dcmotor/dcmotor.h"             /* Include DC Motor driver header file */
#include "../HAL/lcd/lcd.h"                     /* Include LCD driver header file */
#include "../HAL/lm35_Sensor/lm35_Sensor.h"     /* Include LM35 Temperature Sensor driver header file */


int main()
{
    /* Variable to store lm35 temperature readings */
    uint8 temp;

    /* Configuration structure for ADC driver */
    ADC_ConfigType ADC_Config = {ADC_INTERNAL_REF, ADC_PRESCALER_FCPU_8};

    /* ADC Initialization */
    ADC_init(&ADC_Config);

    /* Initialize DC MOTOR */
    DcMotor_init();

    /* Initialize LCD */
    LCD_init();
    /* Move cursor to row 0 - column 4 */
    LCD_moveCursor(0, 4);
    LCD_displayString("Fan is ");
    /* Move cursor to row 1 - column 3 */
    LCD_moveCursor(1, 2);
    LCD_displayString("Temp =      C");

    while(1)
    {
        temp = LM35_getTemperature(); /* Read temperature from LM35 sensor */

        if (temp < 30)
        {
            DcMotor_Rotate(STOP, 0); /* Stop DC Motor */

            /* Move cursor to row 0 - column 11 */
            LCD_moveCursor(0, 11);
            LCD_displayString("OFF");
            /* Move cursor to row 0 - column 10 */
            LCD_moveCursor(1, 10);
            /* Display Temp value on LCD */
            LCD_intgerToString(temp); /* Convert temperature to string and display on LCD */
            /* Clear after displaying value */
            LCD_displayCharacter(' ');
        }
        else
        {
            /* Move cursor to row 0 - column 11 */
            LCD_moveCursor(0, 11);
            LCD_displayString("ON ");
            /* Move cursor to row 0 - column 10 */
            LCD_moveCursor(1, 10);

            /* If temperature is more than or equal 30C and less than 60C */
            if (temp >= 30 && temp < 60)
            {
                /* Rotate the motor clockwise at 25% of max speed */
                DcMotor_Rotate(CLOCKWISE, 25);
            }
            /* If temperature is more than or equal 60C and less than 90C */
            else if (temp >= 60 && temp < 90)
            {
                /* Rotate the motor clockwise at 50% of max speed */
                DcMotor_Rotate(CLOCKWISE, 50);
            }
            /* If temperature is more than or equal 90C and less than 120C */
            else if (temp >= 90 && temp < 120)
            {
                /* Rotate the motor clockwise at 75% of max speed */
                DcMotor_Rotate(CLOCKWISE, 75);
            }
            /* If temperature is more than or equal than 120C */
            else if (temp >= 120)
            {
                /* Rotate the motor clockwise at 100% of max speed */
                DcMotor_Rotate(CLOCKWISE, 100);
            }

            /* Display Temp value on LCD */
            LCD_intgerToString(temp); /* Convert temperature to string and display on LCD */
            /* Clear after displaying value */
            LCD_displayCharacter(' ');
        }
    }
}
