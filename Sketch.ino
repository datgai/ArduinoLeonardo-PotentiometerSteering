
#include <Joystick.h>

#define joyRY A2
#define joyRZ A1
#define joyThrottle A3
#define joySteering A0

int ryAxis_ = 0;
int rzAxis_ = 0;
int throttle_ = 0;
int steering_ = 0;

const int numReadings = 10;
int readings[numReadings];

//Create the joystick
Joystick_ Joystick(0x12, JOYSTICK_TYPE_JOYSTICK, 0, 0,false,false,false,false,true,true,false,true,false,false,true);


// Set to true to test "Auto Send" mode or false to test "Manual Send" mode.
const bool testAutoSendMode = true;

unsigned long gNextTime = 0;
unsigned int gCurrentStep = 0;


void setup() {
  Serial.begin(9600);
  //set readings all to 0
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;
  }
  Joystick.begin();
}

void loop() {
  steering_ = analogRead(joySteering); //set steering_ to read pin 'joySteering'
  steering_ = map(steering_,0,1023,0,1278); //
  Serial.println(steering_);
delay(0.5);
  Joystick.setSteering(steering_);
}
