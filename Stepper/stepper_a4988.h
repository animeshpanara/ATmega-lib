#ifndef stepper_a4988
#define stepper_a4988
#include <avr/io.h>
#include <util/delay.h>

#define stepper_dir DDRD
#define stepper_port PORTD
#define dir_pin PIND0
#define step_pin PIND1
#define ms1 PIND2
#define ms2 PIND3
#define ms3 PIND4
#define FULLSTEP 1
#define HALFSTEP 2
#define QUARTERSTEP 3
#define EIGHTHSTEP 4
#define SIXTEENTHSTEP 5

void stepper_setup(int mode);
void stepper_set_rel_angle(int data);
void stepper_set_abs_angle(int data);
void delay_micro(int x);
void stepper_check();
void stepper_reset();

#endif