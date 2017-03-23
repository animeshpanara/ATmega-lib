#ifndef Rhino
#define Rhino
#include "USART_128.h"
void Init(int x);
void Reset(int x);
void AutoCalibrate(int x);
void rotatewithspeed(int speed1,int x);
void stopMotor(int x);
void gotoAngleDeg(float angle1,int x);
void gotoRelDeg(float pos1,int x);
void setSpeed(int speed1,int x);
#endif // Rhino
