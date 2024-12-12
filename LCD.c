#include <reg52.h>

// Define LCD control pins
sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;

// Define LCD data port
#define LCD_DATA P0

// Function prototypes
void delay(unsigned int ms);
void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init();
void lcd_display_string(char *str);

void main() {
    lcd_init();
    lcd_display_string("Hello, World!");

    while (1) {
        // Main loop
    }
}

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 123; j++) {
            // Do nothing, just waste time
        }
    }
}

void lcd_command(unsigned char cmd) {
    LCD_DATA = cmd;
    RS = 0; // Command mode
    RW = 0; // Write mode
    EN = 1;
    delay(1);
    EN = 0;
    delay(2);
}

void lcd_data(unsigned char value) {
    LCD_DATA = value;
    RS = 1; // Data mode
    RW = 0; // Write mode
    EN = 1;
    delay(1);
    EN = 0;
    delay(2);
}

void lcd_init() {
    lcd_command(0x38); // 8-bit mode, 2 lines, 5x7 font
    lcd_command(0x0C); // Display on, cursor off
    lcd_command(0x06); // Increment cursor
    lcd_command(0x01); // Clear display
    delay(2);
}

void lcd_display_string(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}