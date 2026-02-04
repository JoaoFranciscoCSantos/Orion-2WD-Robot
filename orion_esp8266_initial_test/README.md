# ESP8266 Bring-up Test

Firmware: `orion_esp8266_initial.test.ino`

---

## 📌 Objetivo

Este firmware valida o funcionamento básico da board NodeMCU v1.0 (ESP8266).

O teste confirma:

- Comunicação Serial
- Identificação do Chip
- Leitura do tamanho da Flash
- Execução contínua do loop principal

---

## ⚙️ Configuração da Board no Arduino IDE

Antes de compilar e enviar o firmware, é necessário instalar o suporte ao ESP8266.

### 1️⃣ Adicionar o repositório das boards ESP8266

1. Abrir **Arduino IDE**
2. Ir a **File → Preferences**
3. No campo **Additional Boards Manager URLs**, adicionar:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

Se já existir outro URL, separar por vírgula.

Carregar em **OK**.

---

### 2️⃣ Instalar a Board ESP8266

1. Ir a **Tools → Board → Boards Manager**
2. Pesquisar por:

```
esp8266
```

3. Instalar:

```
esp8266 by ESP8266 Community
```

Aguardar a conclusão da instalação.

---

### 3️⃣ Selecionar a Board Correta

Ir a:

```
Tools → Board
```

Selecionar:

```
NodeMCU 1.0 (ESP-12E Module)
```

---

### 4️⃣ Configurações Importantes

- Baud Rate no Serial Monitor: **115200**
- Selecionar a porta COM correta
- Instalar driver **CH340** caso a board não seja reconhecida no Windows

---

## 🔎 Output Esperado

No Serial Monitor deverá aparecer:

- Cabeçalho do projeto Orion
- Chip ID
- Tamanho da Flash
- Mensagem periódica:

```
Orion ESP8266 running...
```

---

## 🎯 Finalidade no Projeto

Este é o primeiro passo da validação da plataforma ESP8266 no projeto Orion-2WD-Robot.

Serve como base para:

- Testes WiFi
- Implementação de servidor web
- Comunicação futura com outros módulos
- Evolução para arquitetura distribuída no robô
