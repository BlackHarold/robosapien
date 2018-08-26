#include <IRremote.h> 
  
byte bytes[4]; 
 int RECV_PIN = 11;    //вход ИК приемника 
IRrecv irrecv(RECV_PIN); 
decode_results results; 
unsigned long ir_dt, old_ir;
  
void setup() 
{ 
  Serial.begin(115200); 
  irrecv.enableIRIn(); // включить приемник 
} 
  
void loop() { 
  if (irrecv.decode(&results))  
  { 
    if (results.value > 0 && results.value < 0xFFFFFFFF) 
    { 
      ir_dt = results.value; 
      Serial.println(ir_dt, HEX);
      bytes[0] = ir_dt & 0xFF;          // преобразовать в 4-байта  
      bytes[1] = (ir_dt & 0xFF00) >> 8;  
      bytes[2] = (ir_dt & 0xFF0000) >> 16; 
      bytes[3] = (ir_dt & 0xFF000000) >> 24; 
      Serial.write( bytes,4); // отправить прочитаное значение компьютеру 
              
      if (old_ir == ir_dt){delay(250);}  //Пауза между короткими нажатиями
      else {delay(500);}// Пауза после первого нажатия и удержания(перед повторами)
      old_ir = ir_dt;
    } 
           if (results.value == 0xFFFFFFFF )
            {
             delay(120); //пауза между повторами
             Serial.write( bytes,4);
            } 
       irrecv.resume(); 
  } 
}  
