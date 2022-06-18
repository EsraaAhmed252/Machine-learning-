/*
 * header.h
 *
 * Created: 6/18/2022 5:33:51 PM
 *  Author: esraa
 */ 


#ifndef HEADER_H_
#define HEADER_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000
#include <util/delay.h>

#define SETBIT(REG,BIT) REG|= 1<<BIT
#define CLRBIT(REG,BIT) REG&= ~(1<<BIT)
#define TOGBIT(REG,BIT) REG^= 1<<BIT
#define GETBIT(REG,BIT) ((REG>>BIT) & 1)


#endif /* HEADER_H_ */