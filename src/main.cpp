#include <Arduino.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(DIN1, INPUT);
    pinMode(DIN2, INPUT);
    pinMode(DIN3, INPUT);
    pinMode(DIN4, INPUT);
    pinMode(DIN5, INPUT);
    pinMode(DIN6, INPUT);
    pinMode(DIN7, INPUT);
    pinMode(DIN8, INPUT);

    pinMode(LOCK_OPEN, OUTPUT);
    pinMode(LOCK_CLOSED, OUTPUT);

    Serial.begin(115200);
}

void loop() {
   digitalWrite(LED_BUILTIN, HIGH);
   delay(50);
   digitalWrite(LED_BUILTIN, LOW);
   delay(950);

   bool din1 = digitalRead(DIN1);
   bool din2 = digitalRead(DIN2);
   bool din3 = digitalRead(DIN3);
   bool din4 = digitalRead(DIN4);
   bool din5 = digitalRead(DIN5);
   bool din6 = digitalRead(DIN6);
   bool din7 = digitalRead(DIN7);
   bool din8 = digitalRead(DIN8);

   Serial.print(" DIN1:");
   Serial.print(din1);
   Serial.print(" DIN2:");
   Serial.print(din2);
   Serial.print(" DIN3:");
   Serial.print(din3);
   Serial.print(" DIN4:");
   Serial.print(din4);
   Serial.print(" DIN5:");
   Serial.print(din5);
   Serial.print(" DIN6:");
   Serial.print(din6);
   Serial.print(" DIN7:");
   Serial.print(din7);
   Serial.print(" DIN8:");
   Serial.print(din8);

   Serial.print(" => ");

   bool lockstate = ((not (din1 xor din2)) and (not (din2 or din3))) and (din4 and (din5 and din6)) and ((not (din5 and din6)) xor (not (din7 xor din8)));
   Serial.println(lockstate ? "OPEN" : "LOCKED");

   digitalWrite(LOCK_OPEN, lockstate);
   digitalWrite(LOCK_CLOSED, !lockstate);
}
