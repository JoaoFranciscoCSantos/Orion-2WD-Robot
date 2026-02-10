# ESP8266 Web Control v1

Firmware: `orion_esp8266_web_control_v1.ino`

---

## 🎥 Demonstração em Vídeo

[▶ Ver demonstração no YouTube](https://youtube.com/shorts/GS2C35gP7ic?feature=share)

---

## 📌 Descrição

Este módulo implementa uma interface web simples para controlo remoto do ESP8266 através de um smartphone ou browser.

A página web disponibiliza dois botões:

- 👍 Liked
- 👎 Disliked

Cada botão envia um pedido HTTP ao ESP8266, que responde imprimindo uma mensagem diferente no Serial Monitor.

---

## 🎯 Objetivo

- Validar comunicação WiFi
- Implementar servidor web embutido no ESP8266
- Testar interação remota via browser
- Criar base para controlo futuro de motores do Orion

---

## 🏗 Arquitetura

ESP8266 atua como:

- Cliente WiFi (liga-se ao router)
- Servidor HTTP na porta 80
- Interface web responsiva para smartphone

Fluxo:

Browser → Pedido HTTP → ESP8266 → Serial Output

---

## 🔐 Segurança

As credenciais WiFi **não estão incluídas no repositório**.

É utilizado um ficheiro separado:

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

O ficheiro `secrets.h` está incluído no `.gitignore`.

---

## ⚙️ Configuração

1. Criar ficheiro `secrets.h`
2. Inserir SSID e password
3. Selecionar board:
   ```
   NodeMCU 1.0 (ESP-12E Module)
   ```
4. Baud Rate: 115200
5. Fazer upload

---

## 📱 Como Testar

1. Abrir Serial Monitor
2. Aguardar mensagem:
   ```
   Ligado!
   IP: 192.168.X.X
   ```
3. No smartphone (mesma rede WiFi), abrir:
   ```
   http://IP_MOSTRADO
   ```
4. Pressionar os botões
5. Ver mensagens no Serial Monitor:
   ```
   Gostei
   Nao Gostei
   ```

---

## 🚀 Próximos Passos

- Substituir prints por controlo de motores
- Implementar feedback visual na página
- Usar AJAX para evitar reload
- Migrar para WebSocket (tempo real)
- Integrar telemetria de sensores

---

## 📦 Versão

v0.2 – Primeiro painel web funcional do Orion
