#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2       // Define the pin where the DHT22 sensor is connected
#define DHTTYPE DHT22  // Define the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();                      
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  
  lcd.setCursor(0, 1);
  lcd.print("By Kalyan & Kesav");
  delay(3000); // Display the intro message for 3 seconds

  lcd.clear(); // Clear the screen for the sensor data
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  
  dht.begin();  // Initialize the DHT sensor
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Error reading");
    lcd.setCursor(0, 1);
    lcd.print("sensor data");
  } else {
    lcd.setCursor(6, 0);
    lcd.print(temperature, 1);  // Display temperature with one decimal place
    lcd.print(" C");

    lcd.setCursor(10, 1);
    lcd.print(humidity, 1);  // Display humidity with one decimal place
    lcd.print(" %");
  }

  delay(2000); // Wait for 2 seconds before updating the values
}
