#ifndef _OBJECTTRANSFER_h
#define _OBJECTTRANSFER_h

#include "Arduino.h"
#include "SerialObjectReader.h"
#include "SerialObjectTypes.h"
#include "SerialOutputStream.h"
#include "SerialInputStream.h"

class ObjectTransfer_
{
private:
	static const long DEFAULT_SPEED = 115200;
	static const short MAXIMUM_READERS = 8;
#ifdef __USBAPI__
	Serial_* _port;
#else
	HardwareSerial* _port;
#endif // __USBAPI__
	SerialObjectReader* _readers[MAXIMUM_READERS];
	int _readerCounter;
	void process(byte b);

public:
	ObjectTransfer_();
	void addDeserializableData(SerialObject* data);
	void begin();
	void begin(long speed);
#ifdef __USBAPI__
	void begin(Serial_* port, long speed);
#else
	void begin(HardwareSerial* port, long speed);
#endif // __USBAPI__
	void processInput();
	void write(SerialObject* data);
};

extern ObjectTransfer_ ObjectTransfer;

#endif

