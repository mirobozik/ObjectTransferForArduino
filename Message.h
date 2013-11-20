#ifndef _MESSAGE_h
#define _MESSAGE_h

#include "Arduino.h"
#include "SerialObject.h"
#include "SerialInputStream.h"
#include "SerialOutputStream.h"

class Message : public SerialObject
{
private:
	char _text[32];			

public:	
	void setText(char* text);
	char* getText();	
	//SerialObject virtual members
	void readData(SerialInputStream& input);
	void writeData(SerialOutputStream& output);
	int getDataSize();
	
};

#endif

