#include "WiFi.h"
  #include <HTTPClient.h>
//#include "ESP8266WiFi.h"
// WiFi parameters to be configured
const char* ssid = "TP-Link_6F2E";
const char* password = "54618497";
//const char* ssid = "Hzt";
//const char* password = "elmenchomelapela2020$";
const char* serverName = "https://backend-domotica.herokuapp.com/requests";
const int buttonBR = 14;    // the number of the pushbutton pin
const int buttonHelp = 27;
const int ledPin = 2;      // the number of the LED pin
int sound_digital = 12;
int sound_analog = 13;
int umbral = 700;
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonStateBR;             // the current reading from the input pin
int buttonStateHelp;             // the current reading from the input pin
int lastButtonStateBR = LOW;   // the previous reading from the input pin
int lastButtonStateHelp = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
void setup() {
  Serial.begin(9600);
  pinMode(buttonBR, INPUT);
  pinMode(buttonHelp, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sound_digital, INPUT); 
  //digitalWrite(ledPin, ledState);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("Conectado a internet, mi IP es:");
  // Print the IP address
  Serial.println(WiFi.localIP());
}
void loop() {
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);
Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val_digital);
Serial.print("\n");
  if (val_analog >= umbral)  
  {
    digitalWrite (ledPin, HIGH);
    delay(300);
//    if(WiFi.status()== WL_CONNECTED){
//          HTTPClient http;
//         
//          // Your Domain name with URL path or IP address with path
//          http.begin(serverName);
//          http.addHeader("Content-Type", "application/json");
//          int httpResponseCode = http.POST("{\"patient_id\":\"10\",\"type\":\"Ayuda\"}");
//          Serial.print("HTTP Response code: ");
//          Serial.println(httpResponseCode);
//             
//          // Free resources
//          http.end();
//    }
  }
  else
  {
    digitalWrite (ledPin, LOW);
  }
}
