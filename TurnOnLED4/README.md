# STM32 GPIO - Turn On LED4

A simple bare-metal C project to turn on the green LED (LED4) on the STM32F407G-DISC1 development board using direct register access.

## What I Learned
- Enabling the GPIO peripheral clock through the RCC AHB1ENR register
- Configuring GPIO pin PD12 as an output
- Using bitwise operators and masks to modify register bits,
- Controlling an LED through the GPIO output data register (ODR)

## Hardware
- STM32F407G-DISC1 Discovery Board

## Implementation
The program enables the GPIOD peripheral clock, configures pin PD12 as a general-purpose output, and sets the pin HIGH to turn on LED4 (Green LED).

## Status
Completed