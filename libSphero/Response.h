#ifndef SPHERO_RESPONSE_H_
#define SPHERO_RESPONSE_H_
#include <ostream>
#include <string>
#include <vector>
#include <inttypes.h>

namespace LibSphero {

#ifndef BYTE_ARRAY_BUFFER_T
#define BYTE_ARRAY_BUFFER_T
typedef std::vector<uint8_t> ByteArrayBuffer;
#endif

namespace Response {

typedef std::vector<uint8_t> ByteArrayBuffer;

enum class Type {
	REGULAR, INFORMATION, UNKNOWN
};

enum class Code {
	OK,
	ERROR_GENERAL,
	ERROR_CHECKSUM,
	ERROR_FRAGMENT,
	ERROR_BAD_COMMAND,
	ERROR_UNSUPPORTED,
	ERROR_BAD_MESSAGE,
	ERROR_PARAMETER,
	ERROR_EXECUTE,
	ERROR_MAIN_APP_CORRUPT,
	ERROR_TIME_OUT,
	ERROR_UNKNOWN,
	UNKNOWN_RESPONSE,
	INVALID
};

enum class InformationCode {
	EMIT, DATA, INVALID
};

std::ostream &operator<<(std::ostream &os, Type type);
std::ostream &operator<<(std::ostream &os, Code code);
std::ostream &operator<<(std::ostream &os, InformationCode code);

/** Response message class */
class Message {
private:
	ByteArrayBuffer packet;
	Code code;
	Type type;

public:
	/** Returns whether the data buffer contains at least one valid packet */
	static bool containsValidPacket(const ByteArrayBuffer &data);

	/** Creates a message */
	Message();

	/** Creates a message */
	Message(const ByteArrayBuffer &source);

	virtual ~Message();

	/** Returns the response type */
	Type getResponseType() const {
		return type;
	}

	/** Returns the response code */
	Code getResponseCode() const {
		return code;
	}

	/** Returns the message packet */
	const ByteArrayBuffer &getPacket() const {
		return packet;
	}

	/** Returns a pointer to the packet data */
	const uint8_t* getPacketPointer() const {
		return &packet[0];
	}

	/** For information responses, returns the information code */
	InformationCode getInformationCode() const;

	/** Returns whether the packet is corrupt */
	bool isCorrupt() const;

	/** Returns the size of the header */
	size_t getHeaderLength() const;

	/** Returns where, in the packet, the payload begins */
	size_t getPayloadStart() const;

	/** Returns the size of the payload */
	size_t getPayloadLength() const;

	/** Returns the total size of the packet */
	size_t getTotalLength() const;

	/** Returns the packet sequence number */
	int getSequenceNumber() const;

	/** Returns the checksum contained in the packet */
	uint8_t getClaimedChecksum() const;

	/** Returns the checksum calculated from the packet */
	uint8_t getActualChecksum() const;

};

}

}
#endif
