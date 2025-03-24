
//Header Files
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

//Variables
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define DHT_TYPE DHT11
#define DHT_PIN 4
#define SDA_PIN 2
#define SCL_PIN 3
boolean initialized = false;

//Device Variables
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() 
{
  Wire.begin(SDA_PIN, SCL_PIN);
  dht.begin();
  
  Serial.begin(9600);
  Serial.println("Initializing...");
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    return;
  }
  else{
    Serial.println("Initialized.");
    initialized = true;
    Display("???");
  }
  
  delay(1000);    
}

void loop() 
{
  if (!initialized) { return; }
  
  UpdateTemperature();
  delay(2000);
}

void UpdateTemperature(){
 float ft = dht.readTemperature(true);
  
  if (isnan(ft)) {
    return;
  }

  int f = (int)ft;
  
  display.clearDisplay();

  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(40, 18);
  display.println(f);
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(90, 14);
  display.println("o");
  
  display.display();
}

void Display(String text){
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(text);
  display.display(); 
}
