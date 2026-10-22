// LED Toggle program with a software delay between LED on and LED off.

//Turn on the LED3 (Orange Led) on the STM32F047G-DISC1 Card.
// Bitwise Operators and Masks

//LED3 is on GPIO PD13 pin

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
	*pClkCtrlreg |= (1 << 3);

	// 2. Configure the mode of the IO pin at output
	//a. Clear the 26th and 27th bit positions.
	*pPortDModeReg &= ~(3 << 26);
	// b. make 26th bit position as 1 (SET)
	*pPortDModeReg |= (1 << 26);

	/*
	while(1) {
		//3. Set 13th bit of the output data register to make I/O pin-13 HIGH to light Orange LED (LED13)
		*pPortDOutReg |= (1 << 13);
		// introduce small human observable delay
		for(uint32_t i =0; i<2000000; i++);
		*pPortDOutReg &= ~(1 << 13);
		for(uint32_t i =0; i<2000000; i++);
	}
	*/
	// OR:
	while(1) {
		for(uint32_t i =0; i<3000000; i++);
		*pPortDOutReg ^= (1 << 13);
	}

}

void delay(int) {

}
