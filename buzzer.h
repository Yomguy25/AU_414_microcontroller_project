#include <reg51.h>

// Définir la broche du buzzer
sbit BUZZER = P2^5;

// Prototypes des fonctions
void buzz(int frequency);

void buzz(int frequency) {
    unsigned int period = 1000000 /frequency; // Période en microsecondes
		
	BUZZER = 1;
}
