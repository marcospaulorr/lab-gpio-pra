#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED = 14;
const int BTN = 17;

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

int main() {
    stdio_init_all();

    //Configuração do LED como sáida
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    //Configuração do botão como entrada com pull-up
    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);

    //Configuração dos pinos do motor de passos como saída
    gpio_init(IN1);
    gpio_set_dir(IN1, GPIO_OUT);
    gpio_init(IN2);
    gpio_set_dir(IN2, GPIO_OUT);
    gpio_init(IN3);
    gpio_set_dir(IN3, GPIO_OUT);
    gpio_init(IN4);
    gpio_set_dir(IN4, GPIO_OUT);


    while (true) {
        //Verifica se o botão foi pressionado
        if(!gpio_get(BTN)){
            gpio_put(LED, 1);
            for ( int i = 0; i<512; i++){
                gpio_put(IN1, 1);
                sleep_ms(60);
                gpio_put(IN1, 0);
                gpio_put(IN2, 1);
                sleep_ms(60);
                gpio_put(IN2, 0);
                gpio_put(IN3, 1);
                sleep_ms(60);
                gpio_put(IN3, 0);
                gpio_put(IN4, 1);
                sleep_ms(60);
                gpio_put(IN4, 0);
            }
            gpio_put(LED, 0);

            //Espera o botão ser liberado para evitar múltiplas piscadas
            while (!gpio_get(BTN)){
                sleep_ms(10);
            }
        }

    }
}
