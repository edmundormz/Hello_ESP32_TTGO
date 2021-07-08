#include <NewPing.h>
 
#define TRIGGER_PIN  22
#define ECHO_PIN     23
//#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN);
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
