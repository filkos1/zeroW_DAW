//libraries
#include <stdio.h>  
#include <wiringPi.h>
//pins (all in phys addr)

//Outputs
#define O1 (8)
#define O2 (10)
#define O3 (12)
//Inputs
#define I1 (7)
#define I2 (5)
#define I3 (3)
//some other stuff
#define MAX_PRESSED 3  // Maximum number of presses we track at one time

//values
unsigned char pressed[MAX_PRESSED] = {0};  // Array to store pressed buttons
unsigned char nextArr = 0;


// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetupPhys() == -1) {
        printf("WiringPi init failed\n");
        return 2; // Initialization failed
    }
    printf("\033[32mInit succeeded\033[37m\n");
    
    // Pin modes
    pinMode(O1, OUTPUT);
    pinMode(O2, OUTPUT);
    pinMode(O3, OUTPUT);

    pullUpDnControl(I1, PUD_DOWN);
    pullUpDnControl(I2, PUD_DOWN);
    pullUpDnControl(I3, PUD_DOWN);
    pinMode(I1, INPUT);
    pinMode(I2, INPUT);
    pinMode(I3, INPUT);

    while (1) {

        // Clear pressed array
        for (int i = 0; i < MAX_PRESSED; i++) {
            pressed[i] = 0;  // Clear previous data
        }
        nextArr = 0;  // Reset the index for the current scan

        // Check Row 1
        digitalWrite(O1, HIGH);
        delay(50);  // Slight delay for stable read
        if (digitalRead(I1) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 11;  // Row 1, Column 1
        }
        if (digitalRead(I2) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 12;  // Row 1, Column 2
        }
        if (digitalRead(I3) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 13;  // Row 1, Column 3
        }
        digitalWrite(O1, LOW);  // Turn off Row 1

        // Check Row 2
        digitalWrite(O2, HIGH);
        delay(50);  // Slight delay for stable read
        if (digitalRead(I1) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 21;  // Row 2, Column 1
        }
        if (digitalRead(I2) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 22;  // Row 2, Column 2
        }
        if (digitalRead(I3) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 23;  // Row 2, Column 3
        }
        digitalWrite(O2, LOW);  // Turn off Row 2

        // Check Row 3
        digitalWrite(O3, HIGH);
        delay(50);  // Slight delay for stable read
        if (digitalRead(I1) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 31;  // Row 3, Column 1
        }
        if (digitalRead(I2) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 32;  // Row 3, Column 2
        }
        if (digitalRead(I3) == HIGH && nextArr < MAX_PRESSED) {
            pressed[nextArr++] = 33;  // Row 3, Column 3
        }
        digitalWrite(O3, LOW);  // Turn off Row 3

        // Clear the line and print results
        printf("\r\033[KPressed buttons are: ");
        for (int i = 0; i < nextArr; i++) {
            printf("%d ", pressed[i]);  // Print valid button presses
        }

        // Ensure clearing of previous longer output
        printf("                     ");
        
        fflush(stdout);  // Ensure immediate display

        delay(100);  // Slight delay between iterations
    }

    // Return 0 to indicate successful completion
    return 0;
}
