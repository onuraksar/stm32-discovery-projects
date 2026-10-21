//Turn on the LED4 (Green Led) on the STM32F047G-DISC1 Card.
// Bitwise Operators and Masks

//LED4 is on GPIO PD12 pin

//Address of Clock control register(AHB1ENR) (RCC) to Enable The Clock!
//0x40023800 + 0x30 ==> 0x40023830

//Address of the GPIOD mode register (used to control mode) To Select the Mode
// 0x40020C00 + 0x00 ==> 0x40020C00

// Address of the GPIOD output data register (used to write) To Make The LED HIGH
// 0x40020C00 + 0x14 ==> 0x40020C14

#include <stdint.h>

int main(void)
{

	uint32_t *pClkCtrlreg = (uint32_t *)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t *)0x40020C00;
	uint32_t *pPortDOutReg = (uint32_t *)0x40020C14;


	//1. Enable the Clock for GPIOD peripheral in the AHB1ENR
	*pClkCtrlreg |= 0x08;

	// 2. Configure the mode of the IO pin at output
	//a. Clear the 24th and 25th bit positions.
	*pPortDModeReg &= 0xFCFFFFFF;
	// b. make 24th bit position as 1 (SET)
	*pPortDModeReg |= 0x01000000;

	//3. Set 12th bit of the output data register to make I/O pin-12 HIGH
	*pPortDOutReg |= 0x1000;

	while(1);
}
