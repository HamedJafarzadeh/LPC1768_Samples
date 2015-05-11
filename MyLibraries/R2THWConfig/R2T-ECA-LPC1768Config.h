#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#ifndef  _R2T_ECA_LPC1768Config_H_
#define  _R2T_ECA_LPC1768Config_H_


//#define LEDPORT    							2
//
//#define LED1PIN    							0
//#define LED2PIN    							1
//#define LED3PIN    							2
#define LED4PIN    							3
#define LED5PIN    							4
#define LED6PIN    							5
#define LED7PIN    							6
#define LED8PIN            					7

#define SWPORT2  							2

#define SW21PIN                              10
#define SW22PIN                              11
#define SW23PIN                              12
#define SW24PIN                              13

#define SWPORT1   						   	1

#define SW15PIN                             29
#define SW16PIN                             28
#define SW17PIN                             27
#define SW18PIN                             13

//######### Simplified Read and Write port functions , probably not suitable for fast works with high frequency , use Standard methods instead
// Todo : make function of these declarations
#define ReadPORT(PORTName,PINNumber)       (((GPIO_ReadValue(PORTName) & 1<<PINNumber)>>PINNumber)? 1 : 0)
#define WritePORT(PORTName,PINNumber,val)  (val? GPIO_SetValue(PORTName,1<<PINNumber) : GPIO_ClearValue(PORTName,1<<PINNumber) )
#define TogglePORT(PORTName,PINNumber)    WritePORT(PORTName,PINNumber,!ReadPORT(PORTName,PINNumber))

void ECALPC1768Init()
{
   PINSEL_CFG_Type PINSELConfig;
   SystemInit();


   GPIO_SetDir(LEDPORT,(1<<LED1PIN)|(1<<LED2PIN)|(1<<LED3PIN)|(1<<LED4PIN)|(1<<LED5PIN)|(1<<LED6PIN)|(1<<LED7PIN)|(1<<LED8PIN),1); //Set LED Pins as Output
   //Config Switches on PORT 2 , default IOsate is input
   PINSELConfig.Portnum = SWPORT2;
   PINSELConfig.Pinnum = SW21PIN;
   PINSELConfig.Pinmode = PINSEL_PINMODE_PULLUP;
   PINSELConfig.Funcnum = 0; // General GPIO
   PINSEL_ConfigPin(&PINSELConfig);
   PINSELConfig.Pinnum = SW22PIN;
   PINSEL_ConfigPin(&PINSELConfig);
   PINSELConfig.Pinnum = SW23PIN;
   PINSEL_ConfigPin(&PINSELConfig);
   PINSELConfig.Pinnum = SW24PIN;
   PINSEL_ConfigPin(&PINSELConfig);
   //Config Switches on PORT 1, default IOState is input
   PINSELConfig.Portnum = SWPORT1;
   PINSELConfig.Pinnum = SW15PIN;
   PINSEL_ConfigPin(&PINSELConfig);
   PINSELConfig.Pinnum = SW16PIN;
   PINSEL_ConfigPin(&PINSELConfig);
   PINSELConfig.Pinnum = SW17PIN;
   PINSEL_ConfigPin(&PINSELConfig);


}

void ECALPCGPIODemo()
{
	WritePORT(LEDPORT,LED1PIN,ReadPORT(SWPORT2,SW21PIN));
	WritePORT(LEDPORT,LED2PIN,ReadPORT(SWPORT2,SW22PIN));
	WritePORT(LEDPORT,LED3PIN,ReadPORT(SWPORT2,SW23PIN));
	WritePORT(LEDPORT,LED4PIN,ReadPORT(SWPORT2,SW24PIN));
	WritePORT(LEDPORT,LED5PIN,ReadPORT(SWPORT1,SW15PIN));
	WritePORT(LEDPORT,LED6PIN,ReadPORT(SWPORT1,SW16PIN));
	WritePORT(LEDPORT,LED7PIN,ReadPORT(SWPORT1,SW17PIN));
}


#endif
