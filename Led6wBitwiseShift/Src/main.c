//Turn on the LED6 (Blue Led) on the STM32F047G-DISC1 Card.
// Bitwise Operators and Masks

//LED6 (Blue led) is on GPIO PD15 pin

//Address of Clock control register(AHB1ENR) (RCC) to Enable The Clock!
//0x40023800 + 0x30 ==> 0x40023830

//Address of the GPIOD mode register (used to control mode) To Select the Mode
// 0x40020C00 + 0x00 ==> 0x40020C00

// Address of the GPIOD output data register (used to write) To Make The LED HIGH
// 0x40020C00 + 0x14 ==> 0x40020C14

#include <stdint.h>

int main(void)
{

	uint32_t *pClkCtrlreg = (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;


	//1. Enable the Clock for GPIOD peripheral in the AHB1ENR / Set 3rd bit of this register to 1
	*pClkCtrlreg |= (1 << 3);

	// 2. Configure the mode of the IO pin at output
	//a. Clear the 30th and 31st bit positions.
	//*pPortDModeReg &= ~(1 << 30);
	//*pPortDModeReg &= ~(1 << 31);
	*pPortDModeReg &= ~(3 << 30);
	// b. make 30th bit position as 1 (SET)
	*pPortDModeReg |= (1 << 30);

	//3. Set 15th bit of the output data register to make I/O pin-15 HIGH to light LED6
	*pPortDOutReg |= (1 << 15);

	while(1);
}
