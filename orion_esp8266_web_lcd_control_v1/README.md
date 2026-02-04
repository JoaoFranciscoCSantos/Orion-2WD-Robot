# ESP8266 Web + LCD Control v1

Firmware: `orion_esp8266_web_lcd_control_v1.ino`

---

## 📌 Descrição

Este módulo expande o controlo web do Orion integrando um display TFT SPI.

O sistema permite:

- Controlo remoto via smartphone (interface web)
- Escrita no Serial Monitor
- Atualização em tempo real no LCD

Cada botão pressionado no browser:

- Envia pedido HTTP ao ESP8266
- Imprime mensagem no Serial
- Atualiza o display TFT

---

## 🎯 Objetivos Técnicos

- Validar comunicação WiFi
- Implementar servidor HTTP embarcado
- Integrar display SPI com ESP8266
- Sincronizar interface web com interface física
- Criar base para painel visual do robô

---

## 🧩 Hardware Utilizado

- NodeMCU v1.0 HW-389 (ESP8266)
- Display TFT SPI 2.0" (ST7789)
- Ligação via SPI hardware

---

## 🔌 Ligações

| TFT | NodeMCU |
|------|----------|
| SCL  | D5 (GPIO14) |
| SDA  | D7 (GPIO13) |
| CS   | D2 (GPIO4) |
| DC   | D1 (GPIO5) |
| RST  | D0 (GPIO16) |
| BL   | 3.3V |
| VCC  | 3.3V |
| GND  | GND |

> ⚠️ Evitar usar D3, D4 e D8 devido a restrições de boot do ESP8266.

---

## 🔐 Segurança

As credenciais WiFi estão no ficheiro:

```
secrets.h
```

Estrutura esperada:

```cpp
#ifndef SECRETS_H
#define SECRETS_H

const char* WIFI_SSID = "O_TEUP_WIFI";
const char* WIFI_PASSWORD = "A_TUA_PASSWORD";

#endif
```

Este ficheiro está excluído do repositório através do `.gitignore`.

---

## ⚙️ Configuração

1. Instalar bibliotecas:
   - Adafruit GFX
   - Adafruit ST7789

2. Selecionar board:
   ```
   NodeMCU 1.0 (ESP-12E Module)
   ```

3. Upload Speed:
   ```
   115200
   ```

4. Criar `secrets.h`

5. Fazer upload

---

## 📱 Funcionamento

Após iniciar:

- LCD mostra "Booting..."
- ESP liga ao WiFi
- IP é exibido no Serial Monitor
- Servidor HTTP é iniciado

No smartphone (mesma rede WiFi):

```
http://IP_DO_ESP
```

Botões disponíveis:

- 👍 Liked → Serial + LCD verde
- 👎 Disliked → Serial + LCD vermelho

---

## 🧠 Problemas Conhecidos

- Boot pode falhar se pinos críticos forem usados
- Alguns displays ST7789 podem apresentar offset de imagem
- Alimentação instável pode causar reinícios

---

## 🚀 Próximos Passos

- Mostrar IP no LCD
- Exibir intensidade do sinal WiFi (RSSI)
- Implementar telemetria de sensores
- Criar layout gráfico avançado
- Controlar motores 2WD via interface web

---

## 📦 Versão

v0.3 – Integração Web + LCD funcional
