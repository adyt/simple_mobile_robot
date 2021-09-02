void aksi_motor()
{
  if(warna_kiri==0){motki_maju();}
  else{motki_mundur();}
  
  if(warna_kanan==1){motka_maju();}
  else{motka_mundur();}
 }



void read_voltage_all_sensor()
{
  sensor_kiri=analogRead(potPinA);                // Baca data ADC dari potpinA ditampung di variabel sensor_kiri
  sensor_kanan=analogRead(potPinB);               // Baca data ADC dari potpinA ditampung di variabel sensor_kanan
  voltage_kiri=convert_to_voltage(sensor_kiri);
  voltage_kanan=convert_to_voltage(sensor_kanan); 
  }

void deteksi_warna()
{
  // mencari keputusan sensor mendeteksi warna hitam atau putih
  if(voltage_kanan >= vth_kanan) warna_kanan=1; // putih=1  hitam=0
  else
    warna_kanan=0;  
    
  if(voltage_kiri >= vth_kiri) warna_kiri=1;
  else
    warna_kiri=0;
  // hasil keluarannya kalau putih=1 kalauhitam=0
  
  }


float convert_to_voltage(int xx)
{ float temp;
  temp = xx * (3.3 / 4096.0);
  return temp; 
  }


void motka_maju()
{
   ledcWrite(3, 255);
   ledcWrite(4, 0);
  }

void motka_mundur()
{
   ledcWrite(3, 0);
   ledcWrite(4, 255);
  }
void motki_maju()
{
  ledcWrite(1, 0);
  ledcWrite(2, 255);
  }

void motki_mundur()
{
   ledcWrite(1, 255);
   ledcWrite(2, 0);
  }
void maju()
{
  ledcWrite(1, 0);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
  ledcWrite(4, 0); 
  }

 void kanan()
 {
   ledcWrite(3, 0);
   ledcWrite(4, 255);
   ledcWrite(1, 0);
   ledcWrite(2, 255);
  
  } 
 void kiri()
 {
   ledcWrite(3, 255);
   ledcWrite(4, 0);
   ledcWrite(1, 255);
   ledcWrite(2, 0); 
  } 
  
  void mundur()
  {

   ledcWrite(1, 255);
   ledcWrite(2, 0);
   ledcWrite(3, 0);
   ledcWrite(4, 255); 
    }
    
 
