
#pragma autoStartTasks        // Automatically start this task when the main user program starts.

task emergencyStop()				//Button that will save your bacon if your robot goes on a Robo Rampage.

{
	while(SensorValue(eStopSwitch)==0)  //Reads the touch sensor value 1 is pressed 0 is the opposite of pressed.
																			//Make sure sensor name 'eStopSwitch' is contrained in #Pragma statments, if not change it in Motor and Sensor Setup.
	{
		wait1Msec(10);				//Limits processor power used by only updating every 1/100th of a second.
	}
	StopAllTasks();					//Robot Stops
}
