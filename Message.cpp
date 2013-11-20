#include "Message.h"

void Message::setText(char* text)
{
	strcpy(this->_text, text);	
}

char* Message::getText()
{
	return this->_text;	
}

//SerialObject virtual members

void Message::readData(SerialInputStream& input)
{
	input.readString(this->_text);
}

void Message::writeData(SerialOutputStream& output)
{
	output.writeString(_text);
}

int Message::getDataSize()
{
	return SerialObjectTypes::SIZEOF_INTEGER + strlen(this->_text);
}