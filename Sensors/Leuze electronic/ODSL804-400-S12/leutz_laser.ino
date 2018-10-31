#include <SoftwareSerial.h>

bool flag = 0;
int value = 0;
double measurement = 0;
//SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  //mySerial.begin(9600);
}

void loop()
{
  readLaser();
}

void readLaser()
{
  if (Serial.available())
  {
    byte Rxbyte = Serial.read();            //Read transmitted byte

    if (flag == 0)                          //First byte has to be a Low-Byte
    {
      if ((Rxbyte & 0x01) == 0)             //Test on Low-Byte
      {
        value = (Rxbyte & 0xFE) >> 1;       //Insert measurement value point-aligned
        flag = 1;                           //Next received byte has to be a High-Byte
      }
    }
    else
    {
      if ((Rxbyte & 0x01) == 1)             //Test on High-Byte
      {
        value |= ((Rxbyte & 0xFE) << 6);    //Insert point-aligned in measurement value
        flag = 0;                           //14 bit measurement value is generated

        measurement = value / 10.00;
        Serial.println(measurement);
      }
    }
  }
}