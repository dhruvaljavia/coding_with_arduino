#include <FABRIK2D.h>
#include <Servo.h>
#define L1 10
#define L2 20
int lengths[] = {L1, L2}; //Specifying lengths of two arms
Fabrik2D fabrik2D(3, lengths); //Specifying joints and lengths

Servo b; //Base motor
Servo a1; //Shoulder motor
Servo a2; //Elbow motor

void setup() {
  Serial.begin(9600);
  b.attach(9);
  a1.attach(10);
  a2.attach(11);
  // Set tolerance to 0.5mm. If reachable, the end effector will approach
  // the target with this tolerance
  fabrik2D.setTolerance(0.5);

  fabrik2D.solve2(5, 10, 10, lengths);

  b.write(fabrik2D.getBaseAngle());
  a1.write(fabrik2D.getAngle(0)* 57296 / 1000);
  a2.write(fabrik2D.getAngle(1)* 57296 / 1000);

  Serial.println(fabrik2D.getX(2));
  Serial.println(fabrik2D.getY(2));
  Serial.println(b.read());
  Serial.println(a1.read());
  Serial.println(a2.read());  
}

void loop() {

  
}
