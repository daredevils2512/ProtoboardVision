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
	AxisCamera* camera;
public:
	
	RobotDemo()
	{
		vision = new VisionSample2014;
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
			camera->WriteExposureControl(AxisCamera::kExposure_Automatic);
			camera->WriteWhiteBalance(AxisCamera::kWhiteBalance_Automatic);
			camera->WriteBrightness(1);
				
			SmartDashboard::PutBoolean("HOT", vision->ProcessImage());
			
			camera->WriteExposureControl(AxisCamera::kExposure_Automatic);
			camera->WriteWhiteBalance(AxisCamera::kWhiteBalance_Automatic);
			camera->WriteBrightness(1);
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

