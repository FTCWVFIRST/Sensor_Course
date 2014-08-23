#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)


//Move Forward
void moveForward (int move)
{
	move = move*200; // find conversion:    ? encoder counts = 1 cm  (200 used as place holder)

	nMotorEncoder[motorE] = 0;  //Clear the TETRIX encoders in motors D and E.
  nMotorEncoder[motorD] = 0;	//Robot should be at a complete stop before encoder reset.

	while (nMotorEncoder[motorE] < move-200){ // Motors slowdown 200/4 = 50 degrees from stop position (Can be adjusted for either accuracy or speed)
	motor[motorE] = 50;
	motor[motorD] = 50;
}
	while (nMotorEncoder[motorE] < move){ //Motors move at 10 percent power right before end of movement to improve accuracy.
																				//Motor power can be used this low because of close loop PID control indicated in #pragma statement.
	motor[motorE] = 10;
	motor[motorD] = 10;
}																			//Stop Motors
	motor[motorE] = 0;
	motor[motorD] = 0;
	wait1Msec(200);									//Wait 2/10ths of a second to allow robot to reach a complete stop.
}

//Right Point Turn
void rightTurn ()
{

	nMotorEncoder[motorE] = 0;  //Clear the TETRIX encoders in motors D and E.
  nMotorEncoder[motorD] = 0;	//Robot should be at a complete stop before encoder reset.

while (nMotorEncoder[motorE]<1000){			//Robot value for right point turn.  Default value(1000).
																				//Value will change to account for changes in:
																				//1.Wheelbase
																				//2.Wheelsize
																				//3.Floor Friction
																				//4.Power Level
	motor[motorD]=-20;
	motor[motorE]=20;
  }
  motor[motorD]=0;
  motor[motorE]=0;
	wait1Msec(200);
}
//Left Point Turn
void leftTurn ()
{

	nMotorEncoder[motorE] = 0;  //Clear the TETRIX encoders in motors D and E.
  nMotorEncoder[motorD] = 0;	//Robot should be at a complete stop before encoder reset.

while (nMotorEncoder[motorE]>-1000){			//Robot value for left point turn.  Default value(-1000).
																				//Value will change to account for changes in:
																				//1.Wheelbase
																				//2.Wheelsize
																				//3.Floor Friction
																				//4.Power Level
	motor[motorD]=20;
	motor[motorE]=-20;
  }
  motor[motorD]=0;
  motor[motorE]=0;
	wait1Msec(200);
}
