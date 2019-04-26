#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iMiliSecondValue){
	
	long i;
	long End;
	End=iMiliSecondValue*12000;
	for(i=0; i<End; i++){
	}
}	

int main(){
	
	LedInit();
	KeyboardInit();
	

	while(1){
		switch (eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			default: break;
		}
		//Delay(500);
	}
}
