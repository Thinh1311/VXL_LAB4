/*
 * software_timer.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Hii
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int TIMER_CYCLE;
extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timer_run();
void clearTimer(int timer_index);

#endif /* INC_SOFTWARE_TIMER_H_ */
