#include <stdio.h>  // Include the standard input/output
#include <bcm2835.h>
#include <wiringPi.h>

// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetup() == -1) {
        printf("WiringPi init failed\n")
        return 2; // Initialization failed
    }

    if (!bcm2835_init()) {
        printf("bcm2835_init failed. Are you running as root?\n");
        return 1;
    }



    printf("Hello, World!\n");

    // Return 0 to indicate successful completion
    return 0;
}
