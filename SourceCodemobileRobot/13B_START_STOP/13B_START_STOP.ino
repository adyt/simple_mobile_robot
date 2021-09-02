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
int sta=0;

BlynkTimer timer;
void myTimerEvent()
{ 
  Blynk.virtualWrite(V5, voltage_kiri * 1000);
  Blynk.virtualWrite(V6, voltage_kanan * 1000);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  sta=pinValue;
  Serial.println(sta);
  // process received value
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  read_voltage_all_sensor();                   
}



