#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

// Inisialisasi objek sensor BMP180 (BMP280)
Adafruit_BMP085_Unified bmp;

void setup() {
  Serial.begin(9600);

  // Inisialisasi sensor BMP180
  if (!bmp.begin()) {
    Serial.print("Tidak dapat menemukan sensor BMP180/BMP280");
    while (1);
  }
  
  Serial.println("Sensor BMP180/BMP280 terdeteksi dengan benar!");
}

void loop() {
  // Membaca nilai tekanan udara dan suhu
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure) {
    // Menghitung ketinggian berdasarkan tekanan udara
    float pressure = event.pressure;
    float altitude = bmp.pressureToAltitude(1013.25, pressure); // 1013.25 adalah tekanan standar permukaan laut (hPa)

    // Menampilkan hasil ke Serial Monitor
    Serial.print("Tekanan: ");
    Serial.print(pressure);
Serial.print(" hPa, ");
    Serial.print("Ketinggian: ");
    Serial.print(altitude);
    Serial.println(" meter");
  } else {
    Serial.println("Tidak dapat membaca tekanan udara");
  }

  delay(2000); // Pembacaan setiap 2 detik
}
