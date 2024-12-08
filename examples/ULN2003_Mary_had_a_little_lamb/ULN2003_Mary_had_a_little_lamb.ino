#include <Geekble_MotorOrgel.h>
Geekble_MotorOrgel Sing;

int IN1 = 6;
int IN2 = 7;
int IN3 = 8;
int IN4 = 9;

void setup() {
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 

  Sing.Set_BPM_QuarterNote(120);
}

void loop() {
  motorTone(n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(n_D5, Sing.NoteLength(_eighth));
  motorTone(n_C5, Sing.NoteLength(_quarter));
  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_half));

  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_D5, Sing.NoteLength(_half));
  motorTone(n_E5, Sing.NoteLength(_quarter));
  motorTone(n_G5, Sing.NoteLength(_quarter));
  motorTone(n_G5, Sing.NoteLength(_half));

  motorTone(n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(n_D5, Sing.NoteLength(_eighth));
  motorTone(n_C5, Sing.NoteLength(_quarter));
  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_half));

  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_D5, Sing.NoteLength(_quarter));
  motorTone(n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(n_D5, Sing.NoteLength(_eighth));

  motorTone(n_C5, Sing.NoteLength(_half));

  delay(5000);  // noTone
}

const int numSteps = 8;
const int steps[numSteps][4] = {
  {LOW, LOW, LOW, HIGH},  // Step 0
  {LOW, LOW, HIGH, HIGH}, // Step 1
  {LOW, LOW, HIGH, LOW},  // Step 2
  {LOW, HIGH, HIGH, LOW}, // Step 3
  {LOW, HIGH, LOW, LOW},  // Step 4
  {HIGH, HIGH, LOW, LOW}, // Step 5
  {HIGH, LOW, LOW, LOW},  // Step 6
  {HIGH, LOW, LOW, HIGH}  // Step 7
};

void motorTone(unsigned int _tone, unsigned long _length) {
  unsigned long stepDelayMicros = 1000000UL / (_tone * numSteps);
  unsigned long _startTime = millis();
  int currentStep = 0;

  while (millis() - _startTime < _length) {
    // 현재 스텝의 출력 설정
    digitalWrite(IN1, steps[currentStep][0]);
    digitalWrite(IN2, steps[currentStep][1]);
    digitalWrite(IN3, steps[currentStep][2]);
    digitalWrite(IN4, steps[currentStep][3]);

    // 스텝 간 지연 시간
    delayMicroseconds(stepDelayMicros);

    // 다음 스텝으로 이동
    currentStep = (currentStep + 1) % numSteps;
  }
}
