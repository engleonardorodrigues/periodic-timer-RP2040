# Periodic Timer with Raspberry Pi Pico W

## Sobre o projeto

<p align="justify">
O projeto se propõe a desenvolver um semáforo utilizando função de temporização por hardware add_repeating_timer_ms() sendo está uma biblioteca de hardware do Raspberry Pi Pico.  Essa função é utilizada para criar e registrar um temporizador periódico. Esse temporizador executa uma função de callback repetidamente em intervalos de tempo definidos.
</p>

## Fluxograma e diagrama esquemático no simulador Wokwi

<p align="justify">
O fluxograma e diagrama esquemático do projeto proposto e visto a seguir. Nele temos um Raspberry Pi Pico W, três leds (Vermelho, Amarelo e Verde) e três resistores de 330 ohms. 

<p align="center">
  <img src="fig1-esquema.png" alt="Fluxograma e esquema de simulação" width="700">
</p>

## Descrição do código

<p align="justify">
Este código implementa um sistema de controle de semáforo utilizando o Raspberry Pi Pico W. Ele controla três LEDs (vermelho, amarelo e verde) para simular o funcionamento de um semáforo real, alternando entre os estados em intervalos de 3 segundos.
</p>
<p align="justify">
A lógica do programa funciona com um temporizador periódico (add_repeating_timer_ms), que chama a função repeating_timer_callback() a cada ciclo. Essa função muda o estado dos LEDs de acordo com a sequência:
</p>
<p align="justify">
Vermelho aceso por 3 segundos
Amarelo aceso por 3 segundos
Verde aceso por 3 segundos
Retorno ao primeiro estado
No main(), os pinos GPIO dos LEDs são configurados como saída e o estado inicial é definido com o LED vermelho ligado. O temporizador inicia a execução da lógica de alternância dos LEDs sem necessidade de delays bloqueantes, permitindo que o programa continue rodando normalmente.
</p>
<p align="justify">
Além disso, há um loop infinito (while(true)) que imprime "Semáforo inteligente" no console a cada segundo para monitoramento do funcionamento.
</p>
