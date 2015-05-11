//presentation variable
#include "system_lpc17xx.h"
//unsigned long crystal=100000000;  // for other crystal change 100000000
unsigned long x;
unsigned long y;
void delay_us(unsigned long a)
{
	do{
		unsigned long d=0;
		x=SystemCoreClock/8160000;
		for (d=0;d<x;d++);		 //start the VALUE off d is 0 ,  increase  d ,
								 //if d > x goto next line ,else (d<x) increase d
		y++;  					 // increase y
	} while(y<a); 				 //if y > a goto next line ,else (y<a) goto "do{"
	y=0;
}
					//in mine program , you write "delay_s(4);" . in this Header "a" is 4 & do-while
					//loop repeat 4 ---time = (x*5)/ crystal
//--------------------------------------------------------------------------------
// sub delay_ms

void delay_ms(unsigned long b)
{
	do{
		unsigned long e=0;
		x=SystemCoreClock/8160;
		for (e=0;e<x;e++);
		y++;
	} while(y<b);
	y=0;
}
//---------------------------------------------------------------------------------
// sub delay_s

void delay_s(unsigned long c)
{
	c=c*1000;
	do{
		unsigned long f=0;

		x=SystemCoreClock/8160;
		for (f=0;f<x;f++);
		y++;
	} while(y<c);
	y=0;
}
