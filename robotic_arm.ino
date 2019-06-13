/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include <FABRIK2D.h>

#include <Servo.h>
#include <Math.h>


int shoulderlength = 103 , elbowlength =117 , wristlength=98;
int lengths[] = {shoulderlength, elbowlength, wristlength}; // 3DOF arm where shoulder to elbow is 225mm, elbow to wrist is 150mm and wrist to end effector is 100mm.
Fabrik2D fabrik2D(4, lengths); // This arm has 4 joints; one in the origin, the elbow, the wrist and the end effector.


Servo myservo,myservo1,myservo2,myservo3,myservo4;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
float ninetytime=385.0; 
void setup() {
  myservo.attach(6); 
  myservo1.attach(7);
  myservo2.attach(8);// attaches the servo on pin 9 to the servo object
  myservo3.attach(9);
  myservo4.attach(10);
    fabrik2D.setTolerance(0.5);

}

void move(Servo servo , int angle ){
  float angletime = (ninetytime/90.0)*abs(angle);
  Serial.println(angletime);
  if(angle>=0){
    servo.write(0);
    delay(angletime);
    servo.write(90);
  }
  else{
    servo.write(180);
    delay(angletime);
    servo.write(90);
  }
}

void pick(){
//  
//  move(myservo,180,true);
//  delay(500);
//  
//    move(myservo1,60,true);
//      delay(500);
//
//      move(myservo2,30,true);
//      delay(1000);
//
//      move(myservo2,30,false);
//
//            delay(500);
//
//    move(myservo1,60,false);
//          delay(500);
//
//        move(myservo,180,false);



}

void loop() {


    fabrik2D.solve2(225,0,0 , -M_PI/2.5,0, lengths);
   //fabrik2D.solve(175,0,lengths);


    Serial.print(fabrik2D.getAngle(0)* 57296 / 1000);
  Serial.print("\t");
  Serial.print(fabrik2D.getAngle(1)* 57296 / 1000);
  Serial.print("\t");
  Serial.print(fabrik2D.getAngle(2)* 57296 / 1000);
  Serial.print("\t");
  Serial.print(fabrik2D.getBaseAngle());

delay(5000);


myservo4.write(150);
delay(500);

move(myservo,-120);
delay(500);
move(myservo2,-25);
delay(100);
move(myservo1,45);
delay(2000);
move(myservo2,-25);
delay(100);
move(myservo1,45);
delay(5000);

myservo4.write(110);
delay(500);


move(myservo1,-100);
move(myservo2,50);

delay(2000);
move(myservo,120);
delay(500);
move(myservo2,-25);
delay(100);
move(myservo1,45);
delay(2000);
move(myservo2,-25);
delay(100);
move(myservo1,45);
delay(5000);

myservo4.write(150);
delay(500);

move(myservo1,-100);
move(myservo2,50);

delay(100000);

}
