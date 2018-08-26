#include <IRremote.h>
int RECV_PIN = 11;
int RELAY_PIN = 3;
int pin5 =5;
int vkl;

IRrecv irrecv(RECV_PIN);
decode_results results;


void dump(decode_results *results) 
      
      {
        int count = results->rawlen;
        Serial.print(results->value, HEX);
        Serial.println("");
      }

void setup()

      {
        delay (1000);
        pinMode(RELAY_PIN, OUTPUT);
        pinMode(5, OUTPUT);
        pinMode(13, OUTPUT);
        Serial.begin(9600);
        irrecv.enableIRIn(); // Start the receiver
     }
        int on = 0;
        unsigned long last = millis();

void loop() 
    
    {
if (irrecv.decode(&results)) 
    {
if (millis() - last > 250) 
    {
        on = !on;
        digitalWrite(RELAY_PIN, on ? HIGH : LOW);
        digitalWrite(13, on ? HIGH : LOW);
        dump(&results);
    }
        last = millis();
        irrecv.resume();
}

               
}
