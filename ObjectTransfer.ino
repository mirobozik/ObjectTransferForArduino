#include "SerialObjectTransfer.h"
#include "Message.h"

#define OT_SPEED 19200
#define DEBUG_SPEED 19200

Message message;

void updateMessage(SerialObject* object)
{
	Serial1.print("Message.Text=");
	Serial1.println(message.getText());
	Serial1.print("preamble=");
	Serial1.println(message.getPreamble());
	Serial1.print("Postamble=");
	Serial1.println(message.getPostamble());
	Serial1.print("Checksum=");
	Serial1.println(message.getChecksum());
}

void setup()
{	
	Serial1.begin(DEBUG_SPEED);
	
	message.setUpdateCallback(&updateMessage);
	
	ObjectTransfer.begin(OT_SPEED);
	ObjectTransfer.addDeserializableData(&message);
}

void loop()
{	
	ObjectTransfer.processInput();
	
	Message myMessage;
	myMessage.setText("Hello PC!");
	ObjectTransfer.write(&myMessage);
	delay(5000);
}

