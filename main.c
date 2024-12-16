#include <reg51.h>
#include <stdio.h>
#include "lcd.h"
#include "buzzer.h"

/*
Capteur : HC-SR04
Formule de la distance : distance = (temps * vitesse_du_son) / 2
*/

// Définition des broches Trigger et Echo
sbit trigger = P3^0;
sbit echo = P3^1;

// Prototypes des fonctions
void delay_us(unsigned int us);
void init_timer();
void send_trigger();
unsigned int measure_echo_time();
float calculate_distance(unsigned int time);

void main() {
    unsigned int echo_time;
    float distance;
	
		// Fréquence du buzzer
    unsigned int frequency = 1000000; // Fréquence de 1 kHz
	
    lcd_init();                          // Initialisation de l'écran LCD

    while (1) {
        send_trigger();                  // Envoyer une impulsion trigger
        echo_time = measure_echo_time(); // Mesurer le temps de l'écho
        distance = calculate_distance(echo_time); // Calculer la distance

				lcd_display_string("Dist:");     // Affichage d'un texte fixe
        lcd_display_number((int)distance); // Afficher la distance entière
				lcd_display_string(" cm");       // Ajouter l'unité "cm"
        lcd_command(0xC0);               // Se déplacer sur la 2e ligne
			
				lcd_display_string("MC:");     // Affichage d'un texte fixe
        lcd_display_number((int) echo_time); // Afficher la distance entière
								
				if (distance < 15){
					buzz(frequency);
					delay(distance*20);
				}
				lcd_command(0x01); 					// Efface le texte affiché
    }
}

// Fonction de retard en microsecondes
void delay_us(unsigned int us) {
    while (us) {
        // Retard approximatif en fonction du cristal d'horloge
				us--;
    }
}

// Initialisation du Timer 0
void init_timer() {
    TMOD = 0x01;  // Mode 1 : 16 bits
    TH0 = 0x00;   // Réinitialiser les registres du Timer
    TL0 = 0x00;
}

// Envoyer un signal trigger de 10 µs
void send_trigger() {
    trigger = 1;
    delay_us(10); // Retard de 10 µs
    trigger = 0;
}

// Mesurer le temps de l'écho en µs
unsigned int measure_echo_time() {
    unsigned int time = 0;

    while (!echo);  // Attendre que Echo passe à HIGH
    TR0 = 1;        // Démarrer le Timer

    while (echo);   // Attendre que Echo passe à LOW
    TR0 = 0;        // Arrêter le Timer

    time = (TH0 << 8) | TL0;  // Combiner TH0 et TL0 pour obtenir le temps
    TH0 = 0x00;  // Réinitialiser le Timer
    TL0 = 0x00;

    return time;
}

// Calculer la distance à partir du temps mesuré
float calculate_distance(unsigned int time) {
    return (time *0.0343/8.33) / 2;  // Distance en cm (vitesse du son = 343 m/s)
}
