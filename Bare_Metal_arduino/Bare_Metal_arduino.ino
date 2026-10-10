// Accessing mem address on Port b data register (digital pins), direct access increases speed multiple times
#define RAMPORTB *((volatile byte*) 0x25) 
// Assessing mem address on Port b data direction register to control wether specified pin is an input or output
#define RAMDIRB  *((volatile byte*) 0x24) 

void setup() {
  RAMDIRB = 32;  //1000000,  to set pin 13 as output 
}

void loop() {
  RAMPORTB = 32; //1000000,  to give pin 13 on high/5v

  for (long i = 0; i < 1000000; i++) {RAMPORTB = 32;} //to wastte some time in order to act as a "delay"of sorts 

  RAMPORTB = 0; //1000000,  to set pin 13 on low/0v
  for (long i = 0; i < 1000000; i++) {RAMPORTB = 0;} //to wastte some time in order to act as a "delay"of sorts
}
