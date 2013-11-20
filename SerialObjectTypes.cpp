#include "SerialObjectTypes.h"

long SerialObjectTypes::bytesToInteger(byte b[SerialObjectTypes::SIZEOF_INTEGER]) 
{
	long val = 0;
	val = ((long)b[0]) << 24;
	val |= ((long)b[1]) << 16;
	val |= ((long)b[2]) << 8;
	val |= b[3];
	return val;
}

void SerialObjectTypes::integerToBytes(long val, byte b[SerialObjectTypes::SIZEOF_INTEGER]) 
{
	b[0] = (val >> 24) & 0xff;
	b[1] = (val >> 16) & 0xff;
	b[2] = (val >> 8) & 0xff;
	b[3] = val & 0xff;
}

long SerialObjectTypes::floatToIntBits(float val) 
{
	union u u;
	u.d = val;
	long e = u.l & 0x7f800000;
	long f = u.l & 0x007fffff;

	if (e == 0x7f800000 && f != 0) {
		u.l = 0x7fc00000;
	}

	return u.l;
}

float SerialObjectTypes::intBitsToFloat(long bits) 
{
	union u u;
	u.l = bits;
	return u.d;
}
