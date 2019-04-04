import processing.serial.*;
Serial port;

String temp="";

String data;
int index=0;
PFont font; //processing font

void setup(){
  size(1000,700);
  port=new Serial(this,"COM3",9600);
  port.bufferUntil('\n'); //keep looking until the end
  font = loadFont("Arial-BoldMT-200.vlw"); //do  this by tools->create font
  textFont(font,120);
}

void draw(){
  background(0,0,0);
  fill(46,209,2);
  text(temp,175,175);

}
void serialEvent(Serial port){
  data= port.readStringUntil('\n');

  temp= data.substring(0,5)+"\n"+data.substring(5,data.length()-1);
}