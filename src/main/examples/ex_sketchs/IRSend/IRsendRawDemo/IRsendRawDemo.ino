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
  //unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendNEC(0x2FD48B7,32);
  delay(3000);
  /*unsigned int irSignal[] = {-4450,550,-600,500,-600,500,-600,550,-550,550,-550,550,-550,550,-1650,600,-550,550,-1650,550,-1700,550,-1650,550,-1650,600,-1650,550,-1650,550,-600,550,-1650,550,-600,500,-1700,550,-550,550,-550,550,-1650,550,-600,550,-550,550,-550,550,-1650,550,-600,500,-1700,550,-1650,550,-600,550,-1650,550,-1650,550,-1700,550};
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), 38);
  delay(3000);*/
  
  

}
