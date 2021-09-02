#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

/*Sesuaikan dengan Auth Token saat Blynk Project dibuat (konfirmasi via e-Mail)*/
char auth[] = "";

/*Sesuaikan SSID Name dan Password Portable Hotspot yang digunakan*/
char ssid[] = "Hallo";
char pass[] = "12345678";


const int potPinA = 34;                            // sensor kiri
const int potPinB = 35;                             // sensor kanan
int sensor_kiri;                                    // deklarasi variable sensor kiri 
int sensor_kanan;                                   // deklarasi variable sensor kanan

float voltage_kiri;                                 // deklarasi variabel voltage dari sensor kiri 
float voltage_kanan;                                // deklarasi variabel voltage dari sensor kanan
float vth_kanan=2.4;                                   //deklarasi variabel threshold voltage dari sensor kanan
float vth_kiri=2.4;                                  //deklarasi variabel threshold voltage dari sensor kiri

boolean warna_kanan;
boolean warna_kiri;
char* table_warna[]={"hitam", "putih"};

uint8_t enC = 14; // mot kiri
uint8_t enD = 15; // mot kiri

uint8_t enA = 12; // mot kanan
uint8_t enB = 13;// mot kanan

int sta=0;

BlynkTimer timer;
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  sta=pinValue;
  Serial.println(pinValue);
  // process received value
}


  
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
 
  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, voltage_kiri * 1000);
  Blynk.virtualWrite(V6, voltage_kanan * 1000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
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
  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
//kiri();
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  read_voltage_all_sensor();                        // return voltage_kiri(v)  dan  voltage_kanan(v)
  deteksi_warna();   
  if(sta==1)
  {aksi_motor();}
  else
  {berhenti();}
  
 // Serial.print(voltage_kiri);Serial.println(voltage_kanan);
}

