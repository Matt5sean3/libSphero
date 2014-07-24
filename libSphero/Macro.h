#ifndef SPHERO_MACRO_H_
#define SPHERO_MACRO_H_
#include "Command.h"
namespace LibSphero {

struct Macro {
	enum BlockSpecifier {
		FACTORY = 0, USER = 1
	};

	enum MotorMode {
		FORWARD = 1, REVERSE = 2
	};

	enum Flag {
		MacroFlagNone = 0,
		MacroFlagMotorControl = 1,
		MacroFlagExclusiveDrive = 2,
		MacroFlagUseVersion3 = 4,
		MacroFlagInhibitIfConnected = 8,
		MacroFlagEndMarker = 16,
		MacroFlagStealth = 32,
		MacroFlagUnkillable = 64,
		MacroFlagExtendedFlags = -128,
		MACRO_STREAMING_DESTINATION = -2,
	};

	/** Flags to determine sensor data */
	enum StreamingMasks {
		OFF = 0,

		MOTOR_BACK_EMF_LEFT_FILTERED = 32,
		MOTOR_BACK_EMF_LEFT_RAW = MOTOR_BACK_EMF_LEFT_FILTERED << 16,
		MOTOR_BACK_EMF_RIGHT_FILTERED = 64,
		MOTOR_BACK_EMF_RIGHT_RAW = MOTOR_BACK_EMF_RIGHT_FILTERED << 16,
		MOTOR_BACK_EMF_FILTERED = MOTOR_BACK_EMF_LEFT_FILTERED
				| MOTOR_BACK_EMF_RIGHT_FILTERED,
		MOTOR_BACK_EMF_RAW = MOTOR_BACK_EMF_LEFT_RAW
				| MOTOR_BACK_EMF_RIGHT_RAW,

		MAGNETOMETER_X_FILTERED = 512,
		MAGNETOMETER_X_RAW = MAGNETOMETER_X_FILTERED << 16,
		MAGNETOMETER_Y_FILTERED = 256,
		MAGNETOMETER_Y_RAW = MAGNETOMETER_Y_FILTERED << 16,
		MAGNETOMETER_Z_FILTERED = 128,
		MAGNETOMETER_Z_RAW = MAGNETOMETER_Z_FILTERED << 16,
		MAGNETOMETER_FILTERED = MAGNETOMETER_X_FILTERED
				| MAGNETOMETER_Y_FILTERED
				| MAGNETOMETER_Z_FILTERED,
		MAGNETOMETER_RAW = MAGNETOMETER_X_RAW
				| MAGNETOMETER_Y_RAW
				| MAGNETOMETER_Z_RAW,

		ACCELEROMETER_X_FILTERED = 32768,
		ACCELEROMETER_X_RAW = ACCELEROMETER_X_FILTERED << 16,
		ACCELEROMETER_Y_FILTERED = 16384,
		ACCELEROMETER_Y_RAW = ACCELEROMETER_Y_FILTERED << 16,
		ACCELEROMETER_Z_FILTERED = 8192,
		ACCELEROMETER_Z_RAW = ACCELEROMETER_Z_FILTERED << 16,
		ACCELEROMETER_FILTERED = ACCELEROMETER_X_FILTERED
				| ACCELEROMETER_Y_FILTERED
				| ACCELEROMETER_Z_FILTERED,
		ACCELEROMETER_RAW = ACCELEROMETER_X_RAW
				| ACCELEROMETER_Y_RAW
				| ACCELEROMETER_Z_RAW,

		GYRO_X_FILTERED = 4096,
		GYRO_X_RAW = GYRO_X_FILTERED << 16,
		GYRO_Y_FILTERED = 2048,
		GYRO_Y_RAW = GYRO_Y_FILTERED << 16,
		GYRO_Z_FILTERED = 1024,
		GYRO_Z_RAW = GYRO_Z_FILTERED << 16,
		GYRO_FILTERED = GYRO_X_FILTERED | GYRO_Y_FILTERED | GYRO_Z_FILTERED,
		GYRO_RAW = GYRO_X_RAW | GYRO_Y_RAW | GYRO_Z_RAW,

		IMU_YAW_FILTERED = 65536,
		IMU_ROLL_FILTERED = 131072,
		IMU_PITCH_FILTERED = 262144,
		IMU_FILTERED = IMU_YAW_FILTERED | IMU_ROLL_FILTERED | IMU_PITCH_FILTERED,
	};

	/** Aborts a running macro */
	static Command::Message abort();

	/** Calibrates using the given heading */
	static Command::Message calibrate(int heading);

	/** Sets the front LED brightness (0-255) */
	static Command::Message setFrontLED(uint8_t brightness);

	/** Gets the Bluetooth info  */
	static Command::Message getBluetoothInfo();

	static Command::Message getConfigurationBlock(BlockSpecifier block); //?

	/** Sets the robot in bootloader application. This closes the connection. */
	static Command::Message jumpToBootloader();

	/** Jumps to the application. This closes the connection. */
	static Command::Message jumpToMain();

	static Command::Message level1Diagnostics(); //?

	/** Sets the RGB LED color */
	static Command::Message RGBLED(uint8_t red,
			uint8_t green,
			uint8_t blue);

	/** Sets the direction and speed for each individual internal motor */
	static Command::Message rawMotor(MotorMode leftMode,
			uint8_t leftSpeed,
			MotorMode rightMode,
			uint8_t rightSpeed);

	/** Moves the robot in a given heading angle (in degress) and a given speed (0-255) */
	static Command::Message roll(int heading,
			uint8_t velocity,
			bool stop);

	static Command::Message rotationRate(uint8_t rate); //?

	/** Runs the given macro (untested) */
	static Command::Message runMacro(uint8_t macroId);

	/** Tells the robot to stream back sensor data
	 * @param mDivisor Divisor to divide the default sampling rate of 400 Hz
	 * @param mPacketFrames Number of frames per packet
	 * @param mSensorMask Which sensor values to send (bit mask from StreamingMasks)
	 * @param mPacketCount Number of packets to receive
	 **/
	static Command::Message setDataStreaming(uint16_t mDivisor,
			uint16_t mPacketFrames,
			int mSensorMask,
			uint8_t mPacketCount);

	/** Sets the robot name */
	static Command::Message setRobotName(const std::string &name);

	/** Sleeps for the given number of seconds. This closes the connection */
	static Command::Message sleep(int time, int macroId);

	/** Tells the robot to spin left */
	static Command::Message spinLeft(uint8_t speed);

	/** Tells the robot to spin right */
	static Command::Message spinRight(uint8_t speed);

	/** Enables or disables the stabilizer */
	static Command::Message enableStabilizer(bool on);

	/** Requests version information from the robot */
	static Command::Message version();

};

}
#endif
