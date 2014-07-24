#ifndef SPHERO_COMMAND_H_
#define SPHERO_COMMAND_H_
#include <ostream>
#include <string>
#include <vector>
#include <inttypes.h>

namespace LibSphero {

#ifndef BYTE_ARRAY_BUFFER_T
#define BYTE_ARRAY_BUFFER_T
typedef std::vector<uint8_t> ByteArrayBuffer;
#endif

namespace Command {

enum class MessageType {
	PING,
	VERSIONING,
	SET_BLUETOOTH_NAME,
	GET_BLUETOOTH_INFO,
	GO_TO_SLEEP,
	JUMP_TO_BOOTLOADER,
	LEVEL_1_DIAGNOSTICS,
	JUMP_TO_MAIN,
	CALIBRATE,
	STABILIZATION,
	ROTATION_RATE,
	RGB_LED_OUTPUT,
	FRONT_LED_OUTPUT,
	ROLL,
	BOOST,
	RAW_MOTOR,
	GET_CONFIGURATION_BLOCK,
	RUN_MACRO,
	MACRO,
	SAVE_MACRO,
	ABORT_MACRO,
	SET_DATA_STREAMING,
	SPIN_LEFT,
	SPIN_RIGHT,
	CUSTOM_PING,
	INVALID,

};

std::ostream &operator<<(std::ostream &os, MessageType type);

/** Command message class */
class Message {
private:
	MessageType command;
	ByteArrayBuffer payload;

public:
	/** Creates a message with the given command and no payload */
	Message(MessageType command);

	/** Creates a message with the given command and the given payload */
	Message(MessageType command, const ByteArrayBuffer &payload);

	~Message();

	/** Returns the command */
	MessageType getCommand() const {
		return command;
	}

	/** Returns the payload */
	ByteArrayBuffer &getPayload() {
		return payload;
	}

	/** Returns the payload */
	const ByteArrayBuffer &getPayload() const {
		return payload;
	}

	/** Returns a pointer to the payload */
	const uint8_t* getPayloadPointer() const {
		return &payload[0];
	}

	/** Converts the message to a packet */
	void packetize(ByteArrayBuffer &buffer, int seqNum) const;
};

}

}
#endif
