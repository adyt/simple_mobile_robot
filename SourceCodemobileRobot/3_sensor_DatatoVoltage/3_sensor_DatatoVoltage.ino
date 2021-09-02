const int potPinA = 2;              // sensor kiri
const int potPinB = 15;              // sensor kanan
int sensor_kiri;                    // deklarasi variable sensor kiri 
int sensor_kanan;                    // deklarasi variable sensor kanan

float voltage_kiri;                 // deklarasi variabel voltage dari sensor kiri 
float voltage_kanan;                // deklarasi variabel voltage dari sensor kanan

void setup() {
  Serial.begin(9600);               // Inisialisasi Penggunaan serial dengan baudrate 9600bps
}

void loop() {
   
  sensor_kiri=analogRead(potPinA);                // Baca data ADC dari potpinA ditampung di variabel sensor_kiri
  sensor_kanan=analogRead(potPinB);               // Baca data ADC dari potpinA ditampung di variabel sensor_kanan
  voltage_kiri=convert_to_voltage(sensor_kiri);
  voltage_kanan=convert_to_voltage(sensor_kanan);
  
  Serial.print(sensor_kiri);                      // Data yang ditampung dikirimkan ke serial monitor tanpa new line atau ln
  Serial.write('\t');                             // create tab
  Serial.print(sensor_kanan);                   // menampilkan data sensor kanan disertai new line
  Serial.write('\t');                             // create tab
  Serial.print(voltage_kiri);                   // menampilkan data sensor kanan disertai new line
  Serial.write('\t');                             // create tab
  Serial.println(voltage_kanan);                   // menampilkan data sensor kanan disertai new line  
}





