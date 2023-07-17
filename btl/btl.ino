#include <Wire.h> 
#include <Servo.h>

Servo myservo;  
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  myservo.attach(3);
  lcd.init();                    
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Arduinokit.vn");
  lcd.setCursor(0,1);
  lcd.print("Xin chao cac ban");
}

void loop()
{
  for (int angle = 0; angle <= 150; angle += 1) {
    myservo.write(angle);  // Ghi giá trị góc cho servo
    delay(15);  // Delay để servo đến vị trí mới
  }

  // Điều khiển servo quay từ 180 đến 0 độ
  for (int angle = 150; angle >= 0; angle -= 1) {
    myservo.write(angle);  // Ghi giá trị góc cho servo
    delay(15);  // Delay để servo đến vị trí mới
  }
}
