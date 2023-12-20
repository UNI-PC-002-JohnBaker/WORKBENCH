#include <stdint.h>


//User LD1: a green user LED is connected to the STM32 I/O PB0 (RCC_AHB1ENR = 2), (GPIOB_MODER = 01 pin0,1)
//User LD2: a blue user LED is connected to PB7. (GPIOB_MODER = 01 pin15,14)
//User LD3: a red user LED is connected to PB14. (GPIOB_MODER = 01 pin29,28)

//B1 USER: the user button is connected to the I/O PC13 by default. (RCC_AHB1ENR = 4)(GPIOC_MODER = 00 pin27,26)

//RCC AHB1 peripheral clock register (RCC_AHB1ENR)
//GPIO port mode register (GPIOx_MODER)

#define PERIPH_BASE 			0x40000000UL           // Base address all peripherals start here
#define AHB1_OFFSET				0x00020000UL
#define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1_OFFSET)

#define GPIOB_OFFSET			0x400UL
#define GPIOB_BASE				(AHB1PERIPH_BASE + GPIOB_OFFSET)

#define GPIOC_OFFSET			0x800UL
#define GPIOC_BASE				(AHB1PERIPH_BASE + GPIOC_OFFSET)

#define RCC_OFFSET				0x3800UL
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)
#define AHB1EN_R_OFFSET			0x30UL  				// THE ACTUAL REGISTER OFFSET

/*
// * CLOCK GATES
//this becomes a register
#define RCC_AHB1EN_R	 		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))		//Typecast to a pointer & dereference the pointer


#define MODER_OFFSET			0x00UL
#define GPIOB_MODE_R			(*(volatile unsigned int *)(GPIOB_BASE + MODER_OFFSET))  //final register
#define GPIOC_MODE_R			(*(volatile unsigned int *)(GPIOC_BASE + MODER_OFFSET))  //final register


//GPIOx_ODR
#define ODR_OFFSET			    0x14UL
#define GPIOB_ODR_R				(*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))  //final register
*/




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

#define USER_USER_B1_MODER 		(1U<<28)
#define USER_USER_B1_MODER2		(1U<<29)


#define USER_LED1		 		(1U<<0) 	//Green LED
#define USER_LED2		 		(1U<<7) 	//Blue LED
#define USER_LED3		 		(1U<<14) 	//Red LED

#define  __IO            volatile



//typedef struct
//{
//  __IO uint32_t MODER;        /*!< GPIO port mode register,                                  Address offset: 0x00 */
//  __IO uint32_t OTYPER;       /*!< GPIO port output type register,                           Address offset: 0x04 */
//  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,                          Address offset: 0x08 */
//  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
//  __IO uint16_t IDR;          /*!< GPIO port input data register,                            Address offset: 0x10 */
//  __IO uint32_t ODR;          /*!< GPIO port output data register,                           Address offset: 0x14 */
//  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
//  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
//  __IO uint32_t AFRL[2];      /*!< GPIO alternate function low register,                     Address offset: 0x24 */
//
//}GPIO_TypeDef;




typedef struct
{
	__IO uint32_t DUMMY[12];   //offset is 12 members x 4 bytes each as structured in RCC RM

	__IO uint32_t RCC_AHB1ENR;

}RCC_TypeDef;


typedef struct
{
	__IO uint32_t MODER;        /*!< GPIO port mode register,                                  Address offset: 0x00 */
	__IO uint32_t DUMMY[4];     //offset is 4 members x 4 bytes each as structured in GPIO RM
	__IO uint32_t ODR;          /*!< GPIO port output data register,                           Address offset: 0x14 */

}GPIO_TypeDef;


#define GPIOB 		((GPIO_TypeDef *)GPIOB_BASE)
#define RCC         ((RCC_TypeDef *)RCC_BASE)




int main(void)
{
	//*Enable clock access for Port B*/
	//RCC_AHB1EN_R  |= GPIO_CLK_EN_B;
	RCC->RCC_AHB1ENR |= GPIO_CLK_EN_B;

	//*Configure LED pins as output pins*/
	//GPIOB_MODE_R |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
	GPIOB->MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;

while(1)
{
	//*Toggle on all LEDS*/
	//GPIOB_ODR_R |= USER_LED1 | USER_LED2 | USER_LED3;

	//*Turn on/off all LEDS*/
	//GPIOB_ODR_R ^= USER_LED1 | USER_LED2 | USER_LED3;
	GPIOB->ODR ^= USER_LED1 | USER_LED2 | USER_LED3;
	for(int i = 0;i<1000000;i++){}
}

}
