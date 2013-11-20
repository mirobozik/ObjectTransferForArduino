#include "SerialObjectReader.h"

SerialObjectReader::SerialObjectReader(SerialObject* data)
{
	initialize(data, DEFAULT_BUFFER_SIZE);
}

SerialObjectReader::SerialObjectReader(SerialObject* data, short bufferSize)
{
	initialize(data, bufferSize);
}

SerialObjectReader::~SerialObjectReader()
{
	free(_buffer);
}

void SerialObjectReader::initialize(SerialObject* data, short bufferSize)
{
	this->_serialObject = data;
	this->_bufferSize = bufferSize;

	_buffer = (byte*)malloc(bufferSize* sizeof(byte));
	_bufferCounter = 0;

	_preambleCounter = 0;
	_postambleCounter = 0;
	_doCollectData = false;

	SerialObjectTypes::integerToBytes(_serialObject->getPreamble(), _preamble);
	SerialObjectTypes::integerToBytes(_serialObject->getPostamble(), _postamble);
}

void SerialObjectReader::processData(byte b)
{
	if (_doCollectData)
	{
		// if the collect data flag is set (after receiving the preamble) then collect the serial data
		collectData(b);
	}
	else
	{
		if (b == _preamble[_preambleCounter])
		{
			// if the data byte is a preamble sequence byte then collect the preamble
			_buffer[_preambleCounter] = b;
			++_preambleCounter;
		}
		else
		{
			// if the data byte is not a preamble sequence byte then reset the preamble counter
			_preambleCounter = 0;
		}
		// if the whole preamble sequence is received...
		if (_preambleCounter == SerialObjectTypes::SIZEOF_INTEGER)
		{
			// reset the preamble counter to be ready to count the next preamble seuquence byte
			_preambleCounter = 0;
			// start collecting the data
			_bufferCounter = SerialObjectTypes::SIZEOF_INTEGER - 1; // the preamble is already stored in the buffer
			_doCollectData = true;
		}
	}
}

void SerialObjectReader::collectData(byte b)
{
	// increase the buffer counter but prevent a buffer overflow
	if (_bufferCounter < _bufferSize)
	{
		++_bufferCounter;
	}

	// fill the buffer
	_buffer[_bufferCounter] = b;

	// check for a postamble sequence byte
	if (b != _postamble[_postambleCounter])
	{
		_postambleCounter = 0;
	}
	else
	{
		++_postambleCounter;
	}

	// if the whole postamble sequence is received...
	if (_postambleCounter == SerialObjectTypes::SIZEOF_INTEGER)
	{
		// do a checksum test before deserializing the data
		byte checksumBytes[SerialObjectTypes::SIZEOF_INTEGER];
		for (int i = 0; i < SerialObjectTypes::SIZEOF_INTEGER; ++i)
		{
			checksumBytes[i] = _buffer[i+SerialObjectTypes::SIZEOF_INTEGER];
		}
		int checksumInt = SerialObjectTypes::bytesToInteger(checksumBytes);		
		// deserialize the data and fire an update event (callback routine)
		if (checksumInt == _bufferCounter + 1)
		{
			SerialInputStream input(_buffer, _bufferCounter);
			_serialObject->read(input);
			if (_serialObject->updateCallback != NULL)
			{
				(*(_serialObject->updateCallback))(_serialObject);
			}
		}
		else
		{
			// Exception handling
		}
		// reset the postamble counter to be ready to count the next postamble seuquence byte
		_postambleCounter = 0;
		// stop collecting the data (start waiting for the preamble sequence)
		_doCollectData = false;
	}
}
