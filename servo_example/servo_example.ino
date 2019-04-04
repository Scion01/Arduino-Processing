#include<Servo.h>

Servo servo;
void setup() {
  servo.attach(5);
  servo.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<180;i++){
    servo.write(i);
    delay(50);
  }
  for(i=0;i<180;i=i+5){
    servo.write(179-i);
    delay(50);
  }
}
