/*
 * Crawling_Robot.c
 *
 * Created: 6/18/2022 5:32:41 PM
 * Author : Esraa
 */ 
#define outputA ((PIND >> 2) & 1)
#define outputB ((PIND >> 3) & 1)
#include "header.h"
#include "Servo.h"
#include "DIO_interface.h"
#include "Encoder_interface.h"
#include <stdlib.h>
/*
Machine learning crawling Robot Reinforcement Learning Unsupervised - Version 1
by: jim demello
Edited by :
1-
2-
3-
4-
5-
*/

// Servo setup:  the servos must be oriented so that if the arm is rotating counter-clockwise to the left of the servo, then up is 0 degrees
//               and down is 180 degrees, for both servos. Then when the arm is in it's highest postion, servo 1 (the servo closest to the
//               body of the robot, will be at 0 degrees and servo 2 will be at 40 degrees.)
// Sonar:        the ultrasonic module should be placed facing the rear of the robot as it measures movement of the robot away from some
//               solid structure like a wall.
// TODO:         1. smooth servo arm movements (simultaneous moves) - done
//               2. lower servo starting positions
//               3. try for 3 positions in success table
//               4. try using wheel encoder rather than ultrasonic module for greater precision and so that robot does not have to
//               measure distance from another object.
// algorithm:    this is a positive reinforcement (perhaps a simple greedy epsilon algorithm) unsupervised learning algorithm
//               It chooses a random state (arm position) for the first position then the second time in the loop randomly gets the second arm position
//               and then moves the arm from the first to the second position, gets distance moved and then if it is greater than
//               2cms, it stores these two arm movements in the successes table array.
//               When it has looped through the episodes number of cycles, it loops through the successes table to find the highest distance moved.
//               Then it just cycles back and forth through those two arm movements.
// improvements to algorithm: sometimes using just two arm positions is too little to produce much movement (although sometimes it is reallly good)
//                            so could change successes table to store 3 arm movements and then I think it would produce greater movement each time.

uint16_t counter = 0;
int state;
int success[5] = {};
int spos1;
int spos2;
int spos3;
int spos4;
int pos[16][2]={  
{ 0,40}, // column 1 holds servo1 positions and column 2 holds servo 2 positions
{ 0,85},
{ 0,130},
{ 0,175},
{ 30,40},
{ 30,85},
{ 30,130},
{ 30,175},
{ 60,40},
{ 60,85},
{ 60,130},
{ 60,175},
{ 90,40},
{ 90,85},
{ 90,130},
{ 90,175}};

void doTraining() {
	for(int i=0; i<5; i++)
		success[i]=0;

	for (int episode=0;episode<20;episode++) // no. of episodes
	{
		counter = 0;
		state = rand()%16;
		spos1 = pos[state][0];
		spos2 = pos[state][1];
		
		state = rand()%16;
		spos3 = pos[state][0];
		spos4 = pos[state][1];
		
		//Instead of waiting for each servo individually. move them simultaneously then wait before moving them again
		servoA_write(spos1);
		servoB_write(spos2);
		
		servoA_write(spos3);
		servoB_write(spos4);
		
		servoA_write(0);
		servoB_write(0);
		if ( counter >= success[4]) { // if moved forward 2 or more centimeters
			success[0] = spos1; // servo position 1
			success[1] = spos2; // servo position 2
			success[2] = spos3; // servo position 1
			success[3] = spos4; // servo position 2
			success[4] = counter; // store distance
		}
	}  // end each episode
} // end doTraining

void doLearnedBehavior() {
	servoA_write(0);
	servoB_write(0);
	
	spos1 = success[0];
	spos2 = success[1];
	spos3 = success[2];
	spos4 = success[3];
	cli();
	for (int i=0;i<10;i++) {
		
		servoA_write(spos1);
		servoB_write(spos2);
		
		servoA_write(spos3);
		servoB_write(spos4);
		
	}
	sei();
}


int main (){
	timer1_PWM_init();
	servo_init();
	_delay_ms(1000);
	SetInterrupt0(CHANGE);
	sei();
	while(1){
		doTraining();     // trial and error training with distance reinforcement
		_delay_ms(5000);
		doLearnedBehavior();
		/**Ending behaviour**/
		servoA_write(0); //return to starting position for servo 1
		servoB_write(0); //return to starting position for servo 2
		_delay_ms(5000);
	}
	return 0;
} // end setup


ISR(INT0_vect)
{
	if (outputB != outputA)
		counter ++;
	else counter --;
	
	
}