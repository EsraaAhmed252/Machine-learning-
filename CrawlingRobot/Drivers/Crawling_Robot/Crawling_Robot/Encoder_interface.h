#ifndef ENCODER_INTERFACE_H
#define ENCODER_INTERFACE_H


#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define INT0	6
#define INT1	7
#define INT2	5

#define LOW 0
#define CHANGE  1
#define FALLING 2
#define RISING  3


// Function to set the external interrupt 0
u8 SetInterrupt0(u8 Mode);

// Function to set external interrupt 1
u8 SetInterrupt1(u8 Mode);

#endif
