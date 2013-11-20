#ifndef _SERIALOBJECTTYPES_h
#define _SERIALOBJECTTYPES_h

#include "Arduino.h"

class SerialObjectTypes
{
public:	
	static const int SIZEOF_INTEGER = 4;
	static const int SIZEOF_FLOAT = 4;
	static const int SIZEOF_STRING = 4;
	static long bytesToInteger(byte b[SIZEOF_INTEGER]);
	static void integerToBytes(long val, byte b[SIZEOF_INTEGER]);
	static long floatToIntBits(float val);
	static float intBitsToFloat(long bits);
};

// the float to integer conversion union
union u { long l; float d; };

#endif

