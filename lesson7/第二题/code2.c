#include <MsTimer2.h>
#define S 2
#define key 1
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S, OUTPUT);
  pinMode(key, INPUT_PULLUP);

  Serial.begin(9600);

  MsTimer2::set(1000, myTimer);
  MsTimer2::start();

  attachInterrupt(key,myKey,CHANGE);
}

int cnt = 0;
void loop() {
  digitalWrite(S, LOW);
  digitalWrite(IN1, cnt & 0x01);
  digitalWrite(IN2, (cnt >> 1) & 0x01);
  digitalWrite(IN3, (cnt >> 2) & 0x01);
  digitalWrite(IN4, (cnt >> 3) & 0x01);
  digitalWrite(S, HIGH);
}

void myTimer() {
  if (cnt >= 9) {
    cnt = 0;
  }
  else {
    cnt++;
  }
  Serial.println(cnt);
}

void myKey(){
  cnt = 0;
  Serial.println(cnt);
}
