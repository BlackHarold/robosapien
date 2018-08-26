#include <IRremote.h>

IRsend irsend;

void setup()
{

}

void loop() {
  int kHz = 38;
  unsigned int wakeUp[] = {9150,3000,3050,3050,3100,3000,6150,3000,3050,3000,6150,3000,6050,3050,3100,3000,6100};
  unsigned int powerOff[]= {9150,3050,3000,3100,3000,3100,6050,3100,3000,3050,6050,3100,3050,3050,6000,3100,6050};
  unsigned int stepUp[]= {9100,3050,6050,3100,6050,3050,3050,3050,6050,3100,2950,3150,6000,3100,3000,3050,3050};
  
  irsend.sendRaw(wakeUp, sizeof(wakeUp)/sizeof(wakeUp[0]), kHz);
  delay(5000);

  irsend.sendRaw(powerOff, sizeof(powerOff)/sizeof(powerOff[0]), kHz);
  delay(5000);

  irsend.sendRaw(stepUp, sizeof(stepUp)/sizeof(stepUp[0]), kHz);
  delay(5000);

             }
