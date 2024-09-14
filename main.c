#include <stdio.h>  // Include the standard input/output
#include <wiringPi.h>

// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetup() == -1) {
        printf("WiringPi init failed\n");
        return 2; // Initialization failed
    }
    printf("Init succeded");
    printf("Hello, World!\n");

    // Return 0 to indicate successful completion
    return 0;
}
