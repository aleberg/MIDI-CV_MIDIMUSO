// midi.controller
// Sends midi program change
// Aaron Lyon April 2018

// Adapted to work with Midimuso Octex board by Dave nervoussquirrel.com August 2020

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

byte polyphonySelect1State;
byte polyphonySelect2State;
byte polyphonySelect3State;

byte stopSetPolyphony = 0;

int polyphonySelectPin1 = 2;
int polyphonySelectPin2 = 3;
int polyphonySelectPin3 = 4;

int delayTimeBetweenCommands = 50;

void setup() {

  pinMode(polyphonySelectPin1, INPUT);
  pinMode(polyphonySelectPin2, INPUT);
  pinMode(polyphonySelectPin3, INPUT);
  pinMode(13, OUTPUT);

  MIDI.begin(MIDI_CHANNEL_OMNI);

}

void loop() {


  polyphonySelect1State = digitalRead(polyphonySelectPin1);
  polyphonySelect2State = digitalRead(polyphonySelectPin2);
  polyphonySelect3State = digitalRead(polyphonySelectPin3);




  if ((polyphonySelect1State == HIGH) && (stopSetPolyphony != 1)) { // Set to mono with retrigger off

    MIDI.sendProgramChange(99, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(10, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(100, 1);

    stopSetPolyphony = 1;

  }

  if ((polyphonySelect2State == HIGH) && (stopSetPolyphony != 2)) { // Set to mono with retrigger on

    MIDI.sendProgramChange(99, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(10, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(101, 1);

    stopSetPolyphony = 2;

  }

  if ((polyphonySelect3State == HIGH) && (stopSetPolyphony != 3)) { // Set to 12 note polyphony with retrigger off

    MIDI.sendProgramChange(99, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(9, 1);
    delay(delayTimeBetweenCommands);
    MIDI.sendProgramChange(100, 1);

    stopSetPolyphony = 3;

  }





}
