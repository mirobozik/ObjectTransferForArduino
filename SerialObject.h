#ifndef _SERIALOBJECT_h
#define _SERIALOBJECT_h

#include "Arduino.h"
#include "SerialObjectTypes.h"
#include "SerialInputStream.h"
#include "SerialOutputStream.h"

class SerialObject
{
private:
	long _preamble;
	long _checksum;
	long _postamble;	

public:
	SerialObject();
	virtual ~SerialObject();
	long getPreamble();
	void setPreamble(long preamble);
	long getChecksum();
	void setChecksum(long checksum);
	long getPostamble();
	void setPostamble(long postamble);
	int getSize();
	void read(SerialInputStream& input);
	void write(SerialOutputStream& output);
	void (*updateCallback)(SerialObject* data);
	void setUpdateCallback(void (*ptr)(SerialObject*));
	virtual void readData(SerialInputStream& input) { };
	virtual void writeData(SerialOutputStream& output) { };
	virtual int getDataSize() { return 0; };
};

#endif

