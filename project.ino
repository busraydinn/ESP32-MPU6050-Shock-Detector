#include "config.h"
#include <dummy.h>
#include <TinyMPU6050.h>

float pos_offset = 1;
float neg_offset = -1;
long gyro_x, gyro_y, gyro_z, offset_x, offset_y, offset_z;


MPU6050 mpu (Wire);

AdafruitIO_Feed *counter = io.feed("DepremSarsıntı");
void setup() {

   mpu.Initialize();
  Serial.begin(115200);
  Serial.println("=====================================");
  Serial.println("Starting calibration...");
  Serial.println("Calibration complete!");
  Serial.println("Offsets:");
  Serial.print("AccX Offset = ");
  Serial.println(mpu.GetAccX());
  Serial.print("AccY Offset = ");
  Serial.println(mpu.GetAccY());
  Serial.print("AccZ Offset = ");
  Serial.println(mpu.GetAccZ());
  Serial.print("GyroX Offset = ");
  Serial.println(mpu.GetGyroXOffset());
  Serial.print("GyroY Offset = ");
  Serial.println(mpu.GetGyroYOffset());
  Serial.print("GyroZ Offset = ");
  Serial.println(mpu.GetGyroZOffset());
  
  pinMode(14,OUTPUT);
  digitalWrite(14, LOW);
  

  delay(1000);
  for(int i=0; i<100;i++){
   mpu.Execute();
  offset_x = mpu.GetGyroX();
  offset_y = mpu.GetGyroY();
  offset_z = mpu.GetGyroZ();
  }
  Serial.print("offset_x = ");
  Serial.print(offset_x);
  Serial.print("  /  offsetY = ");
  Serial.print(offset_y);
  Serial.print("  /  offsetZ = ");
  Serial.println(offset_z);
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();
for(int i=0; i<5;i++){
  mpu.Execute();
  gyro_x = mpu.GetGyroX();
  gyro_y = mpu.GetGyroY();
  gyro_z = mpu.GetGyroZ();
 }
  Serial.print("GyroX = ");
  Serial.print(gyro_x - offset_x);
  Serial.print("  /  GyroY = ");
  Serial.print(gyro_y - offset_y);
  Serial.print("  /  GyroZ = ");
  Serial.println(gyro_z - offset_z);
  

 if ( pos_offset < gyro_x - offset_x || neg_offset > gyro_x - offset_x || pos_offset < gyro_y - offset_y || 
 neg_offset > gyro_y - offset_y || pos_offset < gyro_z - offset_z || neg_offset > gyro_z - offset_z){

  for(int i=0; i<5; i++){
  digitalWrite(14,HIGH);
  
   Serial.print("sending -> ");
  Serial.println("SARSTINTI");
  counter->save("SARSINTI");
  delay(1000);
  digitalWrite(14,LOW);
  
  delay(5);
  }   
  delay(2000);  
  mpu.Execute();
  offset_x = mpu.GetGyroX();
  offset_y = mpu.GetGyroY();
  offset_z = mpu.GetGyroZ();

 }  
  // increment the count by 1

  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. In this example, we will wait three seconds
  // (1000 milliseconds == 1 second) during each loop.


}
