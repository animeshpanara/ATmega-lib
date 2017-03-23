#include "Rhino.h"
#define baudset 51

	void Init(int x)
	{	
		USART_Init(baudset,x);
		USART_Init(baudset,!x);
		USART_Transmitchar('P',x);
		USART_Transmitchar('0',x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
			USART_TransmitString("Motor Initiated!",!x);
	}
	void Reset(int x)
	{
		
		USART_Transmitchar('Y',x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
			USART_TransmitString("Motor Initiated!",!x);	
	}
	void AutoCalibrate(int x)
	{
		USART_Transmitchar('X',x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
			USART_TransmitString("AUTO calibration!",!x);	
	}
	void setSpeed(int speed1,int x)
	{
		if(speed1>255) 
		speed1=255;
		else if(speed1<0) 
		speed1=0;
		USART_Transmitchar('M',x);
		USART_TransmitNumber(speed1,x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
		{
			USART_TransmitString("speed set",!x);
			USART_TransmitNumber(speed1,!x);
		}
	}
	void rotatewithspeed(int speed1,int x)
	{
		if(speed1>255)
		speed1=255;
		else if(speed1<-255)
		speed1=-255;
		USART_Transmitchar('S',x);
		USART_TransmitNumber(speed1,x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
		{
			USART_TransmitString("speed set",!x);
			USART_TransmitNumber(speed1,!x);
		}
	}
	void stopMotor(int x)
	{
		USART_Transmitchar('S',x);
		USART_Transmitchar('0',x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
			USART_TransmitString("Motor Stopped!",!x);
	}
	void gotoAngleDeg(float angle1,int x)
	{
		angle1 *= 5;
		
		int angle2 = (int)angle1;
		USART_Transmitchar('G',x);
		USART_TransmitNumber(angle2,x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
		{
			USART_TransmitString("go to angle",!x);
			USART_TransmitNumber(angle2/5,!x);
		}
		
	}
	void gotoRelDeg(float pos1,int x)
	{
        pos1 = pos1*5;
		int pos2 = (int)pos1;
		USART_Transmitchar('R',x);
		USART_TransmitNumber(pos2,x);
		USART_Transmitchar('\r',x);
		if(x==0||x==1)
		{
			USART_TransmitString("go to angle",!x);
			USART_TransmitNumber(pos1/5,!x);
		}
    }
