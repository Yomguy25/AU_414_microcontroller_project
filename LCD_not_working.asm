ORG 00000H

; LCD 1602 Initialization and Display Code for STC89C52RC

; Define LCD control pins
RS EQU P2.6
RW EQU P2.5
EN EQU P2.7

; Define LCD data port
DATA_PORT EQU P0

; Delay subroutine
DELAY:
    MOV R2, #1
DELAY1:
    MOV R1, #123
DELAY2:
    DJNZ R1, DELAY2
    DJNZ R2, DELAY1
    RET

; Send command to LCD
LCD_CMD:
    MOV DATA_PORT, A
    CLR RS
    CLR RW
    SETB EN
    ACALL DELAY
    CLR EN
    RET

; Send data to LCD
LCD_DATA:
    MOV DATA_PORT, A
    SETB RS
    CLR RW
    SETB EN
    ACALL DELAY
    CLR EN
    RET

; Initialize LCD
LCD_INIT:
    MOV A, #38H ; Function set: 8-bit, 2 line, 5x7 dots
    ACALL LCD_CMD
    MOV A, #0CH ; Display on, cursor off, blink off
    ACALL LCD_CMD
    MOV A, #06H ; Entry mode set: increment cursor, no shift
    ACALL LCD_CMD
    MOV A, #01H ; Clear display
    ACALL LCD_CMD
    RET

; Main program
START:
    ACALL LCD_INIT
    MOV A, #'H'
    ACALL LCD_DATA
    MOV A, #'e'
    ACALL LCD_DATA
    MOV A, #'l'
    ACALL LCD_DATA
    MOV A, #'l'
    ACALL LCD_DATA
    MOV A, #'o'
    ACALL LCD_DATA
    SJMP $

END