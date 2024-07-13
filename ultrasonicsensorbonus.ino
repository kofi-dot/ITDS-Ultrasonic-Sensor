#include <NewPing.h>

#define TRIGGER_PIN  12  // Pin 12 is connected to trigger pin on the ultrasonic sensor
#define ECHO_PIN     11  // Pin 11 is connected to echo pin on the ultrasonic sensor
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters)


// Constructor for NewPing that sets up the pins and specifies a maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
 Serial.begin(9600); // Open serial monitor at 9600 to see ping results
}

void loop() {
    int distance = sonar.ping_cm(); // Send ping and get distance in centimeters
  
    Serial.print("Ping: ");
    Serial.print(distance); // Print result
    Serial.println("cm");
    if (distance <= 10){
    } else if (distance > 10 && distance <= 100){
      Serial.println("CLOSE");
    } else if (distance > 100) {
      Serial.println("APPROACHING");
  }
  doADelay();
}

// A function that does a delay
void doADelay(){
 delay(500); // Waits for 500 milliseconds [there are 1000 milliseconds in a second]
}
