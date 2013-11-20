#include "SerialInputStream.h"

SerialInputStream::SerialInputStream(byte* buffer, short bufferSize) {
	_buffer = buffer;
	_position = 0;
	_size = bufferSize;
}

SerialInputStream::~SerialInputStream()
{
	
}

long SerialInputStream::readInteger() {
	byte b[SerialObjectTypes::SIZEOF_INTEGER];
	for (int i = 0; i < SerialObjectTypes::SIZEOF_INTEGER; ++i) {
		b[i] = (byte)read();
	}
	return SerialObjectTypes::bytesToInteger(b);
}

float SerialInputStream::readFloat() 
{
	return SerialObjectTypes::intBitsToFloat(readInteger());
}

void SerialInputStream::readString(char* str) 
{
	int length = (int)readInteger();
	//Serial1.print("length of string=");
	//Serial1.println(length);
	
	for (int i = 0; i < length; ++i) {
		str[i] = (char)read();
	}
	str[length] = '\0';
	
	//Serial1.print("message=");
	//Serial1.println(str);
}

int SerialInputStream::read() 
{
	if (_position < _size) 
	{
		return _buffer[_position++] & 0xff;
	}
	else 
	{
		return -1;
	}
}
