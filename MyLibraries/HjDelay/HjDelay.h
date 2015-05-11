/* ----------------------------------------------------------------------------
library name :delay.h - by this library you can work with lpcxxxx family  without
any long statment .
-------------------------------------------------------------------------------------*/
//TODO : Use SysTick for exact milliseconds delay   [ included in append ]
//presentation Header file

#ifndef _DELAY_INCLUDED_
#define _DELAY_INCLUDED_
//-------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//presentation subs ( we have three sub 1- delay_us 2- delay_ms 3- delay_s

void delay_us(unsigned long a);
void delay_ms(unsigned long b);
void delay_s(unsigned long c);
//------------------------------------------------------------------------------------------
// sub delay_us 

#endif

//
///*volatile uint32_t msTicks;	/* counts 1ms timeTicks */
//
//void SysTick_Handler(void)
//{
//	msTicks++;	/* increment counter necessary in Delay() */
//}
//
//__inline static void _delay_ms(uint32_t del)
//{
//	uint32_t curTicks;
//	curTicks = msTicks;
//
//	while ((msTicks - curTicks) < del)
//	{
//		__WFI();
//	}
//}
//
//void setSYSTICK(void)		// Setup Systick!
//{
//	if (SysTick_Config(SystemCoreClock / 100))
//	{ 							/* Setup SysTick Timer for 1 msec interrupts  */
//		while (1);                                  /* Capture error */
//	}
//
//	if ( !(SysTick->CTRL & (1<SYSTICKCLKDIV = 0x08;
//	}
//}
//
//int main(void)
//{
//    SystemInit();
//    setSYSTICK();
//
// 	LPC_PMU->PCON |= (1<<11);
//	SCB->SCR &= ~(1<<2);
//
//	while(1)
//	{
//		_delay_ms(100);
//                //Do Something
//	}
//	return 0 ;
//}
///*  SysTick Sample
//// * volatile uint32_t msTicks;	/* counts 1ms timeTicks */
////
////void SysTick_Handler(void)
////{
////	msTicks++;	/* increment counter necessary in Delay() */
////}
////
////__inline static void _delay_ms(uint32_t del)
////{
////	uint32_t curTicks;
////	curTicks = msTicks;
////
////	while ((msTicks - curTicks) < del)
////	{
////		__WFI();
////	}
////}
////
////void setSYSTICK(void)		// Setup Systick!
////{
////	if (SysTick_Config(SystemCoreClock / 100))
////	{ 							/* Setup SysTick Timer for 1 msec interrupts  */
////		while (1);                                  /* Capture error */
////	}
////
////	if ( !(SysTick->CTRL & (1<SYSTICKCLKDIV = 0x08;
////	}
////}
////
////int main(void)
////{
////    SystemInit();
////    setSYSTICK();
////
//// 	LPC_PMU->PCON |= (1<<11);
////	SCB->SCR &= ~(1<<2);
////
////	while(1)
////	{
////		_delay_ms(100);
////                //Do Something
////	}
////	return 0 ;
////}
//// */
