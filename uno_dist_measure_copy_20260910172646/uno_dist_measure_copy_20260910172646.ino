const int trigPin = 7;
const int echoPin = 8; 
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
      pinMode(led3,OUTPUT);
        pinMode(led4,OUTPUT);
}

void loop()
{
  long duration, inches, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

    if (cm >= 25){
    delay(100);
    digitalWrite(led4,OUTPUT);
  } else {
    delay(100);
    digitalWrite(led4,LOW);
  }
    if (cm >= 20){
      delay(100);
    digitalWrite(led3,OUTPUT);
  } else {
    delay(100);
    digitalWrite(led3,LOW);
  }
    if (cm >= 15){
      delay(100);
    digitalWrite(led2,OUTPUT);
  } else {
    delay(100);
    digitalWrite(led2,LOW);
  }
    if (cm >= 10){
      delay(100);
    digitalWrite(led1,OUTPUT);
  } else {
    delay(100);
    digitalWrite(led1,LOW);
  }
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}


