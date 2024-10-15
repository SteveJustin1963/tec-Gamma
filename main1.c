#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>  // Include for uint32_t type
#include <time.h>    // Include for time function

#define SPECTRUM_SIZE 1024

// Simulated spectrum data array
double spectrum[SPECTRUM_SIZE] = {0};

// Function to initialize the spectrum with random data for testing
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

// Function to display the spectrum with a simple ASCII graph
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

// Main function with user menu
int main() {
    char choice;
    initialize_spectrum();
    display_spectrum();

    do {
        printf("Press 'R' to randomize data and recompute, 'Q' to quit:\n");
        scanf(" %c", &choice);
        if (choice == 'R' || choice == 'r') {
            initialize_spectrum();
            display_spectrum();
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
