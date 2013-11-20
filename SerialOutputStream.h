#ifndef _SERIALOUTPUTSTREAM_h
#define _SERIALOUTPUTSTREAM_h

#include "Arduino.h"
#include "SerialObjectTypes.h"

class SerialOutputStream
{
private:
	byte* _buffer;
	int _position;
	int _size;
	void initialize(short bufferSize);
	void write(byte b);
	void write(byte b[], int length);
public:
	static const short DEFAULT_BUFFER_SIZE = 512;
	SerialOutputStream();
	SerialOutputStream(short bufferSize);
	~SerialOutputStream();
	void writeInteger(long val);
	void writeFloat(float val);
	void writeString(char* str);
	byte* getBuffer();
	int getPosition() { return(_position); };
};

#endif

