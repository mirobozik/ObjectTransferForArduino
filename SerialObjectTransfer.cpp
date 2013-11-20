#include "SerialObjectTransfer.h"

ObjectTransfer_::ObjectTransfer_()
{
	_readerCounter = 0;
}

void ObjectTransfer_::begin()
{
	this->_port = &Serial;
	_port->begin(DEFAULT_SPEED);
#ifdef __USBAPI__
	while (!Serial)
	{
		;
	}
#endif // __USBAPI__
}

void ObjectTransfer_::begin(long speed)
{
	_port = &Serial;
	_port->begin(speed);
#ifdef __USBAPI__
	while (!Serial)
	{
		;
	}
#endif // __USBAPI__
}

#ifdef __USBAPI__
void ObjectTransfer_::begin(Serial_* port, long speed)
{
	_port = port;
	_port->begin(speed);
	while (!Serial)
	{
		;
	}
}
#else
void ObjectTransfer_::begin(HardwareSerial* port, long speed)
{
	_port = port;
	_port->begin(speed);
}
#endif // __USBAPI__

void ObjectTransfer_::addDeserializableData(SerialObject* serialObject) 
{
	_readers[_readerCounter] = new SerialObjectReader(serialObject);
	++_readerCounter;
}

void ObjectTransfer_::processInput() 
{
	if (_port->available() > 0) 
	{
		byte b = _port->read();
		process(b);
	}
}

void ObjectTransfer_::write(SerialObject* data) 
{
	SerialOutputStream out;
	data->write(out);
	byte* buffer = out.getBuffer();
	for (int i = 0; i < out.getPosition(); ++i) 
	{
		_port->write(buffer[i]);
	}
}

void ObjectTransfer_::process(byte b) 
{
	for (int i = 0; i < _readerCounter; i++) 
	{
		_readers[i]->processData(b);
	}
}

ObjectTransfer_ ObjectTransfer;

