#include <reg52.h>

// Définir la broche du buzzer
sbit BUZZER = P2^5;

// Prototypes des fonctions
void delay(unsigned int ms);
void pwm(unsigned int duty_cycle, unsigned int frequency);

void main(void) {
    unsigned int duty_cycle = 50;  // Rapport cyclique de 50%
    unsigned int frequency = 1000; // Fréquence de 1 kHz
    
    // Boucle infinie pour générer un son continu
    while (1) {
        pwm(duty_cycle, frequency); // Générer le signal PWM continu
    }
}

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 123; j++) {
            // Ne rien faire, juste perdre du temps
        }
    }
}

void pwm(unsigned int duty_cycle, unsigned int frequency) {
    unsigned int i;
    unsigned int on_time = duty_cycle;
    unsigned int off_time = 100 - duty_cycle;
    unsigned int period = 1000000 / frequency; // Période en microsecondes

    for (i = 0; i < (period / 2); i++) {
        BUZZER = 1; // Activer le buzzer
        delay(on_time / 10); // Délai pour le temps actif

        BUZZER = 0; // Désactiver le buzzer
        delay(off_time / 10); // Délai pour le temps inactif
    }
}
