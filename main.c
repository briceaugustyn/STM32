#include "stm32f4xx.h"

//PA5

//AHB1

// set bit 0 in RCC_AHB1ENR to 1
#define GPIOD_EN (1<<3) // 0b 0000 0000 0000 0000 0000 0000 0000 1000

// set bit10 to 1 and bit 1 to 0 in GPIOA_MODER
#define MODER_5_OUT (1<<13)  // 0b 0000 0000 0000 0000 0000 0100 0000 0000

//green PD12 Port D pin 12
//orange PD13 Port D pin 13
//red PD14 Port D pin 14
//blue PD15 Port D pin 15
#define ODR_5_SET (1<<13)
#define ODR_5_RESET (0<<13)

#define LED_PIN (1<<13)


int main (void){


	// Configue LEDs
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable the clock of port D of the GPIO
		//GPIOD->MODER |= MODER_5_OUT;

		GPIOD->MODER |= GPIO_MODER_MODER13_0; // Green LED, set pin 12 as output
		// Turn on LEDs
			//GPIOD->BSRR = 1<<13; // Set the BSRR bit 12 to 1 to turn respective LED on

	while(1){

		for (int i = 0; i < 2000000; i++){}
		GPIOD->ODR ^= ODR_5_SET;

	}

}

