/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


#include <IRremote.h>

IRsend irsend;

void setup()
{

}

void loop() {
 int khz = 38;
  unsigned int irSignal1[18] = {9200,3000,3050,3050,3050,3000,6050,3100,3050,3050,6100,3000,6100,3050,3050,3000,6150};
  unsigned int irSignal2[] = {8950,4400,600,500,650,450,650,500,600,550,500,600,500,550,600,1650,550,550,550,1650,600,1650,550,1650,650,1550,600,1650,550,1700,600,450,600,1700,600,450,650,1600,600,500,600,500,650,1550,650,450,650,500,650,450,550,1650,650,500,650,1550,650,1550,650,450,700,1550,600,1600,600,1650,650};
  
  irsend.sendNEC(0x2FD48B7,32);
  delay(5000);


  /*irsend.sendRaw(irSignal1, 18, khz);
  delay(5000);*/

  irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), khz);
  delay(5000);

  /*irsend.sendRaw(irSignal1, sizeof(irSignal1) / sizeof(irSignal1[0]), khz);
  delay(5000);*/
  
  
  /*irsend.sendRaw(irSignal1, 66, khz);
  delay(5000);*/
/*
  irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), 38);
  delay(5000);*/
}
