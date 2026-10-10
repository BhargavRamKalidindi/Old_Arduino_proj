#include <Servo.h>

Servo base;
Servo bottom;
Servo middle;

int btncycle;

void setup() {
  Serial.begin(9600);

  base.attach(3);
  bottom.attach(5);
  middle.attach(6);
}

void loop() {
  for (btncycle = 0; btncycle <= 150; btncycle += 5){
    delay(150);
    base.write(btncycle);
    middle.write(btncycle);
    bottom.write(btncycle);
    break;
  }
  for (btncycle = 155; btncycle >= 150; btncycle -= 5){
    delay(150);
    base.write(btncycle);
    middle.write(btncycle);
    bottom.write(btncycle);
    break;
  }
}
