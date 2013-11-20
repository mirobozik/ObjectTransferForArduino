#include "SerialOutputStream.h"

SerialOutputStream::SerialOutputStream() 
{
	initialize(DEFAULT_BUFFER_SIZE);
}

SerialOutputStream::SerialOutputStream(short bufferSize) 
{
	initialize(bufferSize);
}

SerialOutputStream::~SerialOutputStream() 
{
	free(_buffer);
}

void SerialOutputStream::initialize(short bufferSize) 
{
	_buffer = (byte*)malloc(bufferSize* sizeof(byte));
	_position = 0;
	_size = bufferSize;
}

void SerialOutputStream::writeInteger(long val) 
{
	byte b[SerialObjectTypes::SIZEOF_INTEGER];
	SerialObjectTypes::integerToBytes(val, b);
	write(b, SerialObjectTypes::SIZEOF_INTEGER);
}

void SerialOutputStream::writeFloat(float val) 
{
	long d = SerialObjectTypes::floatToIntBits(val);
	writeInteger(d);
}

void SerialOutputStream::writeString(char* str) 
{
	int length = strlen(str);

	// write the length of the string first
	writeInteger(length);

	// write the characters
	for (int i = 0; i < length; ++i) 
	{
		write((byte)str[i]);
	}
}

byte* SerialOutputStream::getBuffer() 
{
	return _buffer;
}

void SerialOutputStream::write(byte b) 
{
	if (_position < _size) {
		_buffer[_position++] = b;
	}
}

void SerialOutputStream::write(byte b[], int length) 
{
	for (int i = 0; (i < length) & (i < _size); ++i) 
	{
		_buffer[_position++] = b[i];
	}
}