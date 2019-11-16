#include<SoftwareSerial.h>
SoftwareSerial btserial(D5,D6);//rx,tx
String command;
#define light D3
#define fan D4

void setup() {
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
  Serial.begin(9600);
  btserial.begin(9600);
  Serial.println("home bluetooth");
 

}

void loop() {
  while(btserial.available()) {
    char c = btserial.read();
    command += c;
    Serial.println(command);
  }
  if(command.equals("1")){
    digitalWrite(light,HIGH);
    digitalWrite(fan,LOW);
    Serial.println("light is on");
  }
  else if(command.equals("2")){
    digitalWrite(light,LOW);
    Serial.println("light is off");
  }
  else if(command.equals("3")){
    digitalWrite(fan,HIGH);
    Serial.println("fan is on");
  }
  else if(command.equals("4")){
    digitalWrite(fan,LOW);
    Serial.println("fan is off");
  } else if(command.equals("5")){
    digitalWrite(light,HIGH);
    digitalWrite(fan,HIGH);
    Serial.println("light and fan are on");
  }
  else if(command.equals("6")){
    digitalWrite(light,LOW);
    digitalWrite(fan,LOW);
    Serial.println("light and fan are off");
  }
  command = "";
}
