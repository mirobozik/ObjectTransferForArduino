//Board = Arduino Leonardo
#define __AVR_ATmega32U4__
#define ARDUINO 105
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

void updateMessage(SerialObject* object);
//
//

#include "D:\applications\arduino-1.0.5\hardware\arduino\variants\leonardo\pins_arduino.h" 
#include "D:\applications\arduino-1.0.5\hardware\arduino\cores\arduino\arduino.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\ObjectTransfer.ino"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\Message.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\Message.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialInputStream.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialInputStream.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObject.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObject.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectReader.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectReader.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectTransfer.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectTransfer.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectTypes.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialObjectTypes.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialOutputStream.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SerialOutputStream.h"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SimpleSerialization.cpp"
#include "D:\Disk Google\ArduinoProjects\ObjectTransfer\SimpleSerialization.h"
