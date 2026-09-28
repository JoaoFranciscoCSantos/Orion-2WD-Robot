# 🚗 Orion-2WD-Robot

Robô 2WD (Two Wheel Drive) construído de forma incremental para aprender e experimentar **sistemas embebidos, firmware e integração hardware–software**.

Cada pasta deste repositório é um passo documentado do projeto (uma "versão"), com ligações, problemas encontrados e soluções.

- ✅ Controlo de motores com driver TB6612 (um e dois motores, velocidade por PWM)
- ✅ Servidor web embebido no ESP8266 com interface para telemóvel
- ✅ Display TFT SPI integrado com o firmware
- ✅ Teste de leitura de sensor de linha (Pololu QTR-8RC)
- 🚧 Em desenvolvimento: seguimento de linha, deteção de obstáculos
- 🔜 Futuramente: Raspberry Pi, visão artificial e inteligência artificial

---

## 👨‍💻 Autor

João Santos
Projeto académico e experimental na área de Robótica e Sistemas Embebidos.

Mentoria técnica: Manuel João Santos

---

## 🛠️ Hardware Utilizado

- Microcontrolador: NodeMCU v1.0 (ESP8266)
- Driver de motores: TB6612FNG
- Motores: N20 DC Gear Motor (300 RPM)
- Alimentação: bateria 7.4V (2S) + conversor buck para o NodeMCU (recomendado)
- Display: TFT SPI 2.0" (ST7789)
- Sensor de linha: Pololu QTR-8RC (testado com 1 sensor)

---

## 📂 Estrutura do Projeto

Cada pasta contém o firmware (`.ino`) e um README com objetivo, ligações e notas.

| Pasta | O que faz | Demo |
|-------|-----------|------|
| `orion_esp8266_initial_test` | Bring-up da NodeMCU: comunicação Serial, ID do chip e tamanho da Flash | — |
| `orion_esp8266_web_control_v1` | Servidor HTTP no ESP8266 com dois botões que enviam pedidos e imprimem no Serial | [▶](https://youtube.com/shorts/GS2C35gP7ic?feature=share) |
| `orion_esp8266_web_lcd_control_v1` | Igual ao anterior, mas também atualiza um display TFT | [▶](https://youtube.com/shorts/gwjyUfx9qMI?feature=share) |
| `orion_esp8266_qtr_lcd_test_v1` | Leitura do QTR-8RC (método RC por temporização) e feedback "Linha Detectada / Sem Linha" no display | [▶](https://youtube.com/shorts/WwQfm6-C9CA?feature=share) |
| `orion_esp8266_motor_direction_cycle_v1` | Teste de hardware: motor 5 s para a frente / 5 s para trás com TB6612 | — |
| `orion_esp8266_motor_web_ui_v1` | Interface web mobile (frente/trás, touch and hold) | — |
| `orion_esp8266_motor_web_control_v1` | Interface web + controlo de um motor pelo browser | — |
| `orion_esp8266_motor_web_control_v2` | Slider de velocidade (PWM), página em PROGMEM, WiFi sleep desativado, timeout de segurança | [▶](https://youtube.com/shorts/sLTzFPbsDGI) |
| `orion_esp8266_motor_web_control_v3` | Controlo de dois motores (canais A e B do TB6612) com velocidade partilhada | [▶](https://youtube.com/shorts/ofZWXwOd44M?feature=share) |

---

## 🧠 O que já aprendi / resolvi

Problemas reais encontrados durante o desenvolvimento e documentados nos READMEs de cada pasta:

- Motor sem rodar por falta de **massa comum** entre bateria, driver e microcontrolador
- USB a desligar-se e resets por **picos de corrente** dos motores (buck converter e condensadores 470–1000 µF)
- **Pinos de boot do ESP8266** (GPIO15/D8, D3, D4) e como evitá-los
- Servidor web a bloquear por fragmentação de heap (página HTML movida para **PROGMEM**)
- Latência de ~2 s nos comandos causada pelo modo de poupança de energia do WiFi

---

## 🔐 Credenciais WiFi

As credenciais não estão no repositório. Cada projeto com WiFi usa um ficheiro `secrets.h` (incluído no `.gitignore`). Consultar o README de cada pasta para o formato esperado.

---

## 🚀 Roadmap

### Fase 1 — Validação de hardware ✅
- Bring-up do ESP8266
- Controlo de motores com TB6612 (um e dois motores)
- Controlo remoto por WiFi (interface web)
- Display TFT e teste de um sensor QTR-8RC

### Fase 2 — Movimento e sensores 🚧
- Comandos de direção (esquerda/direita) e viragem por velocidade diferencial
- Ler o array QTR completo
- Encoders e medição de RPM

### Fase 3 — Autonomia básica
- Seguimento de linha estável com controlo PID
- Deteção de obstáculos (HC-SR04) e lógica de decisão

### Fase 4 — Avançado
- Integração com Raspberry Pi
- OpenCV
- IA para navegação autónoma

---

## 📜 Licença

Este projeto está licenciado sob a MIT License.
Ver ficheiro LICENSE para mais detalhes.
