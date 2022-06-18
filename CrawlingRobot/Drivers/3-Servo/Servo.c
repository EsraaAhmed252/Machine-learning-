/*
 * Timer1.c
 *
 * Created: 6/18/2022 5:33:04 PM
 *  Author: esraa
 */ 
#include "Servo.h"
void timer1_PWM_init(){
	SETBIT(PORTD,5);
	OCR1AH = 0;
	OCR1AL = 0;
	TCCR1A = 0XA1;//0b10100001
	TCCR1B = 1<<CS10;
}

void servo_init(){
	SERVOA
	SERVOB
}

void servoA_write(uint8_t angle){
	//a=1.8duty Cycle
	uint16_t value = (0.55angle * MAX_SIZE);
	OCR1AL = (uint8_t)value;
	OCR1AH = (uint8_t)(value>>8);
	_delay_ms(1000);
}

void servoB_write(uint8_t angle){
	//a=1.8duty Cycle
	uint16_t value = (0.55angle * MAX_SIZE);
	OCR1BL = (uint8_t)value;
	OCR1BH = (uint8_t)(value>>8);
	_delay_ms(1000);
}



