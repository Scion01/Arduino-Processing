int potPin=0;

void setup() {
  
  // sets the button pin as input
  pinMode(potPin,INPUT);

  //allows us to begin to serial comm. from the arduino

  Serial.begin(9600);
}

void loop() {
  // prints the button state to the terminal
  Serial.println(analogRead(potPin));
  delay(50);
}

