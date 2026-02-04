#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "secrets.h"

ESP8266WebServer server(80);

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body {
        margin: 0;
        font-family: Arial, sans-serif;
        background: linear-gradient(135deg, #0f2027, #203a43, #2c5364);
        color: white;
        text-align: center;
      }

      h1 {
        margin-top: 40px;
        font-size: 28px;
      }

      .container {
        margin-top: 50px;
      }

      .btn {
        display: block;
        width: 200px;
        margin: 20px auto;
        padding: 15px;
        font-size: 18px;
        border: none;
        border-radius: 12px;
        cursor: pointer;
        transition: 0.3s;
      }

      .btn1 {
        background-color: #00c853;
      }

      .btn2 {
        background-color: #d50000;
      }

      .btn:hover {
        transform: scale(1.05);
        box-shadow: 0 0 20px rgba(255,255,255,0.4);
      }

      footer {
        margin-top: 60px;
        font-size: 12px;
        opacity: 0.6;
      }
    </style>
  </head>

  <body>
    <h1>ORION Control Panel</h1>

    <div class="container">
      <button class="btn btn1" onclick="location.href='/btn1'">
        Liked
      </button>

      <button class="btn btn2" onclick="location.href='/btn2'">
        Disliked
      </button>
    </div>

    <footer>
      ESP8266 Web Interface v1.0
    </footer>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleButton1() {
  Serial.println("Gostei");
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleButton2() {
  Serial.println("Nao Gostei");
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

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

  server.on("/", handleRoot);
  server.on("/btn1", handleButton1);
  server.on("/btn2", handleButton2);

  server.begin();
  Serial.println("Servidor iniciado.");
}

void loop() {
  server.handleClient();
}
