#include <reg51.h>  
#include <stdio.h>

/*
sensor : HC-SR04
distance = (time_to_travel * speed_of_sound) / 2
*/

sbit trigger = P1^0;
sbit echo = P1^1;

void delay_us(unsigned int us) {
    /*
    
    */
    while (us--) {
        _nop_();  // Pas d'opération (NOP) pour simuler un délai
    }
}

void init_timer() {
    TMOD = 0x01;  // Timer 0 mode 1 (16 bits)
    TH0 = 0x00;
    TL0 = 0x00;
}

void send_trigger() {
    trigger = 1;
    delay_us(10);
    trigger = 0;
}

unsigned int measure_echo_time() {
    unsigned int time = 0;

    while (!echo);  // Attendre le HIGH
    TR0 = 1;        // Démarrer le Timer

    while (echo);   // Attendre le LOW
    TR0 = 0;        // Arrêter le Timer

    time = (TH0 << 8) | TL0;  // Lire la valeur du Timer
    return time;
}

float calculate_distance(unsigned int time) {
    return (time * 0.0343) / 2;  // Distance en cm
}

void main() {
    unsigned int time;
    float distance;

    init_timer();

    while (1) {
        send_trigger();
        time = measure_echo_time();
        distance = calculate_distance(time);

        // Affichez la distance sur un LCD ou autre (non inclus ici)
    }
}
