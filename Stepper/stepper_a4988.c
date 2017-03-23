#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "stepper_a4988.h"
#include <math.h>
//stepper can be set up in various modes-
//full step mode,half step mode,quarter step mode,eighth step mode,sixteenth step mode
//stepper motor direction  pin can be set up in clockwise as well as in anticlockwise
void stepper_stepset();
void delay_micro(int x);
void full_step();
void half_step();
void quarter_step();
void eighth_step();
void sixteenth_step();
int step_factor = 1;//global variable
int absolute_angle = 0;
void delay_micro(int x){
	while(x--){
		_delay_us(1);
	}
}

void stepper_setup(int mode){
	stepper_dir = (1 << dir_pin) | (1 << step_pin) | (1 << ms1) | (1 << ms2) | (1 << ms3);
	int num;
	num = mode;
	switch(num){
		case 1:
		full_step();
		step_factor=1;
		break;
		case 2:
		half_step();
		step_factor=2;
		break;
		case 3:
		quarter_step();
		step_factor=4;
		break;
		case 4:
		eighth_step();
		step_factor=8;
		break;
		case 5:
		sixteenth_step();
		step_factor=16;
		break; 
	}
}
void stepper_set_rel_angle(int data){
	int angle;
	int i,steps;
	angle = data;
	steps = (int)((abs(angle) / (1.8)) * step_factor);
	if(angle>0){
		stepper_port |= (1 << dir_pin);//for let clockwise +360
		for(i = 0;i < steps;i++){
			stepper_stepset();
		}
	}
	else{
		stepper_port &=~ (1 << dir_pin);//for let anticlockwise -360
		for(i = 0;i < steps;i++){
			stepper_stepset();
		}
	}
}
void stepper_set_abs_angle(int data){
	int angle;
	angle = data - absolute_angle;	
	absolute_angle = data;
	stepper_set_rel_angle(angle);
}
void stepper_reset(){
	absolute_angle=0;
}
void stepper_stepset(){
	stepper_port |= (1<<step_pin);
	delay_micro(500);
	stepper_port &=~ (1<<step_pin);
	delay_micro(500);
}
void full_step(){
	stepper_port &=~ ((1<<ms1)|(1<<ms2)|(1<<ms3));
}
void half_step(){
	stepper_port |= (1<<ms1);
	stepper_port &=~ ((1<<ms3)|(1<<ms2));
}
void quarter_step(){
	stepper_port &=~ (1<<ms1)|(1<<ms3);
	stepper_port |= (1<<ms2);
}
void eighth_step(){
	stepper_port |= (1<<ms1)|(1<<ms2);
	stepper_port &=~ (1<<ms3);
}
void sixteenth_step(){
	stepper_port |= (1<<ms1)|(1<<ms2)|(1<<ms3);
}
void stepper_check()
{
	for(int i=1;i<=5;i++)
	{
		stepper_setup(3);
		for(int j=0;j<=360;j+=30)
		{
			stepper_set_abs_angle(j);
			_delay_ms(2000);
		}
	}
}