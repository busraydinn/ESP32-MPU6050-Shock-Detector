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
Arduino IDE üzerinde geliştirdiğim bu projede temel amacım, MPU6050 sensörünü kullanarak sarsıntıları algılamak ve elde edilen sarsıntı bilgisini ESP32'nin WiFi modülü aracılığıyla Adafruit platformuna iletmektir.

Sarsıntı tespiti, MPU6050 sensörünün Gyroscope (Gyro) özelliğinden elde edilen veriler kullanılarak gerçekleştirilmektedir.

Sensörden alınan gyro verilerinin belirli bir aralığın dışına çıkması durumunda sistemin sarsıntıyı algılayabilmesi için offset değerleri belirledim. Bu değerleri pos_offset ve neg_offset olmak üzere iki farklı değişken üzerinden tanımladım.

pos_offset = +1
neg_offset = -1

Projede sensör verilerinin okunması ve işlenmesi için TinyMPU6050.h kütüphanesini kullandım. Kütüphaneye ait metotlardan yararlanarak X, Y ve Z eksenlerindeki gyro verilerini takip ettim.

GyroX, GyroY ve GyroZ değerlerinden herhangi birinin belirlediğim pozitif veya negatif offset sınırlarının dışına çıkması durumunda sistem sarsıntıyı algılamaktadır.

Sarsıntı algılandığında:

Seri monitöre "SARSINTI" mesajı yazdırılmaktadır.
Breadboard üzerinde bulunan kırmızı LED yakılarak kullanıcıya görsel uyarı verilmektedir.
ESP32'nin WiFi modülü aracılığıyla sarsıntı bilgisi Adafruit platformuna iletilmektedir.

Bu sayede hem fiziksel LED uyarısı hem de internet üzerinden uzaktan bildirim sağlayan bir sarsıntı algılama sistemi geliştirilmiştir. 
 
##### Titreşim Olmadığında
<img width="150" height="150" alt="image" src="https://github.com/user-attachments/assets/f4c3f38f-55ce-402e-ac1c-a28025bce0dd" />

##### Titreşim Olduğunda
<img width="150" height="150" alt="image" src="https://github.com/user-attachments/assets/e1ead6b3-9f63-44fe-8316-f373f7d2a6d6" />
 
