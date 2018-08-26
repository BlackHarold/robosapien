#include <IRremote.h>
IRsend irsend;
int kHz = 38;
int y = 0;
unsigned int wakeUp[] = {9150,3000,3050,3050,3100,3000,6150,3000,3050,3000,6150,3000,6050,3050,3100,3000,6100};
unsigned int powerOff[]= {9150,3050,3000,3100,3000,3100,6050,3100,3000,3050,6050,3100,3050,3050,6000,3100,6050};
unsigned int stepUp[]= {9100,3050,6050,3100,6050,3050,3050,3050,6050,3100,2950,3150,6000,3100,3000,3050,3050};
unsigned int steP[] = {9100,3050,6050,3100,6000,3100,3050,3050,6000,3100,3000,3100,3050,3050,3000,3050,6050};
unsigned int stoP[] = {9150,3050,6050,3050,6000,3100,6100,3050,6000,3100,3100,3000,3050,3050,3000,3100,2950};
unsigned int bacK[] = {9150,3000,3000,3100,3000,3100,6000,3100,6050,3100,3000,3100,3000,3050,3050,3050,3050}; 
unsigned int dancE[] = {9100,3100,6050,3050,3100,3000,3000,3100,3050,3050,6100,3050,3050,3050,6100,3000,6050 };

void setup()
{
  Serial.begin(9600);
}
 
void loop() {
    if (Serial.available() > 0)
    {
    int y = Serial.read();
    int x = y-48;
     Serial.println(x, DEC);
    
    if (x == 1){
      Serial.print("wakeUP");
      Serial.println (x);
      irsend.sendRaw(wakeUp, sizeof(wakeUp)/sizeof(wakeUp[0]), kHz);}
      
    if (x == 2){
      Serial.print("powerOff");
      Serial.println (x);
      irsend.sendRaw(powerOff, sizeof(powerOff)/sizeof(powerOff[0]), kHz);}
    
    if (x == 3){
      Serial.print("stepUp");
      Serial.println (x);
      irsend.sendRaw(stepUp, sizeof(stepUp)/sizeof(stepUp[0]), kHz);}

    if (x == 4){
      Serial.print("steP");
      Serial.println (x);
      irsend.sendRaw(steP, sizeof(steP)/sizeof(steP[0]), kHz);}

     if (x == 5){
      Serial.print("stoP");
      Serial.println (x);
      irsend.sendRaw(stoP, sizeof(stoP)/sizeof(stoP[0]), kHz);}

     if (x == 6){
      Serial.print("bacK");
      Serial.println (x);
      irsend.sendRaw(bacK, sizeof(bacK)/sizeof(bacK[0]), kHz);}

     if (x == 7){
      Serial.print("dancE");
      Serial.println (x);
      irsend.sendRaw(dancE, sizeof(dancE)/sizeof(dancE[0]), kHz);}
     
    }
            }
