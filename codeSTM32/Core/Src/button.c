/*
 * button.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Hii
 */

#ifndef SRC_BUTTON_C_
#define SRC_BUTTON_C_

#include "button.h"
int button_flag[NUM_BUTTONS] = {0};
int buttonLongPress_flag[NUM_BUTTONS] = {0};

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTONS] = {0};

int isButtonPressed(int index){
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int index){
	button_flag[index] = 1;
}
void getKeyInput(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if (i == 0){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					if (buttonLongPress_flag[i] == 0) {
						TimeOutForKeyPress[i] = 2000;
					}
					else {
						TimeOutForKeyPress[i] = 250;
					}
				}
			}
			else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
					buttonLongPress_flag[i] = 1;
				}
			}
		}
		else{
			buttonLongPress_flag[i] = 0;
		}
	}
}

#endif /* SRC_BUTTON_C_ */
