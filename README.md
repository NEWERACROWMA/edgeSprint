# EdgeSprint: Projeto de Simulação e Benefícios para Telespectadores

## Objetivo do Projeto
Este projeto tem como objetivo simular a aceleração, direção e nível de bateria de um carro de Fórmula E para exibir esses dados em tempo real aos telespectadores. Além disso, ele proporciona uma interação adicional com um cronômetro que beneficia os usuários com drops (recompensas) à medida que assistem às transmissões.

## Componentes Necessários

### Hardware
- Arduino Uno ou similar
- Display LCD I2C (20x4)
- Módulo TM1637 para display de 7 segmentos
- Buzzer
- Joystick
- Potenciômetro
- LEDs (verde, amarelo e vermelho)
- Resistores e cabos de conexão

### Software
- Arduino IDE
- Bibliotecas:
  - `LiquidCrystal_I2C`
  - `TM1637`

## Descrição dos Códigos

### Código 1: Simulador de Carro de Fórmula E

#### Funcionalidade
Este código simula a velocidade, direção e nível de bateria de um carro de Fórmula E. As informações são exibidas em um display LCD e LEDs indicam o estado da bateria e movimento do carro.

#### Necessidades
- Um joystick para controlar a direção.
- Um potenciômetro para simular a aceleração.
- LEDs para indicar o estado da bateria.
- Display LCD para exibir a velocidade, nível de bateria e direção.

### Código 2: Simulação de Cronômetro e Drops

#### Funcionalidade
Este código mantém um cronômetro que rastreia o tempo que o usuário está assistindo à transmissão. A cada 3 horas, o usuário recebe uma notificação de drop (comum, raro ou épico), que é exibida no display LCD e indicada com um som emitido pelo buzzer.

#### Necessidades
- Módulo TM1637 para exibir o tempo no formato de 7 segmentos.
- Buzzer para notificação sonora de drops.
- Display LCD para exibir o tempo e tipo de drop disponível.

## Instruções de Montagem e Uso

1. **Montagem do Hardware:**
   - Conecte o display LCD I2C aos pinos apropriados do Arduino.
   - Conecte o módulo TM1637 aos pinos CLK e DIO.
   - Conecte o buzzer ao pino 11.
   - Conecte o joystick ao pino A1.
   - Conecte o potenciômetro ao pino A2.
   - Conecte os LEDs aos pinos 11 (verde), 12 (amarelo) e 13 (vermelho).

2. **Carregamento do Código:**
   - Abra a Arduino IDE e carregue cada um dos códigos em sequência no Arduino.

3. **Operação:**
   - O primeiro código exibirá a velocidade, direção e nível de bateria do carro simulado.
   - O segundo código monitorará o tempo de visualização e notificará os drops a cada 3 horas.

## Vídeo Explicativo

Para uma explicação detalhada de cada parte do projeto, assista ao vídeo disponível no link abaixo:
[Vídeo Explicativo do Projeto](https://www.canva.com/design/DAGEMyf7rcQ/cNwLiiHkScdg7CUHaZc7ug/edit?utm_content=DAGEMyf7rcQ&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Conclusão

Este projeto oferece uma maneira interativa e informativa de acompanhar uma simulação de Fórmula E e recompensar os telespectadores pela sua participação ativa.
