/*****************************************************************************************************
 * Título        : Temporizador periódico para Raspberry Pi Pico W
 * Desenvolvedor : Leonardo Rodrigues
 * Versão        : 1.0.0
 * 
 * Descrição:
 * Este programa implementa um sistema de controle de semáforo utilizando 
 * o Raspberry Pi Pico W. O programa alterna entre os estados do semáforo
 * (vermelho, amarelo e verde) em intervalos definidos, simulando um ciclo real.
 * 
 * Materiais utilizados:
 * 
 * 1 - Raspberry Pi Pico W
 * 3 - LEDs coloridos (vermelho, amarelo e verde)
 * 3 - Resistores de 330 ohms
 * 1 - Simulador Wokwi
 ******************************************************************************************************/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO  12
#define LED_VERDE    13

// Variável global para armazenar o estado atual do semáforo
int estado = 0;

// Função chamada periodicamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    
    // Alterna os LEDs de acordo com o estado do semáforo
    switch (estado) {
        case 0:                                                                 // Estado: Vermelho aceso por 3 segundos
            gpio_put(LED_VERMELHO, 0);                                          // Desliga o LED vermelho
            gpio_put(LED_AMARELO,  1);                                          // Liga o LED amarelo
            gpio_put(LED_VERDE,    0);                                          // Desliga o LED verde
            estado = 1;                                                         // Avança para o próximo estado
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);    // Aguarda 3 segundos
            break;

        case 1:                                                                 // Estado: Amarelo aceso por 3 segundo
            gpio_put(LED_VERMELHO, 0);                                          // Desliga o LED vermelho
            gpio_put(LED_AMARELO,  0);                                          // Desliga o LED amarelo
            gpio_put(LED_VERDE,    1);                                          // Liga o LED verde
            estado = 2;                                                         // Avança para o próximo estado
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);    // Aguarda 3 segundos
            break;

        case 2:                                                                 // Estado: Verde aceso por 3 segundos
            gpio_put(LED_VERMELHO, 1);                                          // Liga o LED vermelho
            gpio_put(LED_AMARELO,  0);                                          // Desliga o LED amarelo
            gpio_put(LED_VERDE,    0);                                          // Desliga o LED verde
            estado = 0;                                                         // Retorna ao primeiro estado
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);    // Aguarda 3 segundos
            break;
    }
    return false;
}

int main() {
    stdio_init_all();                                                           // Inicializa bibliotecas 

    gpio_init(LED_VERMELHO);                                                    // Inicializa GPIO 11 (Led Vermelho)
    gpio_init(LED_AMARELO);                                                     // Inicializa GPIO 12 (Led Amarelo)
    gpio_init(LED_VERDE);                                                       // Inicializa GPIO 13 (Led Verde)

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);                                       // Define GPIO 11 como saída
    gpio_set_dir(LED_AMARELO,  GPIO_OUT);                                       // Define GPIO 12 como saída
    gpio_set_dir(LED_VERDE,    GPIO_OUT);                                       // Define GPIO 13 como saída

    gpio_put(LED_VERMELHO, 1);                                                  // Liga o LED vermelho (estado inicial)
    gpio_put(LED_AMARELO,  0);                                                  // Desliga o LED amarelo
    gpio_put(LED_VERDE,    0);                                                  // Desliga o LED verde

    struct repeating_timer timer;                                               // Declaração da estrutura do temporizador

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);       // Configura e inicia o temporizador

    while (true) {

        printf("Semáforo inteligente\n");                                       // Exibe mensagem no console
        sleep_ms(1000);                                                         // Aguarda 1 segundo antes de exibir novamente
    }

    return 0;
}
