/*
 * button.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Hii
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NUM_BUTTONS 1

int isButtonPressed(int index);
void getKeyInput();


#endif /* INC_BUTTON_H_ */
