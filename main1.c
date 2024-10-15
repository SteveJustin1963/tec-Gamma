#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize the gamma spectrometer
void initialize_detector() {
    printf("Initializing the detector...\n");
}

// Function to load dummy spectrum data for testing
void load_dummy_spectrum(double *spectrum, int size) {
    memset(spectrum, 0, size * sizeof(double));  // Clear the spectrum array
    
    // Load dummy data simulating peaks at specific energy levels
    if (size > 300) spectrum[300] = 200; // Example: Cs-137 at ~300 keV
    if (size > 600) spectrum[600] = 150; // Example: Co-60 at ~600 keV
    if (size > 1000) spectrum[1000] = 180; // Example: I-131 at ~1000 keV
}

// Simple peak detection
void analyze_spectrum(const double *spectrum, int size) {
    printf("Analyzing spectrum...\n");
    for (int i = 0; i < size; i++) {
        if (spectrum[i] > 100) { // Threshold for peak detection set at 100 counts
            printf("Peak detected at energy bin %d with %f counts\n", i, spectrum[i]);
        }
    }
}

// Function to display results with a simple ASCII graph
void display_results(const double *spectrum, int size) {
    printf("Displaying results...\n");
    printf("Spectrum Analysis Graph (Intensity by Energy Bin):\n");
    for (int i = 0; i < size; i++) {
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

// Main function
int main() {
    printf("Gamma Spectrometry Program\n");

    // Initialize the detector
    initialize_detector();
    
    // Define the size of the spectrum array
    const int spectrum_size = 1024;
    double *spectrum = (double *)malloc(spectrum_size * sizeof(double));

    if (spectrum == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Load dummy spectrum data
    load_dummy_spectrum(spectrum, spectrum_size);
    
    // Analyze the captured spectrum
    analyze_spectrum(spectrum, spectrum_size);

    // Display the results with ASCII graph
    display_results(spectrum, spectrum_size);

    // Clean up resources
    free(spectrum);

    return EXIT_SUCCESS;
}
