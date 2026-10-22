
# STM32 LED Toggle Using Bitwise XOR

A simple STM32F407 Discovery project that toggles the orange LED (PD13) using bitwise XOR and a software delay.

## What I Learned
- Enabling the GPIOD peripheral clock through the RCC AHB1ENR register.
- Configuring PD13 as an output using the GPIO mode register (MODER).
- Toggling the LED state using the XOR (`^`) bitwise operator.
- Implementing a simple software delay using a loop.

## Hardware
- STM32F407G-DISC1 Discovery Board
- Orange LED (PD13)

## How It Works
The program configures PD13 as an output and repeatedly toggles its state using:


*pPortDOutReg ^= (1U << 13);


A software delay loop is used between toggles to make the LED blinking visible.
