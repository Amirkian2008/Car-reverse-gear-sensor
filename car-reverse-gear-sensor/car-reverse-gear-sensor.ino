
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);

//*************************Config Pin Buzzer
const int Buzzer = 8;
const int BuzzerGND = 9;
//*************************Config Pin SRF05
const int Echo = 3;
const int Trig = 2;
//*************************Config Pin Switch
const int PinSW = 12;
//*************************Config Value
int DurationSettings = 25;
String DistanceEnd;
int duration;
int distance;
int TimeDisplay;
String Value;
boolean Key;
int TimeSW;
void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(BuzzerGND, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(PinSW, INPUT_PULLUP);
  delay(2000);

}

void loop() {
  delayMicroseconds(2);
  digitalWrite(Trig , LOW );
  delayMicroseconds(10);
  digitalWrite(Trig , HIGH);
  duration = pulseIn(Echo , HIGH);
  distance = (duration / (58));
  DistanceEnd = String(distance);
  lcd.print("Fasele : ");
  lcd.print(DistanceEnd);
  lcd.setCursor(2, 1);
  lcd.print("RUBIKAMP");
  }
  int timer = 0;
  int BuzzerTime = 0;
  while(true){
    timer++;
    delay (1);
    if (digitalRead(PinSW) == 0) {
      TimeSW++;
    }
    else {
      TimeSW = 0;
    }
    if (TimeSW >= 1500) Settings();
    if (timer > 500) break;
    if (distance < DurationSettings ) {
      BuzzerTime++;
      if (BuzzerTime < distance * 4) {
        digitalWrite(Buzzer , LOW );
      }
      else {
        digitalWrite(Buzzer , HIGH );
        if (BuzzerTime > distance * 4 + 80) {
          BuzzerTime = 0;
          digitalWrite(Buzzer , LOW );
        }
      }
    }
    else {
      digitalWrite(Buzzer , LOW );
      BuzzerTime = 0;
    }
  }

void {
  digitalWrite(Buzzer , LOW );
  TimeSW = 0;
  Key = 1;
    if (digitalRead(PinSW) == 0 && Key == 0) {
      Key = 1;
      TimeSW = 0;
      DurationSettings++;
      if (DurationSettings > 99 ) DurationSettings = 5;
    }
    if (digitalRead(PinSW) == 1 && Key == 1)Key = 0;
    if (TimeSW >= 1500) break;
    delay(1);
  }
  TimeSW = 0;
