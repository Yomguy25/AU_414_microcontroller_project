; Code pour générer un signal PWM continu sur P2.5

ORG 0000H          ; Origine de l'adresse du programme
AJMP MAIN          ; Saut à l'étiquette MAIN

; Définir la zone de données
DUTY_CYCLE EQU 30H ; Adresse pour le rapport cyclique

MAIN:
    MOV P2, #0FFH     ; Initialiser le port P2
    MOV DUTY_CYCLE, #50      ; Initialiser le rapport cyclique à 50%

LOOP:
    MOV A, DUTY_CYCLE        ; Charger le rapport cyclique dans A
    MOV R1, #100      ; Définir la période de 100 cycles

PWM_LOOP:
    MOV R2, A         ; Charger le rapport cyclique dans R2
    SETB P2.5         ; Activer le buzzer (P2.5)
    ACALL DELAY       ; Appeler la fonction de délai
    MOV A, #100       ; Recharger la période dans A
    SUBB A, R2        ; Calculer le temps off
    MOV R2, A         ; Stocker le temps off dans R2
    CLR P2.5          ; Désactiver le buzzer (P2.5)
    ACALL DELAY       ; Appeler la fonction de délai
    DJNZ R1, PWM_LOOP ; Répéter jusqu'à ce que la période soit terminée

    SJMP LOOP         ; Répéter en continu

DELAY:
    MOV R3, #123      ; Délai approximatif de 1 ms
DELAY_LOOP:
    NOP               ; Instruction NOP (No Operation)
    DJNZ R3, DELAY_LOOP
    RET               ; Retourner à l'appelant

END
