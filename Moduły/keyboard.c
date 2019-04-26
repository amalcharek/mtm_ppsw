#include <LPC21xx.H>
#include "keyboard.h"

#define BUTT1_bm (1<<4)
#define BUTT2_bm (1<<5)
#define BUTT3_bm (1<<6)
#define BUTT4_bm (1<<7)

void KeyboardInit(){
	IO0DIR = IO0DIR & ~(BUTT1_bm | BUTT2_bm | BUTT3_bm | BUTT4_bm);
}

enum KeyboardState eKeyboardRead(){
	if(BUTT1_bm != (IO0PIN & BUTT1_bm)){
		return BUTTON_1;
	}
	else if(BUTT2_bm != (IO0PIN & BUTT2_bm)){
		return BUTTON_2;
	}
	else if(BUTT3_bm != (IO0PIN & BUTT3_bm)){
		return BUTTON_3;
	}
	else if(BUTT4_bm != (IO0PIN & BUTT4_bm)){
		return BUTTON_4;
	}
	else{
		return RELASED;
	}
}
