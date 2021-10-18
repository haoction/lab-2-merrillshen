#include <xc.h>
#include "LEDarray.h"

/************************************
/ LEDarray_init
/ Function used to initialise pins to drive the LEDarray
************************************/
void LEDarray_init(void)
{   
    //set up TRIS registers for pins connected to LED array
    //set initial output LAT values (they may have random values when powered on)
    
    LATGbits.LATG0=0;   //set initial output state
    TRISGbits.TRISG0=0;
    
    LATGbits.LATG1=0;   //set initial output state
    TRISGbits.TRISG1=0;

    LATAbits.LATA2=0;   //set initial output state
    TRISAbits.TRISA2=0;	
	
    LATFbits.LATF6=0;   //set initial output state
    TRISFbits.TRISF6=0;
    
    LATAbits.LATA4=0;   //set initial output state
    TRISAbits.TRISA4=0;	
    
    LATAbits.LATA5=0;   //set initial output state
    TRISAbits.TRISA5=0;	
    
    LATFbits.LATF0=0;   //set initial output state
    TRISFbits.TRISF0=0;
    
    LATBbits.LATB0=0;   //set initial output state
    TRISBbits.TRISB0=0;
    
    LATBbits.LATB1=0;   //set initial output state
    TRISBbits.TRISB1=0;
}

/************************************
/ LEDarray_disp_bin
/ Function used to display a number on the LED array in binary
************************************/
void LEDarray_disp_bin(unsigned int number)
{
	//some code to turn on/off the pins connected to the LED array
	//if statements and bit masks can be used to determine if a particular pin should be on/off
	//see Readme.md for examples
    if (number & 0b00000000) { LATGbits.LATG0=1;}  //0
    if (number & 0b00000001) { LATGbits.LATG1=1;}  //1
    if (number & 0b00000010) { LATAbits.LATA2=1;}  //2
    if (number & 0b00000100) { LATFbits.LATF6=1;}  //4
    if (number & 0b00001000) { LATAbits.LATA4=1;}  //8
    if (number & 0b00010000) { LATAbits.LATA5=1;}  //16
    if (number & 0b00100000) { LATFbits.LATF0=1;}  //32
    if (number & 0b01000000) { LATBbits.LATB0=1;}  //64
    if (number & 0b10000000) { LATBbits.LATB1=1;}  //128
}

void buttonpress_init(void)
{  
    // setup pin for input (connected to left button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin 
}

/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(unsigned int number)
{
	unsigned int disp_val;
	disp_val = 0;
	//some code to manipulate the variable number into the correct
	//format and store in disp_val for display on the LED array
    if (number > 9)  { disp_val += 1;} 
    if (number > 19) { disp_val += 2;}
    if (number > 29) { disp_val += 4;} 
    if (number > 39) { disp_val += 8;}
    if (number > 49) { disp_val += 16;} 
    if (number > 59) { disp_val += 32;} 
    if (number > 69) { disp_val += 64;} 
    if (number > 79) { disp_val += 128;} 
	LEDarray_disp_bin(disp_val); 	//display value on LED array
}


/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
void LEDarray_disp_PPM(unsigned int cur_val, unsigned int max)
{
	unsigned int disp_val;
	
	// some code to format the variable cur_val and max, store in disp_val for display on the LED array
	// hint: one method is to manipulate the variables separately and then combine them using the bitwise OR operator

	LEDarray_disp_bin(disp_val);	//display value on LED array
}

