#include <NewPing.h>
#include <TimerFreeTone.h>

#define TRIGGER_PIN 12    // Pin 12 is connected to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 11       // Pin 11 is connected to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200  // Maximum distance we want to ping for (in centimeters).
const int ledG = 10;
const int ledY = 9;
const int ledR = 8;
const int buzzer = 13;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();

  if (distance > 0) {
    Serial.println(distance);

    int buzzerdelay = 100;  // Time for each beep in milliseconds
    int pause = 50;        // Pause time between beeps in milliseconds

    if (distance < 10) {
      Serial.println("IT IS TOO CLOSE!!!!");
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledR, HIGH);
        TimerFreeTone(buzzer, 300, buzzerdelay);
        delay(buzzerdelay);
        digitalWrite(ledR, LOW);
        TimerFreeTone(buzzer, 0, pause);
      }
    } 
    else if (distance >= 10 && distance <= 100) {
      Serial.println("IT IS CLOSE!");
      for (int i = 0; i < 2; i++) {
        digitalWrite(ledY, HIGH);
        TimerFreeTone(buzzer, 750, buzzerdelay);
        delay(buzzerdelay);
        digitalWrite(ledY, LOW);
        TimerFreeTone(buzzer, 0, pause);
        delay(pause);
      }
    } 
    else if (distance > 100) {
      Serial.println("APPROACHING");
      digitalWrite(ledG, HIGH);
      TimerFreeTone(buzzer, 1000, buzzerdelay);
      delay(buzzerdelay);
      digitalWrite(ledG, LOW);
      TimerFreeTone(buzzer, 0, pause);
      delay(pause);
    }
  }

  delay(200);  // Added delay to avoid rapid looping
}
