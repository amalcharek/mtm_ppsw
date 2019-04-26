#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define Butt1_bm 0x00000010
#define Butt2_bm 0x00000020
#define Butt3_bm 0x00000040
#define Butt4_bm 0x00000080

void Delay(int iTime){
	unsigned int iDelayCounter;
	iTime = (12000*iTime);
	for(iDelayCounter = 0; iDelayCounter < iTime; iDelayCounter++){}
}

void Led_Init(){
	IO1DIR = (IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
}

void Led_On(unsigned char ucLedIndeks){
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
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
		default:
			break;
	}
}

enum KeyboardState {RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4};

enum KeyboardState eKeyboard_Read(){
	if((0==(IO0PIN & Butt1_bm))){
		return BUTTON_1;
	} 
	else if((0==(IO0PIN & Butt2_bm))){
		return BUTTON_2;
	} 
	else if((0==(IO0PIN & Butt3_bm))){
		return BUTTON_3;
	}
	else if((0==(IO0PIN & Butt4_bm))){
		return BUTTON_4;
	} 
	else {
		return RELASED;
	}
}

void ButtonInit(){
	IO0DIR = (IO0DIR & (~(Butt1_bm | Butt2_bm | Butt3_bm | Butt4_bm)));
}

enum StepDirection {LEFT, RIGHT};

void Led_Step(enum StepDirection eDirection){
	static unsigned int uiPozycjaPunktu;
	switch(eDirection){
		case LEFT:
			uiPozycjaPunktu = (++uiPozycjaPunktu) % 4;
			break;
		case RIGHT:
			uiPozycjaPunktu = (--uiPozycjaPunktu) % 4;
			break;
		default:
			break;
	}
	Led_On(uiPozycjaPunktu);
}

void Led_StepLeft(){
	Led_Step(LEFT);
}

void Led_StepRight(){
	Led_Step(RIGHT);
}
			

int main(){
	/*unsigned char ucLicznik; */
	
	Led_Init();
	ButtonInit();

	while(1){
			
		/*Led_On(0);
		Delay(250);
		Led_On(1);
		Delay(250);
    Led_On(2);
		Delay(250);
		Led_On(3);
		Delay(250); */
			
		/*switch(eKeyboard_Read()){
			case RELASED:
				Led_On(5);
				break;
			case BUTTON_1:
				Led_On(1);
				break;
			case BUTTON_2:
				Led_On(2);
				break;
			case BUTTON_3:
				Led_On(3);
				break;
			case BUTTON_4:
				Led_On(4);
				break;
		} */
		
		/*for(ucLicznik=0; ucLicznik<9; ucLicznik++){
				Delay(500);
				Led_Step(Left);
			}
			for(ucLicznik=0; ucLicznik<9; ucLicznik++){
				Delay(500);
				Led_Step(Right);
			} */
			
		switch(eKeyboard_Read()){
			case RELASED:
				break;
			case BUTTON_1:
				Delay(250);
				Led_StepRight();
				break;
			case BUTTON_2:
				Delay(250);
				Led_StepLeft();
				break;
			default:
				break;
		}
	}
}  
