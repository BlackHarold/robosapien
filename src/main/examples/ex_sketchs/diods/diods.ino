//урок от Дмитрия Осипова - управление arduino ИК пультом
#include <IRremote.h> // это скачанная библиотека

int RECV_PIN = 11; //вход ИК приемника
IRrecv irrecv(RECV_PIN);
decode_results results;
int a=0; // переменная переключения режима, при нажатии кнопки она принимает значение +1
int b=0; //
 

void setup()
{
irrecv.enableIRIn(); // включить приемник
pinMode(3, OUTPUT);
pinMode(4, OUTPUT); // назначаем пины как выходы
Serial.begin(9600);
} 

void loop() {
if (irrecv.decode(&results)) {
delay(300); // задержка перед выполнением определения кнопок, чтобы избежать быстрое двойное нажатие
if (results.value == 0x2FD48B7) {a++;} // обработка нажитя клавиши, здесь переменная принимает значение +1
if (results.value == 0x800FF) {b++;}

// начинаем включать светодиоды на пинах
if (a==1){digitalWrite(3, HIGH);} 
else {digitalWrite(3, LOW); a=0;} // действие после нажатия кнопки, если переменная стала равна 1 то
if (b==1){digitalWrite(4, HIGH);} 
else {digitalWrite(4, LOW); b=0;} // произвести переключение пина в режим HIGH, если 
//же нет то вернуть переменную в исходное состояние


{ //
delay(50); //пауза между повторами //
} //
irrecv.resume();
// 

}

}

