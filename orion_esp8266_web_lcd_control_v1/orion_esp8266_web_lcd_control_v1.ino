#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "secrets.h"

// ===== TFT PIN DEFINITIONS =====
#define TFT_CS   D2
#define TFT_DC   D1
#define TFT_RST  D0


Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// ===== WEB SERVER =====
ESP8266WebServer server(80);

// ===== LCD FUNCTION =====
void showMessage(String title, String message, uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 30);
  tft.println(title);

  tft.drawLine(20, 55, 220, 55, ST77XX_WHITE);

  tft.setTextColor(color);
  tft.setTextSize(3);
  tft.setCursor(20, 100);
  tft.println(message);
}

// ===== WEB PAGE =====
void handleRoot() {

  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body {
        font-family: Arial;
        text-align: center;
        background: #111;
        color: white;
      }
      button {
        width: 200px;
        padding: 15px;
        margin: 20px;
        font-size: 18px;
        border-radius: 10px;
        border: none;
        cursor: pointer;
      }
      .green { background:#00c853; }
      .red { background:#d50000; }
    </style>
  </head>
  <body>
    <h2>ORION Control Panel</h2>
    <button class="green" onclick="location.href='/btn1'">Liked</button>
    <button class="red" onclick="location.href='/btn2'">Disliked</button>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

// ===== BUTTON HANDLERS =====
void handleButton1() {
  Serial.println("Gostei");
  showMessage("ORION", "Gostei", ST77XX_GREEN);

  server.sendHeader("Location", "/");
  server.send(303);
}


void handleButton2() {
  Serial.println("Nao Gostei");
  showMessage("ORION", "Nao Gostei", ST77XX_RED);

  server.sendHeader("Location", "/");
  server.send(303);
}

// ===== SETUP =====
void setup() {

  Serial.begin(115200);
  delay(1000);

  // TFT INIT
  tft.init(240, 320);   // altera se for 240x320
  tft.setRotation(1);

  showMessage("ORION", "Booting...", ST77XX_YELLOW);

  // WIFI
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("A ligar ao WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Ligado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  showMessage("WiFi OK", WiFi.localIP().toString(), ST77XX_CYAN);

  // WEB ROUTES
  server.on("/", handleRoot);
  server.on("/btn1", handleButton1);
  server.on("/btn2", handleButton2);

  server.begin();
  Serial.println("Servidor iniciado.");
}

// ===== LOOP =====
void loop() {
  server.handleClient();
}
