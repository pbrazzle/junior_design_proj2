#ifndef BOPITIO
#define BOPITIO

#include <Wire.h>

namespace BopItIO
{
	const int MPU=0x68;

	struct accelData
	{
		int accelX, accelY, accelZ, gyroX, gyroY, gyroZ;
	};
	
	void initializeSensors()
	{
		Wire.begin();
		Wire.beginTransmission(MPU);
		Wire.write(0x6B); 
		Wire.write(0);    
		Wire.endTransmission(true);
		Serial.begin(9600);
	}
	
	bool readPopButton()
	{
		return false;
	}

	bool readDigButton()
	{
		return false;
	}

	accelData readShakeSensor()
	{
		//Make struct for accelerometer data?
		accelData data;
		Wire.beginTransmission(MPU);
		Wire.write(0x3B);  
		Wire.endTransmission(false);
		Wire.requestFrom(MPU,12,true);  
		data.accelX = Wire.read()<<8 | Wire.read();    
		data.accelY = Wire.read()<<8 | Wire.read();  
		data.accelZ = Wire.read()<<8 | Wire.read();  
		data.gyroX  = Wire.read()<<8 | Wire.read();  
		data.gyroY  = Wire.read()<<8 | Wire.read();  
		data.gyroZ  = Wire.read()<<8 | Wire.read();
		return data;
	}
}

#endif
