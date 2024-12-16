#include <reg51.h>

// Define LCD control pins
sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;

// Define LCD data port
#define LCD_DATA P0

// Function prototypes
void delay(unsigned int ms);
void lcd_command(unsigned char cmd);
void lcd_data(unsigned char value);
void lcd_init();
void lcd_display_string(char *str);
void lcd_display_number(int num);

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

// Function to display a number on the LCD
void lcd_display_number(int num) {
    char buffer[16];  // Buffer to store the converted number as a string
    int i = 0;        // Index for the buffer
    int start, end;   // Declaring start and end variables inside the function
		char temp;
	
    // Special case for 0
    if (num == 0) {
        buffer[i++] = '0';
    } else {
        // Convert the number to a string (reverse order)
        while (num > 0) {
            buffer[i++] = (num % 10) + '0';
            num /= 10;
        }
    }

    buffer[i] = '\0';  // Null-terminate the string

    // Reverse the string since the digits are stored in reverse order
    start = 0;      // Initialize start index
    end = i - 1;    // Initialize end index

    // Swap the characters in buffer to reverse the string
    while (start < end) {
        temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    lcd_display_string(buffer); // Display the number as a string
}

