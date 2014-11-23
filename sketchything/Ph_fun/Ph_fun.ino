//Ph Senser clean code

#include <SoftwareSerial.h>
#define rx 0
#define tx 1

SoftwareSerial PhSerial(rx, tx);

char ph_data[20]; //20 byte char array to hold incoming data from PH 
char computerdata[20]; // 20 byte char to hold incomming data from PC
byte recived_from_computer = 0; //Knowing how many have been recived
byte recived_from_sensor = 0; //recived cheack
byte arduino_only = 0; // odd arduino only thing not sure

byte startup = 0; // make sure arduino takes over control of the PH Circuit
float ph = 0; //another take over cheak
byte string_recived = 0; //used to identify when we have recived a string from PH circuit

void setup(){
  Serial.begin(9600);
  PhSerial.begin(9600);
}

void serialEvent(){
  if(arduino_only != 1){
    recived_from_computer = Serial.readBytesUntil(13, computerdata, 20);
    
    computerdata[recived_from_computer] = 0;
    
    PhSerial.print(computerdata);
    
    PhSerial.print('\r');
  }
}

void loop(){
  if(PhSerial.available() > 0){
    recived_from_sensor = PhSerial.readBytesUntil(13, ph_data, 20);
    
    ph_data[recived_from_sensor] = 0;
    
    string_recived = 1;
    
    Serial.println(ph_data);
  }
  if(arduino_only==1){Arduino_Control();}
  
}


void Arduino_Control(){
  if(startup == 0){
    PhSerial.print("c,0\r");
    delay(50);
    PhSerial.print("c,0\r");
    delay(50);
    
    startup = 1;
  }
  
  delay(800);
  PhSerial.print("R\r");
  if(string_recived==1){
    ph=atof(ph_data);
    if(ph >= 7.5){Serial.println("high\r");}
    if(ph < 7.5){Serial.println("low\r");}
    string_recived = 0;
  }
}
