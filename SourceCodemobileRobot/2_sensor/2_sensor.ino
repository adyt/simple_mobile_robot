const int potPinA = 2;              // sensor kiri
const int potPinB = 15;              // sensor kanan
int sensor_kiri;                    // deklarasi variable sensor kiri 
int sensor_kanan;                    // deklarasi variable sensor kanan

void setup() {
  Serial.begin(9600);               // Inisialisasi Penggunaan serial dengan baudrate 9600bps
}

void loop() {
  sensor_kiri=analogRead(potPinA);  // Baca data ADC dari potpinA ditampung di variabel sensor_kiri
  sensor_kanan=analogRead(potPinB);  // Baca data ADC dari potpinA ditampung di variabel sensor_kanan
  Serial.print(sensor_kiri);      // Data yang ditampung dikirimkan ke serial monitor tanpa enter atau ln
  Serial.write('\t'); 
  Serial.println(sensor_kanan); 
}



