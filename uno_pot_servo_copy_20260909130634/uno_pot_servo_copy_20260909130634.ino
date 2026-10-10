#include <Servo.h>

int sensorValue;
int led = 11;
Servo myservo;
void setup()
{
	Serial.begin(9600);
  	pinMode(led,OUTPUT);
    myservo.attach(11);

}

void loop()
{
	sensorValue = analogRead(A0);
  	float voltage = sensorValue*(5.0/1023.0);
  	Serial.println(voltage);
    int dist = map(sensorValue,0,1023,0,180);
    myservo.write(dist);
    delay(10);
}