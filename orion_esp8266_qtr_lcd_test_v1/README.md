# ESP8266 QTR + LCD Test v1

Firmware: `orion_esp8266_qtr_lcd_test_v1.ino`

---

## 📌 Descrição

Este módulo testa a leitura de um sensor do array Pololu QTR-8RC utilizando a placa NodeMCU HW-389 (ESP8266) e apresenta o resultado no display TFT SPI.

Quando o sensor detecta uma linha preta:

- É apresentada a mensagem **"Linha Detectada"** no LCD
- A leitura do sensor é exibida no Serial Monitor

Quando não detecta linha:

- É apresentada a mensagem **"Sem Linha"**

---

## 🎯 Objetivo

- Validar funcionamento do QTR-8RC
- Implementar leitura por temporização (método RC)
- Confirmar contraste entre superfície branca e preta
- Integrar sensor com interface visual no LCD

---

## 🧩 Hardware Utilizado

- NodeMCU v1.0 HW-389 (ESP8266)
- Display TFT SPI (ST7789)
- Pololu QTR-8RC

---

## 🔌 Ligações

### TFT SPI

| TFT | NodeMCU |
|------|----------|
| SCL  | D5 |
| SDA  | D7 |
| CS   | D2 |
| DC   | D1 |
| RST  | D0 |
| BL   | 3.3V |
| VCC  | 3.3V |
| GND  | GND |

> Evitar utilizar D3, D4 e D8 devido a restrições de boot do ESP8266.

---

### QTR-8RC (Teste com 1 sensor)

| QTR | NodeMCU |
|------|----------|
| VCC | 3.3V |
| GND | GND |
| OUT1 | D6 |
| LEDON | 3.3V |

---

## ⚙️ Funcionamento

O QTR-8RC funciona por descarga RC:

1. O pino é carregado como OUTPUT HIGH.
2. O pino passa para INPUT.
3. Mede-se o tempo até o sinal cair para LOW.
4. Superfície preta → descarga lenta → valor alto.
5. Superfície branca → descarga rápida → valor baixo.

A decisão é feita com base num `LINE_THRESHOLD` configurável.

---

## 📊 Valores Típicos

| Superfície | Valor aproximado |
|------------|------------------|
| Branco     | 200 – 800 µs |
| Preto      | 1500 – 3000+ µs |

O threshold deve ser ajustado conforme o ambiente.

---

## 🧠 Problemas Comuns

- Mau contacto nos pinos do QTR
- LEDON não ligado (sensores IR desligados)
- Uso incorreto de versão analógica (QTR-8A)
- Uso de pinos críticos de boot no ESP8266

---

## 🚀 Próximos Passos

- Ler múltiplos sensores simultaneamente
- Exibir padrão dos sensores no LCD
- Implementar lógica básica de seguidor de linha
- Integrar controlo de motores 2WD

---

## 📦 Versão

v0.4 – Teste funcional do QTR-8RC com feedback visual no LCD