# Periodic Timer with Raspberry Pi Pico W

## Sobre o Projeto

Este projeto implementa um sistema de semáforo utilizando um temporizador periódico por hardware no **Raspberry Pi Pico W**. A função **`add_repeating_timer_ms()`**, pertencente à biblioteca de hardware do Raspberry Pi Pico, é utilizada para criar e registrar um temporizador que executa uma função de callback repetidamente em intervalos de tempo definidos.

O objetivo do projeto é demonstrar o funcionamento de um semáforo utilizando **três LEDs** (vermelho, amarelo e verde), alternando entre os estados em ciclos de **3 segundos**.

---

## Diagrama Esquemático e Fluxograma no Wokwi

O esquema de montagem do projeto, simulado na plataforma **Wokwi**, é ilustrado abaixo. Ele consiste nos seguintes componentes:

- **1x Raspberry Pi Pico W**
- **3x LEDs** (vermelho, amarelo e verde)
- **3x Resistores de 330Ω**

<p align="center">
  <img src="fig1-esquema.png" alt="Fluxograma e esquema de simulação" width="701">
</p>

---

## 🛠 Instalação e Uso
1. Clone este repositório para o seu Raspberry Pi Pico W:
   ```sh
   git clone https://github.com/engleonardorodrigues/periodic-timer-RP2040.git
   ```
2. Compile e carregue o código no Raspberry Pi Pico W utilizando o SDK do **Pico**.
3. A execução irá ocorrer automaticamente.

---

## Descrição do Código

O código implementa um ciclo de **semáforo inteligente**, alternando entre três estados:

1. **Vermelho aceso** por **3 segundos**
2. **Amarelo aceso** por **3 segundos**
3. **Verde aceso** por **3 segundos**
4. **Retorno ao estado inicial**

### Estrutura do Código
- **Configuração de GPIOs:** No `main()`, os pinos GPIO dos LEDs são configurados como **saída**, e o estado inicial é definido com o LED vermelho ligado.
- **Temporização periódica:** A função `repeating_timer_callback()` é chamada a cada 3 segundos pelo temporizador criado com **`add_repeating_timer_ms()`**. Ela alterna os LEDs conforme a sequência do semáforo.
- **Monitoramento:** O código também inclui um loop `while(true)`, que imprime "Semáforo inteligente" no console a cada 1 segundo para monitoramento.


---

## Conclusão

Este projeto demonstra o uso eficiente de temporizadores periódicos no **Raspberry Pi Pico W** para criar um **semáforo inteligente**. Com a utilização da função **`add_repeating_timer_ms()`**, foi possível implementar uma alternância entre estados sem bloqueios, garantindo uma execução fluida e monitorável.

Para expandir o projeto, podem ser adicionados **sensores de presença** para um controle dinâmico do semáforo ou **módulos de comunicação** para integração com sistemas inteligentes de tráfego.

---

## 📩 Contato
Caso tenha dúvidas ou sugestões, entre em contato:
- **Desenvolvedor**: Leonardo Rodrigues
- **Linkedin**: https://www.linkedin.com/in/leonardorodrigues7/