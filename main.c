#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "ADC.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	unsigned int count=0;
    unsigned int max=0;
    unsigned int cur_val=0;
    LEDarray_init();
    ADC_init();
    while (1) {
        cur_val = ADC_getval();
        if (cur_val >= max) { max=cur_val;}  
        max -= 10;
        count++;
        LEDarray_disp_PPM(cur_val,max);
		__delay_ms(100); // Delay 
    }
}
