# Fan Controller System using ATmega32

#### The Fan Controller System automatically adjusts fan speed based on LM35 temperature sensor readings using an ATmega32 microcontroller. It monitors temperature, displays it on an LCD, and controls fan speed accordingly.

## Features:

* Layered Architecture: The project is structured based on a layered architecture model for modularity and scalability.
* Temperature Sensing: Continuous monitoring of temperature using an LM35 temperature sensor.
* LCD Display: Displays the temperature value and fan state for user visibility.
* Fan Control Logic: Adjusts fan speed based on temperature thresholds: OFF below 30°C, 25% speed at 30-59°C, 50% speed at 60-89°C, 75% speed at 90-119°C, and 100% speed at 120°C or higher.
* DC Motor Control: Speed of the fan is controlled using PWM signal generated from Timer0.
* User Interaction: External push buttons enable user interaction to start, stop, resume, and reset the fan controller.

## Hardware Components:

* ATmega32 Microcontroller
* LM35 Temperature Sensor
* DC Motor (Fan)
* LCD Display
* External Push Buttons
* 7-Segment Display

## Software Components:

* ADC Driver: Configures ADC to operate with internal reference voltage and prescaler.
* GPIO Driver: Handles pin directions and writing to pins.
* LCD Driver: Displays temperature and fan state on the LCD.
* Temperature Sensor Driver: Interfaces with the LM35 temperature sensor.
* DC Motor Driver: Controls the direction and speed of the DC motor.
* PWM Driver: Generates PWM signal for motor speed control.

## Implementation:

- The project is implemented in C programming language, following a layered architecture model for better organization and maintainability.
- It utilizes the hardware components and software drivers to achieve the desired functionality.

## Usage:
- Clone the repository and upload the provided code to an ATmega32 microcontroller.
- Follow hardware setup instructions and connect the required components as specified.
- Power up the microcontroller to start using the fan controller system.

## Additional Resources:

[LinkedIn Post](https://www.linkedin.com/posts/omar-sherif-rizk_embeddedsystems-avr-project-activity-7081141229492576256-6wh5?utm_source=share&utm_medium=member_desktop) demonstrates the hardware setup and functionality of the Fan Controller System through a video.

## Contributing:
Contributors are welcome to suggest improvements, report issues, and submit pull requests to enhance the project's functionality and usability.

## License:
This project is licensed under the MIT License, allowing for modification, distribution, and commercial use with proper attribution.
