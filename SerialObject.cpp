#include "SerialObject.h"

SerialObject::SerialObject()
{
	_preamble = 123456789;   // default preamble
	_postamble = 987654321;  // default postamble
	updateCallback = NULL;
}

SerialObject::~SerialObject()
{
}

long SerialObject::getPreamble()
{
	return _preamble;
}

void SerialObject::setPreamble(long preamble)
{
	this->_preamble = preamble;
}

// the checksum is calculated at runtime
long SerialObject::getChecksum()
{
	return _checksum;
}

void SerialObject::setChecksum(long checksum)
{
	this->_checksum = checksum;
}

long SerialObject::getPostamble()
{
	return _postamble;
}

void SerialObject::setPostamble(long postamble)
{
	this->_postamble = postamble;
}

void SerialObject::read(SerialInputStream& input)
{
	setPreamble(input.readInteger());
	setChecksum(input.readInteger());

	readData(input); // let the subclass read its data

	setPostamble(input.readInteger());
}

void SerialObject::write(SerialOutputStream& output)
{
	output.writeInteger(getPreamble());
	output.writeInteger(getSize());

	writeData(output); // let the subclass write its data

	output.writeInteger(getPostamble());
}

int SerialObject::getSize()
{
	int size = SerialObjectTypes::SIZEOF_INTEGER; // preamble
	size += SerialObjectTypes::SIZEOF_INTEGER;    // checksum
	size += getDataSize();                         // subclass' data size
	size += SerialObjectTypes::SIZEOF_INTEGER;    // postamble

	return size;
}

void SerialObject::setUpdateCallback(void (*ptr)(SerialObject*))
{
	updateCallback = ptr;
}