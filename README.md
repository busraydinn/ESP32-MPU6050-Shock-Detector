# <p align="center">ESP32 MPU6050 Shock Detector</p>
<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Microcontroller-red?style=for-the-badge&logo=espressif" />
  <img src="https://img.shields.io/badge/MPU6050-Gyroscope-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Adafruit-IO-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/WiFi-green?style=for-the-badge&logo=wifi" />
</p>

## Proje Hakkında
ESP-32S WiFi+Bluetooth çift modlu geliştirme kartını kullandım. MPU6050 ivme ölçerin gyro özelliğini kullanarak sarsıntı ölçer cihazı geliştirdim. Sarsıntı olduğunu hem kullandığım led ile gösterirken hem de Wifi modülü ile Adafruit üzerinden sarsıntı olduğu zaman bilgisini kullanıcıya iletilmektedir.

---

## 🛠️ Gereksinimler ve İhtiyaçlar

### Kullanılan Devre Elemanları ve Özellikleri

Projede kullanılan devre elemanları ve özellikleri verilmiştir.

### 1. MPU6050 – 6 Eksen İvme ve Gyro Sensörü

<img src="https://github.com/user-attachments/assets/6e5a69b4-eb70-4190-9964-8c441404e798" width="200" alt="MPU6050 6 Eksen İvme ve Gyro Sensörü" align="center" />

MPU6050: Robotik projelerde sıklıkla kullanılan üzerinde 3 eksenli bir gyro ve 3 eksenli bir açısal ivme ölçer bulunduran 6 eksenli bir IMU sensör kartıdır. Kart üzerinde voltaj regülatörü bulunduğundan 3V ile 5V arası besleme voltajı ile çalıştırılabilir.

### 2. ESP-32S WiFi + Bluetooth Geliştirme Kartı
<img width="200" height="150" alt="image" src="https://github.com/user-attachments/assets/bcac293f-fa54-4fd3-9df9-448b2f2b565f" align="center"/>

ESP32: Bluetooth ve WiFi özelliği olan, düşük maliyetli ve düşük güçlü bir mikrodenetleyici sistemdir. Espressif Systems tarafından oluşturulup geliştirilmiştir
## Diğer Elemanlar
<img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/f8e9af94-2f34-4653-81a0-7f4cfd5d0664" />
<img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/2f5a43af-2ad4-49a9-acd6-ea727ccb4472" />
<img width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/fa6cf2a5-8390-4653-bbfe-7f88ad77c4db" />
<img  width="200" height="200" alt="image" src="https://github.com/user-attachments/assets/d563600d-b046-486c-946c-4d1b706858f5" />

---
## Test ve Uygulama
 Arduino IDE üzerinde geliştirdiğim projemde hedefim MPU6050 sensörü ile sarsıntı ölçmek ve elde ettiğim sarsıntı bilgisini ESP32’nin WiFi modülü ile Adafruit’e iletmekti. Sarsıntı tespitini, sensörün Gyro özelliğinden aldım. Sensörden gelen gyro verilerini belirli bir aralığın üzerinde olduğu durumda sistem tarafından algılanması için offset değerleri belirledim. Offset değerlerim pos_offset ve neg_offset olarak ikiye ayırdım. Pos_offset için bu değerim +1 iken neg_offset için bu değeri -1 olarak verdim. Kütüphane olarak <TinyMPU6050.h> kütüphanesini kullandım. Bu kütüphaneye ait metotlardan projemde yararlandım.
  GyroX, GyroY, GyroZ değerlerim pos_offset ve neg_offset değerlerinin dışında bir değer aldığında sistem “SARSINTI” mesajını ekrana yazdırmakta ve aynı zamanda breadboard üzerindeki led ile kullanıcıya uyarı vermektedir. 
##### Titreşim Olmadığında
<img width="150" height="150" alt="image" src="https://github.com/user-attachments/assets/f4c3f38f-55ce-402e-ac1c-a28025bce0dd" />
#### Titreşim Olduğunda
<img width="150" height="150" alt="image" src="https://github.com/user-attachments/assets/e1ead6b3-9f63-44fe-8316-f373f7d2a6d6" />
