# 🚗 Orion-2WD-Robot

Projeto de Robô 2WD (Two Wheel Drive) com:

- 🟢 Seguimento de linha
- 🚧 Deteção de obstáculos
- 🔜 Futuramente: visão artificial e inteligência artificial

---

## 👨‍💻 Autor

João Santos  
Projeto académico e experimental na área de Robótica e Sistemas Embebidos.

Mentoria técnica: Manuel João Santos

---

## 🎯 Objetivos do Projeto

- Construir um robô 2WD funcional
- Implementar algoritmo de seguimento de linha
- Integrar sensor ultrassónico para deteção de obstáculos
- Aplicar boas práticas de controlo de versões (Git/GitHub)
- Evoluir para sistemas com Raspberry Pi e visão computacional

---

## 🛠️ Hardware Base (Fase 1)

- Chassis 2WD (motores N20)
- Driver de motores (ex: L298N ou equivalente)
- Arduino (Uno / Nano)
- Sensor de linha IR
- Sensor ultrassónico HC-SR04
- Bateria + módulo step-down (LM2596)

---

## 📂 Estrutura do Projeto

```
hardware/
    esquemas/
    modelos-3d/

firmware/
    line_follower/
    obstacle_detection/

docs/
    arquitetura.md
    evolucao.md

experiments/
```

---

## 🚀 Roadmap

### Fase 1
- Movimento básico
- Testes individuais de sensores

### Fase 2
- Seguimento de linha estável
- Ajuste de PID

### Fase 3
- Deteção de obstáculos + lógica de decisão

### Fase 4 (Avançado)
- Integração Raspberry Pi
- OpenCV
- IA para navegação autónoma

---

## 📜 Licença

Este projeto está licenciado sob a MIT License.
Ver ficheiro LICENSE para mais detalhes.
