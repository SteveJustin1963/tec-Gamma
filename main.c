#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define SPECTRUM_SIZE 1024

// Simulated spectrum data array
double spectrum[SPECTRUM_SIZE] = {0};

void initialize_spectrum() {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < SPECTRUM_SIZE; i++) {
        spectrum[i] = 0; // Reset spectrum data
    }
    // Add random peaks in the spectrum
    spectrum[rand() % SPECTRUM_SIZE] = rand() % 100 + 100;
    spectrum[rand() % SPECTRUM_SIZE] = rand() % 100 + 100;
    spectrum[rand() % SPECTRUM_SIZE] = rand() % 100 + 100;
}

void display_spectrum() {
    printf("Spectrum Analysis Graph (Intensity by Energy Bin):\n");
    for (int i = 0; i < SPECTRUM_SIZE; i++) {
        if (spectrum[i] > 0) {
            printf("%4d keV | ", i);
            int numAsterisks = spectrum[i] / 10; // Scale factor to reduce graph width
            for (int j = 0; j < numAsterisks; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}

// Placeholder function to simulate serial data transmission
void Serial_send(const char* data) {
    printf("Sending over serial: %s\n", data);
}

void send_spectrum_serial() {
    char buffer[10];  // Buffer to hold the formatted data
    int first = 1;    // Flag to handle the comma delimiter
    for (int i = 0; i < SPECTRUM_SIZE; i++) {
        if (spectrum[i] > 0) {
            if (!first) {
                Serial_send(",");  // Send comma delimiter between values
            }
            sprintf(buffer, "%04X", (uint16_t)spectrum[i]);  // Format data as hex
            Serial_send(buffer);
            first = 0;  // Reset the first item flag after the first item
        }
    }
    Serial_send("\n");  // New line at the end of data transmission
}

int main() {
    char choice;
    initialize_spectrum();
    display_spectrum();

    do {
        printf("Press 'R' to randomize data and recompute, 'S' to send data over serial, 'Q' to quit:\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'R':
            case 'r':
                initialize_spectrum();
                display_spectrum();
                break;
            case 'S':
            case 's':
                send_spectrum_serial();
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
