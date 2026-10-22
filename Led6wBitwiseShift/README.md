
# STM32 LED6 Control Using Bitwise Shifts

## Overview
This project turns on the blue LED (LED6) on the STM32F407G-DISC1 development board using direct register access and bitwise shift operations in C.

## What I Learned
- Enabling the GPIOD peripheral clock through the RCC AHB1ENR register.
- Configuring PD15 as an output using the GPIOD MODER register.
- Using bitwise shifts, masks, AND, and OR operators to modify specific register bits.
- Controlling the LED through the GPIOD output data register (ODR).

## Implementation
The LED is connected to GPIO PD15. The program enables the GPIOD clock, configures PD15 as an output and sets the corresponding ODR bit to HIGH.

This project builds on a previous exercise that used manually defined bit masks to control LED4, exploring bitwise shift operations to configure and control LED6.
