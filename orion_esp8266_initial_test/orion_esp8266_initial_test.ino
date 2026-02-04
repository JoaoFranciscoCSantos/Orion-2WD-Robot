/*
  Orion-2WD-Robot
  ESP8266 Bring-up Test
  Board: NodeMCU v1.0 (ESP-12E Module)
  Author: João Santos
*/

void setup() {
  Serial.begin(115200);
  delay(1000); // Pequena pausa para estabilizar

  Serial.println();
  Serial.println("=================================");
  Serial.println("   ORION 2WD ROBOT - BRINGUP    ");
  Serial.println("=================================");
  Serial.println("ESP8266 inicializado com sucesso!");
  Serial.println();
  Serial.print("Chip ID: ");
  Serial.println(ESP.getChipId());

  Serial.print("Flash Chip Size: ");
  Serial.print(ESP.getFlashChipSize() / (1024 * 1024));
  Serial.println(" MB");

  Serial.println();
  Serial.println("Sistema pronto.");
  Serial.println("---------------------------------");
}

void loop() {
  Serial.println("Orion ESP8266 running...");
  delay(2000);
}
