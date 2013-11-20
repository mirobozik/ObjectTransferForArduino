#ifndef _SERIALOBJECTREADER_h
#define _SERIALOBJECTREADER_h

#include "Arduino.h"
#include "SerialObjectTypes.h"
#include "SerialObject.h"

class SerialObjectReader
{
private:
	static const short DEFAULT_BUFFER_SIZE = 512;
	SerialObject* _serialObject;
	byte* _buffer;
	short _bufferCounter;
	short _bufferSize;
	short _preambleCounter;
	short _postambleCounter;
	boolean _doCollectData;
	byte _preamble[SerialObjectTypes::SIZEOF_INTEGER];
	byte _postamble[SerialObjectTypes::SIZEOF_INTEGER];
	void initialize(SerialObject* data, short bufferSize);
	void collectData(byte b);
public:
	SerialObjectReader(SerialObject* data);
	SerialObjectReader(SerialObject* data, short bufferSize);
	~SerialObjectReader();
	void processData(byte b);

};

#endif

