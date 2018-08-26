#include <IRremote.h>
IRsend irsend;
int kHz = 38;
int y = 0;
unsigned int wakeUp[] = {9150,3000,3050,3050,3100,3000,6150,3000,3050,3000,6150,3000,6050,3050,3100,3000,6100};
unsigned int powerOff[]= {9150,3050,3000,3100,3000,3100,6050,3100,3000,3050,6050,3100,3050,3050,6000,3100,6050};
unsigned int stepUp[]= {9100,3050,6050,3100,6050,3050,3050,3050,6050,3100,2950,3150,6000,3100,3000,3050,3050};
void setup()
{
  Serial.begin(9600);
}
 
void loop() {
  if (Serial.available() > 0)
    {
    int y = Serial.read();
    int x = y-48;
    Serial.println("Ha)|(MuTe kHoiiky: ");
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
     
     
    }
            }
