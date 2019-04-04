import processing.serial.*; //import serial libraries

Serial port;            //serial instance
float brightness=0;

void setup(){
   size(1920,1080);
   port = new Serial(this,"COM3",9600); //new prot object
   port.bufferUntil('\n');
}

void draw(){ //keeps repeating 
  background(0,0,brightness);
}

void serialEvent(Serial port){//Called when data is available. Use Serial.read() to capture this data.
  brightness=float(port.readStringUntil('\n'));
}