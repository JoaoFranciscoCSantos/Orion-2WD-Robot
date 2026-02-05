#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// ===== TFT PIN DEFINITIONS =====
#define TFT_CS   D2
#define TFT_DC   D1
#define TFT_RST  D0

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// ===== QTR SENSOR PIN =====
#define QTR_PIN D6

// Threshold (ajustar conforme teste)
#define LINE_THRESHOLD 1500

unsigned long readQTR() {

  pinMode(QTR_PIN, OUTPUT);
  digitalWrite(QTR_PIN, HIGH);
  delayMicroseconds(10);

  pinMode(QTR_PIN, INPUT);

  unsigned long startTime = micros();

  while (digitalRead(QTR_PIN) == HIGH) {
    if ((micros() - startTime) > 3000)
      break;
  }

  return micros() - startTime;
}

void showMessage(String msg, uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 30);
  tft.println("QTR TEST");

  tft.setTextSize(3);
  tft.setTextColor(color);
  tft.setCursor(20, 100);
  tft.println(msg);
}

void setup() {

  Serial.begin(115200);

  tft.init(240, 320);
  tft.setRotation(1);

  showMessage("Booting...", ST77XX_YELLOW);

  delay(1000);
}

void loop() {

  unsigned long sensorValue = readQTR();

  Serial.println(sensorValue);

  if (sensorValue > LINE_THRESHOLD) {
    showMessage("Linha Detectada", ST77XX_GREEN);
  } else {
    showMessage("Sem Linha", ST77XX_RED);
  }

  delay(500);
}
