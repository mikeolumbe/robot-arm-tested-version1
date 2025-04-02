#include <Servo.h>

Servo myservo1;   //The Arm  // create servo object to control a servo

Servo myservo2;   //The gripper
int pos = 30;    // variable to store the servo position

int pos1 = 0;

void setup() {
  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);
  Serial.begin(9600); // Initialize serial communication for debugging (optional)
}

void loop() {

  // MOVE ARM UP *************************************************
  Serial.println("Moving arm up..."); //optional serial print.
  for (pos = 30; pos <= 180; pos += 1) { // goes from 30 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold grip for 1 second

  //RELEASE THE ARM *************************************************
  Serial.println("release..."); //optional serial print.
  //for (pos1 = 30; pos1 <= 180; pos1 += 1) 
  { // goes from 30 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold grip for 1 second

  // MOVE ARM DOWN ************************************************
  Serial.println("Moving arm down..."); //optional serial print.
  for (pos = 180; pos >= 30; pos -= 1) { // goes from 180 degrees to 30 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold ungrip for 1 second

  //GRAB OBJECT *****************************************************
  Serial.println("Grabbing..."); //optional serial print.
  for (pos1 = 0; pos1 <= 60; pos1 += 1) 
  { // goes from 60 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold grip for 1 second


  //Alternative grip/ungrip using direct writes.
  /*
  Serial.println("Gripping...");
  myservo.write(90); //grip
  delay(1000);

  Serial.println("Ungripping...");
  myservo.write(0); //ungrip
  delay(1000);
  */
}