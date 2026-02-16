#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "secrets.h"

#define PWMA D5
#define AIN1 D7
#define AIN2 D6

#define PWMB D1
#define BIN1 D3
#define BIN2 D2

ESP8266WebServer server(80);

int currentSpeed = 600;
unsigned long lastCommandTime = 0;
const unsigned long timeout = 1000;

// ================= MOTOR CONTROL =================

void applySpeed() {
  analogWrite(PWMA, currentSpeed);
  analogWrite(PWMB, currentSpeed);
}

void forward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  applySpeed();
  lastCommandTime = millis();
}

void backward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);


  applySpeed();
  lastCommandTime = millis();
}

void stopAll() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

// ================= WEB PAGE (PROGMEM) =================

const char webpage[] PROGMEM = R"====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Orion Motor v2 Dual</title>
<style>
body { margin:0; background:#111; color:white; font-family:sans-serif; text-align:center; padding-top:30px; }
button { width:80%; max-width:300px; padding:20px; margin:15px; font-size:20px; border:none; border-radius:12px; color:white; }
.forward { background:#2ecc71; }
.backward { background:#e74c3c; }
.stop { background:#3498db; }
input[type=range] { width:80%; max-width:300px; }
.speed { margin-top:20px; font-size:18px; }
</style>
</head>
<body>

<h2>Orion Motor v2 Dual</h2>

<button class="forward" onclick="sendCmd('forward')">Forward</button>
<button class="backward" onclick="sendCmd('backward')">Backward</button>
<button class="stop" onclick="sendCmd('stop')">Stop</button>

<div class="speed">
  Speed: <span id="speedValue">600</span>
</div>

<input type="range" min="0" max="900" value="600"
       oninput="updateSpeed(this.value)">

<script>
let speedTimer = null;

function sendCmd(cmd) {
  fetch('/' + cmd).catch(()=>{});
}

function updateSpeed(val) {
  document.getElementById("speedValue").innerText = val;

  clearTimeout(speedTimer);
  speedTimer = setTimeout(() => {
    fetch('/speed?value=' + val).catch(()=>{});
  }, 150);
}
</script>

</body>
</html>
)====";

// ================= SETUP =================

void setup() {
  Serial.begin(115200);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  stopAll();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send_P(200, "text/html", webpage);
  });

  server.on("/forward", []() {
    forward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/backward", []() {
    backward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/stop", []() {
    stopAll();
    server.send(200, "text/plain", "OK");
  });

  server.on("/speed", []() {
    if (server.hasArg("value")) {
      currentSpeed = server.arg("value").toInt();
      if (currentSpeed > 900) currentSpeed = 900;
      applySpeed();
      Serial.println(currentSpeed);
    }
    server.send(200, "text/plain", "OK");
  });

  server.begin();
}

// ================= LOOP =================

void loop() {
  server.handleClient();

  if (millis() - lastCommandTime > timeout) {
    stopAll();
  }

  yield();
}
