const int potPinA = 2;              // sensor kiri
const int potPinB = 15;              // sensor kanan
int sensor_kiri;                    // deklarasi variable sensor kiri 
int sensor_kanan;                    // deklarasi variable sensor kanan

float voltage_kiri;                 // deklarasi variabel voltage dari sensor kiri 
float voltage_kanan;                // deklarasi variabel voltage dari sensor kanan

float vth_kanan=2.0;                    //deklarasi variabel threshold voltage dari sensor kanan
float vth_kiri=1.4;                     //deklarasi variabel threshold voltage dari sensor kiri

boolean warna_kanan;
boolean warna_kiri;

char* table_warna[]={"hitam", "putih"};

void setup() {
  Serial.begin(9600);               // Inisialisasi Penggunaan serial dengan baudrate 9600bps
}

void loop() {
   
  sensor_kiri=analogRead(potPinA);                // Baca data ADC dari potpinA ditampung di variabel sensor_kiri
  sensor_kanan=analogRead(potPinB);               // Baca data ADC dari potpinA ditampung di variabel sensor_kanan
  voltage_kiri=convert_to_voltage(sensor_kiri);
  voltage_kanan=convert_to_voltage(sensor_kanan);

  if(voltage_kanan >= vth_kanan) warna_kanan=1; // putih=1  hitam=0
  else
    warna_kanan=0;
    
  if(voltage_kiri >= vth_kiri) warna_kiri=1;
  else
    warna_kiri=0;
  
  Serial.print(voltage_kiri);                   
  Serial.write('\t');                             
  Serial.print(voltage_kanan);                   
  Serial.write('\t');                            
  Serial.print(warna_kiri);                   
  Serial.write('\t');                            
  Serial.print(warna_kanan);                  
  Serial.write('\t');                             
  Serial.print(table_warna[warna_kiri]);    
  Serial.write('\t');                             
  Serial.println(table_warna[warna_kanan]);      
}
 



