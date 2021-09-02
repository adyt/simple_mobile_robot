


void read_voltage_all_sensor()
{
  sensor_kiri=analogRead(potPinA);                // Baca data ADC dari potpinA ditampung di variabel sensor_kiri
  sensor_kanan=analogRead(potPinB);               // Baca data ADC dari potpinA ditampung di variabel sensor_kanan
  voltage_kiri=convert_to_voltage(sensor_kiri);
  voltage_kanan=convert_to_voltage(sensor_kanan); 
  }




float convert_to_voltage(int xx)
{ float temp;
  temp = xx * (3.3 / 4096.0);
  return temp; 
  }


