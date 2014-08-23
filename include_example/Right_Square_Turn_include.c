#pragma config(Sensor, S2,     eStopSwitch,    sensorTouch)
//#Pragma statement included in main program code because RobotC would not associate the correct datatype
//to the variable named "eStopSwitch" when called from the included eStop.c file.
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
