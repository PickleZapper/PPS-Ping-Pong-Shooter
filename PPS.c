#pragma config(Sensor, in1,    firingAngle,    sensorPotentiometer)
#pragma config(Sensor, in2,    firingAngleInput, sensorPotentiometer)
#pragma config(Sensor, dgtl3,  firingSwitch,   sensorTouch)
#pragma config(Motor,  port2,           elevationMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           firingMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ballPusher,   tmotorServoStandard, openLoop)


/*
revisions:
	sensor configurations for elevation up and down bumpers, ball detector, and elevation trigger have been removed
		(however the firing switch remains in port 3)
	elevation up and down bumper control code has been removed
	rearranged firing angle movement code slightly
	
	delete this section after further revisions
*/
task main()
{
	while(true)
	{
		setServo(ballPusher,-127);
		while(abs(SensorValue(firingAngle)-SensorValue(firingAngleInput)/4) > 20){

			int angleInput = SensorValue(firingAngleInput)/4;
			if(SensorValue(firingAngle) < angleInput - 50)
				startMotor(elevationMotor, 127);
				
			if(SensorValue(firingAngle) < angleInput)
				startMotor(elevationMotor, 25);
				
			if(SensorValue(firingAngle) > angleInput + 50)
				startMotor(elevationMotor, -80);

			if(SensorValue(firingAngle) > angleInput)
				startMotor(elevationMotor, -15);
		}
		stopMotor(elevationMotor);

		while(SensorValue(firingSwitch) == 1){
			startMotor(firingMotor, 127);
			wait(2);
			setServo(ballPusher, 127);
			wait(0.5);
			stopMotor(firingMotor);
		}
	}
}

