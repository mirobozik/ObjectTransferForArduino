#ifndef _SERIALINPUTSTREAM_h
#define _SERIALINPUTSTREAM_h

#include "Arduino.h"
#include "SerialObjectTypes.h"

class SerialInputStream
{
private:
	byte* _buffer;
	int _position;
	int _size;
	int read();
 
public:
	SerialInputStream(byte* buffer, short bufferSize);
	~SerialInputStream();
	long readInteger();
	float readFloat();
	void readString(char* str);

};

#endif

