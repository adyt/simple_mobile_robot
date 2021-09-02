#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = ""; // silahkan diisi tokon masing masing yg dikirimkan ia email
char ssid[] = "Hallo";
char pass[] = "12345678";

const int analogPin = 34;  // Analog input pin 0 (GPIO 36)
int sensorValue = 0;  // Value read from the ADC

BlynkTimer timer;

void setup() {
  Serial.begin(9600); // Initialize serial monitor output at 9600 bps:
  Blynk.begin(auth, ssid, pass);  // Connect to Blynk Cloud
  timer.setInterval(1000L, AnalogPinRead);  // Run sensor scan 4 times a second
}

void AnalogPinRead() {
  sensorValue = analogRead(analogPin);  // Read the analog in value:
  Serial.print("sensor = ");  // Print the results...
  Serial.println(sensorValue);  // ...to the serial monitor:
 // Blynk.virtualWrite(V0, sensorValue);  // Send the results to Gauge Widget
}

void loop() {
  Blynk.run();
  timer.run();
}
