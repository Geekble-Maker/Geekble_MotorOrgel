#include <Geekble_MotorOrgel.h>

Geekble_Note2Freq Sing;

#define enPin 3
#define stepPin 4
#define dirPin 5

unsigned long prevStepMicros;
const bool motorDirection;

void setup() 
{
	pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);

  digitalWrite(dirPin, motorDirection);
  digitalWrite(enPin, LOW);

  Sing.Set_BPM_QuarterNote(120);
}

void loop() 
{
  motorTone(stepPin, n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_eighth));
  motorTone(stepPin, n_C5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_half));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_half));
  motorTone(stepPin, n_E5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_G5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_G5, Sing.NoteLength(_half));
  motorTone(stepPin, n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_eighth));
  motorTone(stepPin, n_C5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_half));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_quarter));
  motorTone(stepPin, n_E5, Sing.NoteLength(_dottedquarter));
  motorTone(stepPin, n_D5, Sing.NoteLength(_eighth));
  motorTone(stepPin, n_C5, Sing.NoteLength(_half));
  delay(5000);}

void motorTone(byte singleStepPin, unsigned int _tone, unsigned long _length)
{
  digitalWrite(enPin, LOW);
  unsigned int motorSpeeds = (1000000 / _tone);
  unsigned long _startTime = millis();
  while(millis() < (_startTime + _length))
  {
    if ((micros() - prevStepMicros >= motorSpeeds) && (motorSpeeds != 0))
    {
      prevStepMicros += motorSpeeds;
      digitalWrite(singleStepPin, HIGH);
      digitalWrite(singleStepPin, LOW);
    }
  }
  digitalWrite(enPin, HIGH);
}