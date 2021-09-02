const int potPinA = 2;    // sensor kiri
int sensor_kiri;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensor_kiri=analogRead(potPinA);
  Serial.println(sensor_kiri);
}
