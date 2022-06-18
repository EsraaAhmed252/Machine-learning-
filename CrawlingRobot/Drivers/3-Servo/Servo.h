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
#define SERVOA SETBIT();
#define SERVOB SETBIT();
#define MAX_SIZE 65535


#endif /* SERVO_H_ */