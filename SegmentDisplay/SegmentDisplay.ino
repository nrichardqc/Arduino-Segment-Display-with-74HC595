/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const int INTERNAL_LED = 13;

const int SEG_A  = 7;
const int SEG_B  = 6;
const int SEG_C  = 5;
const int SEG_D  = 10;
const int SEG_E  = 11;
const int SEG_F  = 8;
const int SEG_G  = 9;
const int SEG_DP = 4;

const int pins[] =
	{
		SEG_A,
		SEG_B,
		SEG_C,
		SEG_D,
		SEG_E,
		SEG_F,
		SEG_G,
		SEG_DP
	};

const int SEG_COUNT = sizeof(pins) / sizeof(SEG_A);


const int DATA_PIN  = 2;//74HC595 14 pin data input pin SI
const int CLOCK_PIN = 5;//74HC595 11 pin clock line SCK
const int LATCH_PIN = 4;//74hc595 12 pin output memory latch line RCK

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(INTERNAL_LED, OUTPUT);

	for (int i =0; i < SEG_COUNT; i++) {
		pinMode(pins[i], OUTPUT);
	}
}

int ledLevel = HIGH;

// the loop function runs over and over again forever
void loop() {
	digitalWrite(INTERNAL_LED, ledLevel);

	for (int i = 0; i < SEG_COUNT; i++) {
		digitalWrite(pins[i], HIGH);
		delay(100);
		digitalWrite(pins[i], LOW);
	}

	ledLevel = !ledLevel;
}
