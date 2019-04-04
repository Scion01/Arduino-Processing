
#include<Servo.h>
#include<math.h>
Servo servo;
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
int ledPin=13;
int buzzPin=12;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(ledPin,OUTPUT);
pinMode(buzzPin,OUTPUT);
Serial.begin(9600); // Starts the serial communication

servo.attach(11);
servo.write(0);
}
int status=0;
int v1,v2=0;

int i=0;
void call(){

    digitalWrite(buzzPin,HIGH);
    delay(500);
    digitalWrite(buzzPin,LOW);
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
v1=distance;
if(v1<25&&!status&&abs(v1-v2)<100)
{
  status++;
  servo.write(90);
  digitalWrite(ledPin,HIGH);
  call();
  delay(1000);
}
if(distance>=25&&status&&abs(v1-v2)<100){
  servo.write(0);
  status--;
  digitalWrite(ledPin,LOW);
   delay(1000);
}
v2=v1;
}
