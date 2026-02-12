#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "secrets.h"

#define PWMA D5
#define AIN1 D7
#define AIN2 D6

ESP8266WebServer server(80);

String webpage = R"====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Orion Motor UI</title>
<style>
body {
  margin: 0;
  background: #111;
  color: white;
  font-family: -apple-system, BlinkMacSystemFont, sans-serif;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  height: 100vh;
}

h1 {
  margin-bottom: 40px;
  font-weight: 500;
}

.button {
  width: 80%;
  max-width: 300px;
  padding: 25px;
  margin: 15px;
  font-size: 22px;
  border: none;
  border-radius: 15px;
  color: white;
  transition: 0.2s;
}

.forward { background: #2ecc71; }
.backward { background: #e74c3c; }
.stop { background: #3498db; }

.button:active {
  transform: scale(0.95);
  opacity: 0.8;
}

.status {
  margin-top: 30px;
  font-size: 18px;
  opacity: 0.8;
}
</style>
</head>
<body>

<h1>Orion Motor</h1>

<button class="button forward"
  ontouchstart="sendCmd('forward')"
  ontouchend="sendCmd('stop')"
  onmousedown="sendCmd('forward')"
  onmouseup="sendCmd('stop')">
  Forward
</button>

<button class="button backward"
  ontouchstart="sendCmd('backward')"
  ontouchend="sendCmd('stop')"
  onmousedown="sendCmd('backward')"
  onmouseup="sendCmd('stop')">
  Backward
</button>

<div class="status" id="status">Stopped</div>

<script>
function sendCmd(cmd) {
  fetch('/' + cmd);
  document.getElementById("status").innerText = cmd.toUpperCase();
}
</script>

</body>
</html>
)====";

void motorForward() {
  analogWrite(PWMA, 0);
  delay(50);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 500);
}


void motorBackward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 500);
}

void motorStop() {
  analogWrite(PWMA, 0);
}

void setup() {
  Serial.begin(115200);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  analogWrite(PWMA, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Ligando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  server.on("/forward", []() {
    motorForward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/backward", []() {
    motorBackward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/stop", []() {
    motorStop();
    server.send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
