const int potPinA = 2;                            // sensor kiri
const int potPinB = 15;                             // sensor kanan
int sensor_kiri;                                    // deklarasi variable sensor kiri 
int sensor_kanan;                                   // deklarasi variable sensor kanan

float voltage_kiri;                                 // deklarasi variabel voltage dari sensor kiri 
float voltage_kanan;                                // deklarasi variabel voltage dari sensor kanan
float vth_kanan=2.0;                                   //deklarasi variabel threshold voltage dari sensor kanan
float vth_kiri=1.4;                                  //deklarasi variabel threshold voltage dari sensor kiri

boolean warna_kanan;
boolean warna_kiri;
char* table_warna[]={"hitam", "putih"};

uint8_t enC = 18; // mot kiri
uint8_t enD = 19; // mot kiri

uint8_t enA = 16; // mot kanan
uint8_t enB = 17;// mot kanan

void setup() {
  Serial.begin(9600);                                  // Inisialisasi Penggunaan serial dengan baudrate 9600bps
  // Initialize channels 
  ledcAttachPin(enC, 1); 
  ledcAttachPin(enD, 2);
  ledcAttachPin(enA, 3); 
  ledcAttachPin(enB, 4);
                                                      // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
                                                      // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 12000, 8);                             // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);                             // 12 kHz PWM, 8-bit resolution
  ledcSetup(4, 12000, 8);
}

void loop() {
  /// Baca data ADC pada 2 sensor
  read_voltage_all_sensor();                        // return voltage_kiri(v)  dan  voltage_kanan(v)
  deteksi_warna();                                 // warna_kanan(0--> hitam/1--> putih)  warna_kiri(0--> hitam/1--> putih)
  aksi_motor();
}






