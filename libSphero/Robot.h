#ifndef SPHERO_ROBOT_H_
#define SPHERO_ROBOT_H_

#include "Command.h"
#include "Response.h"

namespace LibSphero {

class RobotState {
public:
	int heading;
	uint8_t velocity;
	uint8_t rotationRate;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t brightness;
	bool stop;
};

class IListener {
public:
	virtual ~IListener() {}
	virtual void onPacketReceived(const Response::Message &message) = 0;
};

class Robot {
private:
	ByteArrayBuffer rxBuffer;
	std::string address;
	RobotState state;
	int socket;
	unsigned int seqNum;
	bool debug;

	void updateInternalValues(const Command::Message &command);

public:
	Robot();
	virtual ~Robot();

	/** Connects to the given Bluetooth address. The address should be
	 * in the form '00:06:66:XX:XX:XX' */
	bool connect(const std::string &address);

	/** Closes the connection */
	void disconnect();

	/** Sends a direct command to the robot */
	void send(const Command::Message &message);

	/** Listens for data coming from the robot, sending the received data to the listener.
	 * This function will block indefinitely. */
	void listen(IListener &listener);

	/** Sets whether incoming and outgoing data should be printed */
	void setDebug(bool b);

	/** Sends a roll command to the given heading (in degrees) and speed (0-255) */
	void roll(int heading, uint8_t speed);

	/** Sets the speed (0-255) while maintaining the heading */
	void setSpeed(uint8_t speed);

	/** Sets the heading (in degrees) while maintaining the speed */
	void setHeading(int heading);

	/** Stops the motors */
	void stop();

	/** Calibrates the heading */
	void calibrateHeading(int heading);

	/** Sets the LED RGB color */
	void setLEDColor(uint8_t red, uint8_t green, uint8_t blue);

	/** Sets the brightness of the front LED (0-255) */
	void setFrontLEDBrightness(uint8_t brightness);

	/** Enables or disables the stabilizer */
	void enableStabilizer(bool on);

	/** Convenience function, waits the given amount of milliseconds.
	 * This function is not related to the SLEEP macro. */
	void delay(unsigned int milliseconds);

	/** Returns whether the socket is connected */
	bool isConnected() const {
		return socket != -1;
	}

	/** Returns information about the state stored from sent commands */
	const RobotState &getState() const {
		return state;
	}

	/** Returns the last heading sent */
	int getHeading() const {
		return state.heading;
	}

	/** Returns the last velocity sent */
	uint8_t getVelocity() const {
		return state.velocity;
	}

	/** Returns the last red color sent */
	uint8_t getLEDRed() const {
		return state.red;
	}

	/** Returns the last green color sent */
	uint8_t getLEDGreen() const {
		return state.green;
	}

	/** Returns the last blue color sent */
	uint8_t getLEDBlue() const {
		return state.blue;
	}

	/** Returns the last front LED brightness sent */
	uint8_t getFrontLEDBrightness() const {
		return state.brightness;
	}

	/** Returns whether a stop command has been sent */
	bool isStopped() const {
		return state.stop;
	}

	/** Returns the address of the Bluetooth device */
	const std::string &getAddress() const {
		return address;
	}

};

std::ostream &operator<<(std::ostream &os, const ByteArrayBuffer &packet);

}

#endif
