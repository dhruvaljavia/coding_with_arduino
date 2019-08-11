#include <NewPing.h>
 
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
#define LED 9
int b;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
   Serial.begin(9600);
   pinMode(LED,OUTPUT);
   b=0;
}
 
void loop() {
   delay(30);
   analogWrite(LED,b);
   
   unsigned int distance = sonar.ping_cm();
   if(distance >=5 && distance<=50)
   {
    b=map(distance,5,50,0,255);
   }
   
}
