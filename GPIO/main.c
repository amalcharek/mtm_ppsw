#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define BUTT0_bm 0x00000010
#define BUTT2_bm 0x00000020
#define BUTT1_bm 0x00000040
#define BUTT3_bm 0x00000080

void Delay(int DelayTime){
	int TimeScale=12000;
	int i;
	int Iterations=TimeScale*DelayTime;
	for(i=0;i<Iterations;i++){
	}
}

void LedInit(){
	IO1DIR =(IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR =(LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
				break;
		case 1:
			IO1SET = LED1_bm;
				break;
		case 2:
			IO1SET = LED2_bm;
				break;
		case 3:
			IO1SET = LED3_bm;
				break;
	}
}

enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(){
	
	if((IO0PIN&BUTT0_bm) == 0){
		return BUTTON_0;
	}

	if((IO0PIN&BUTT1_bm) == 0){
		return BUTTON_1;
	}
	
	if((IO0PIN&BUTT2_bm) == 0){
		return BUTTON_2;
	}
	
	if((IO0PIN&BUTT3_bm) == 0){
		return BUTTON_3;
	}
	
		return RELEASED;
}

void KeyboardInit(){
	IO0DIR = ~(~IO0DIR | BUTT0_bm | BUTT1_bm | BUTT2_bm | BUTT3_bm);
}


enum Direction {LEFT, RIGHT};

void LedStep(enum Direction eDir){
	
	static unsigned int uiDiodeNumber=0;
	
	if(eDir == LEFT){
		uiDiodeNumber++;
	}
	else{
		uiDiodeNumber--;
	}
	LedOn(uiDiodeNumber%4);
	
}

void LedStepLeft(){
	LedStep(LEFT);
}

void LedStepRight(){
	LedStep(RIGHT);
}


int main(){
	
	KeyboardInit();
	LedInit();
	
	while(1){
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStep(RIGHT);
				break;
			
			case BUTTON_2:
				LedStep(LEFT);
				break;
			
			default:
				break;
		}
		Delay(100);
	}
	
}

