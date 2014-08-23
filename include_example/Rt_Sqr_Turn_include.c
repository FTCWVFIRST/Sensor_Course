#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Sensor, S2,     eStopSwitch,    sensorTouch)
//#Pragma statements must be in main file not #pragma Statements

#include "CalMove.c"
//CalMove.c contains calibrated movement for the robot in fuctions: moveForward, rightTurn, and leftTurn
#include "eStop.c"
//eStop.c contains simple emergency stop task with slight delay to processing overhead



task main()		//Starts first task, task main()
{
	StartTask (emergencyStop); 	//Starts second task emergencyStop
	while(1==1)
		{
		moveForward(15);
		rightTurn();
	}
}
