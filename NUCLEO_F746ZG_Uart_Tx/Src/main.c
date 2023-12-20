#include "stm32f7xx.h"


//#include <stdint.h>


//User LD1: a green user LED is connected to the STM32 I/O PB0 (RCC_AHB1ENR = 2), (GPIOB_MODER = 01 pin0,1)
//User LD2: a blue user LED is connected to PB7. (GPIOB_MODER = 01 pin15,14)
//User LD3: a red user LED is connected to PB14. (GPIOB_MODER = 01 pin29,28)

//B1 USER: the user button is connected to the I/O PC13 by default.
//(RCC_AHB1ENR = 4)(GPIOC_MODER = 00 pin27,26)

//RCC AHB1 peripheral clock register (RCC_AHB1ENR)
//GPIO port mode register (GPIOx_MODER)

//*ALTERNATE FUNCTION:AF7
// USART3 Tx:PD8
// USART3 Rx:PD9

//Symbolic name for enables of GPIOs (macros)
#define GPIO_CLK_EN_B			(1U<<1)
#define GPIO_CLK_EN_C			(1U<<2)
//---------------------------------------------


#define USER_LED1_MODER 		(1U<<0)
#define USER_LED1_MODER2 		(1U<<1)

#define USER_LED2_MODER 		(1U<<14)
#define USER_LED2_MODER2 		(1U<<15)

#define USER_LED3_MODER 		(1U<<28)
#define USER_LED3_MODER2 		(1U<<29)

#define USER_USER_B1_MODER 		(1U<<27)
#define USER_USER_B1_MODER2		(1U<<26)


#define USER_LED1		 		(1U<<0) 	//Green LED
#define USER_LED2		 		(1U<<7) 	//Blue LED
#define USER_LED3		 		(1U<<14) 	//Red LED


#define PIN13		 		    (1U<<13)   // Input pin
#define BTN_PIN  				PIN13

#define  GPIODEN				(1U<<3)

set_ahb1_periphclock(uint32_t perihs);

set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);


int main(void)
{
	//*Enable clock access for Port B*/
	//RCC_AHB1EN_R  |= GPIO_CLK_EN_B;
	RCC->AHB1ENR |= GPIO_CLK_EN_B;  //

	//*Enable clock access for Port c*/
	RCC->AHB1ENR |= GPIO_CLK_EN_C;
	GPIOC->MODER &= ~USER_USER_B1_MODER;
	GPIOC->MODER &= ~USER_USER_B1_MODER2;
	//*Configure Button1 PC13 as input pin*/


	//*Configure LED pins as output pins*/
	//GPIOB_MODE_R |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
	GPIOB->MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;

while(1)
{
	//*Toggle on all LEDS*/
	//GPIOB_ODR_R |= USER_LED1 | USER_LED2 | USER_LED3;

	//*Check input (GPIOC_IDR:13)
	if(GPIOC->IDR & BTN_PIN)

	{
	//*Turn on/off all LEDS*/
	//GPIOB_ODR_R ^= USER_LED1 | USER_LED2 | USER_LED3;
	//GPIOB->ODR ^= USER_LED1 | USER_LED2 | USER_LED3;
	GPIOB->BSRR = (1U<<0) | (1U<<7) | (1U<<14);
	//for(int i = 0;i<1000000;i++){}
	}
	else
	{
	GPIOB->BSRR = (1U<<16) | (1U<<23) | (1U<<30);
	//for(int i = 0;i<1000000;i++){}
	}
}

void uart3_tx_init(void)
{
	/*1. Enable clock access to GPIOD*/
	set_ahb1_periphclock(GPIODEN); //RCC->AHB1ENR |= GPIODEN

	/*2. Set PD8 mode to alternate function*/


	/*3. Set alternate function to USART*/




	/*Enable clock to USART module*/
	/*Configure USART parameters*/
	/*Set baudrate*/
	/*Enable USART*/






}

void set_ahb1_periphclock(uint32_t perihs)
		{
			//RCC->AHP1ENR |= perihs;
			SET_BIT(RCC->AHB1ENR,perihs);
		}

void set_ahb2_periphclock(uint32_t perihs)
		{
			//RCC->AHP1ENR |= perihs;
			SET_BIT(RCC->AHB2ENR,perihs);
		}

void set_apb1_periphclock(uint32_t perihs)
		{
			//RCC->AHP1ENR |= perihs;
			SET_BIT(RCC->APB1ENR,perihs);
		}

void set_apb2_periphclock(uint32_t perihs)
		{
			//RCC->AHP1ENR |= perihs;
			SET_BIT(RCC->APB2ENR,perihs);
		}


void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)

	{
	/*Direct EXAMPLE*/
	//Clear the relevant bits in the mode register
	//GPIO->MODER  &=~(1U<<16);
	//GPIO->MODER  &=~(1U<<18);

	//Set the relevant bits in the mode register
	//GPIO->MODER  |=(1U<<17);
	//---------------------------------------------


	// *MODIFY_REG ex.

	/* 0x3 = 0b 11
	 * POSITION_VAL(1U<<8)
	 *
	 * (1U<<8) = 0000 0000 0000 0000 0000 0001 0000 0000
	 * rbit    = 0000 0000 1000 0000 0000 0000 0000 0000
	 * clz = 8
	 * POSITION_VAL(1U<<8) * 2 = 16
	 * 03x3 << 16 = (1U<<16 | (1U<<17)
	 * CLEAR (1U<<16 | (1U<<17) )  ==>   &=~((1U<<16) | (1U<<17))
	 *
	 * Mode = 0b 10 = 0x2
	 * 2 << 16 ==> bit16 = 0, bit 17 = 1
	 */

	MODIFY_REG(GPIOx->MODER, (0x3 << (POSITION_VAL(Pin) * 2U)), (Mode << (POSITION_VAL(Pin) * 2U)));

	}


}
