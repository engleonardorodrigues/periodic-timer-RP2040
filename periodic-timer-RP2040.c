/*****************************************************************************************************
 * Título        : Temporizador periodico para Raspberry Pi Pico W
 * Desenvolvedor : Leonardo Rodrigues
 * Versão        : 1.0.0
 * 
 * Descrição:
 * Este programa implementa um sistema de geração de código Morse utilizando 
 * o Raspberry Pi Pico W. O programa aciona LEDs para representar o sinal SOS 
 * no formato Morse (••• ——— •••), com tempos configuráveis para os sinais e 
 * intervalos.
 * 
 * Materias utilizados:
 * 
 * 1 - Raspberry Pi Pico W
 * 3 - Leds coloridos
 * 1 - Resistor de 330 ohms
 * 1 - Simulador Wokwi
 ******************************************************************************************************/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO  12
#define LED_VERDE    13

int estado = 0;

// Função chamada periodicamente pelo timer
bool repeating_timer_callback(struct repeating_timer *t) {
    
    // Alterna os LEDs de acordo com o estado do semáforo
    switch (estado) {
        case 0: // Vermelho aceso por 3 segundos
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            estado = 1;
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);
            break;
        case 1: // Amarelo aceso por 1 segundo
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            estado = 2;
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);
            break;
        case 2: // Verde aceso por 3 segundos
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            estado = 0;
            add_repeating_timer_ms(3000, repeating_timer_callback, NULL, t);
            break;
    }

    return false; // Timer será reiniciado no próximo estado
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO,  GPIO_OUT);
    gpio_set_dir(LED_VERDE,    GPIO_OUT);

    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

     struct repeating_timer timer;

    // Inicia o timer com o primeiro estado (vermelho)
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo inteligente\n");
        sleep_ms(1000);
    }
    return 0;
}