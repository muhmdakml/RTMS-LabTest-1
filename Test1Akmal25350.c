//Muhammad Akmal Bin Mohd Adzuddin
//25350
//Test 1 Set 1

#include <stdio.h>																											 
#include "NUC1xx.h"
#include "SYS.h"
#include "Seven_Segment.h"
#include "GPIO.h"
#include "Scankey.h"

// display an integer on four 7-segment LEDs
void seg_display(int16_t value,int16_t rotate)
{
	int8_t digit;
	int32_t dly;
	int32_t s;
	
	OpenKeyPad();
	s = ScanKey();
	
	switch (s)
	{	
	case 1:
			dly = dly + 1000;
			break;	
		case 0:
			dly = 5000;
			break;	
	case 7:
			dly = dly - 1000;
			break;
	}
	
	digit = value / 1000;
	close_seven_segment();
	show_seven_segment(2,digit);
	DrvSYS_Delay(dly);
			
	value = value - digit * 1000;
	digit = value / 100;
	close_seven_segment();
	show_seven_segment(1,digit);
	DrvSYS_Delay(dly);
	
	value = value - digit * 100;
	digit = value / 10;
	close_seven_segment();
	show_seven_segment(0,digit);
	DrvSYS_Delay(dly);

	
	close_seven_segment();
	show_seven_segment_rotation(3,rotate);
	DrvSYS_Delay(dly);
	

}

int32_t main (void)
{
	uint32_t i=0;
	uint32_t r=7;
	UNLOCKREG();           // Unlock System Registers
	DrvSYS_Open(48000000); // set CPU clock to 25~50MHz
	LOCKREG();	           // Lock System Registers


  DrvSYS_Delay(1000);		
 	while(1) 
	{
	  seg_display(i,r);		// display i on 7-segment display	
		i++;
		r--;
		if (r<0) r=7;
		
		if (i>1010) i=0;
	}

}