/*
 * Timer1.h
 *
 * Created: 6/18/2022 5:33:29 PM
 *  Author: esraa
 */ 


#ifndef SERVO_H_	
#define SERVO_H_
#include "header.h"
void timer1_PWM_init();
void servo_init();
void servoA_write(uint8_t);
void servoB_write(uint8_t);
#define SERVO_A SETBIT(DDRD,4);
#define SERVO_B SETBIT(DDRD,5);
#define MAX_SIZE 65535


#endif /* SERVO_H_ */