int ledPin=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Now use serial monitor to send data to the UNO
  while(Serial.available()==0);
  int val= Serial.read()-'0';
  if(val==1){
    Serial.println("Led is ON!!!!!!!!!");
    digitalWrite(ledPin,HIGH);
  }
  if(val==0){
    Serial.println("Led is OFF!!!!!!!!!");
    digitalWrite(ledPin,LOW);
  }
     Serial.flush();

 
}
