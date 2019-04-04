
void setup(){
  Serial.begin(9600);
}

void loop(){
  int rawVoltage=analogRead(17);
  float celsius=((rawVoltage/1024.0)*5000)/10;
  Serial.print(celsius);
  
  delay(500);
}

