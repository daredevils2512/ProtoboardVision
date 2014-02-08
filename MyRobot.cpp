#include "WPILib.h"
#include "VisionSample2014.h"
/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	VisionSample2014* vision;
	AxisCamera& camera;
	Joystick stick1;
public:
	
	RobotDemo():
		vision(new VisionSample2014),
		camera(AxisCamera::GetInstance("10.25.12.11")),
		stick1(1)
	{
		SmartDashboard::init();
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		
		while (IsOperatorControl())
		{

			SmartDashboard::PutBoolean("HOT", vision->ProcessImage());
			if(stick1.GetRawButton(1)) {
				SetToAutonomous();	
			}
			else if(stick1.GetRawButton(2)) {
				SetToTeleop();
			}
				

		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
	
	void SetToAutonomous() {
		camera.WriteBrightness(0);
	}
	
	void SetToTeleop() {
		camera.WriteBrightness(100);
	}
};

START_ROBOT_CLASS(RobotDemo);

