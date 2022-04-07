#include "BopItIO.hpp"

void setup()
{
	BopItIO::initializeSensors();
}

void loop() 
{
	BopItIO::accelData data = BopItIO::readShakeSensor();
	Serial.println("Accelerometer Data: ");
	Serial.println(data.accelX);
	Serial.println(data.accelY);
	Serial.println(data.accelZ);
	Serial.println(data.gyroX);
	Serial.println(data.gyroY);
	Serial.println(data.gyroZ);
	delay(100);
}