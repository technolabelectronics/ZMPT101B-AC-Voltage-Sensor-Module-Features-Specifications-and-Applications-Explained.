#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ZMPT101B.h>
 
#define SENSITIVITY 500.0f
 
// ZMPT101B sensor output connected to ADC pin 34
// and the voltage source frequency is 50 Hz.
ZMPT101B voltageSensor(34, 50.0);
 
#define SCREEN_WIDTH 128 // ORelay display width, in pixels
#define SCREEN_HEIGHT 64 // ORelay display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define ORelay_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, ORelay_RESET);
void setup() {
  Serial.begin(115200);
  // Change the sensitivity value based on value you got from the calibrate
  // example.
  voltageSensor.setSensitivity(SENSITIVITY);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}
 
void loop() {
  // read the voltage and then print via Serial
  float voltage = voltageSensor.getRmsVoltage();
  Serial.println(voltage);
display.clearDisplay();
display.setCursor(10,0);  
display.setTextSize(2);
display.setTextColor(WHITE);
display.print("Voltage");
display.setCursor(10,25);  
display.setTextSize(3);
display.setTextColor(WHITE);
display.print(String(voltage));
display.display();
  delay(1000);
}
