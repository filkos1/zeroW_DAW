
//compiler
#include <stdio.h>  
#include <wiringPi.h>
#define PIN = 18
#define DELAY = 500 //in ms

// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetup() == -1) {
        printf("WiringPi init failed\n");
        return 2; // Initialization failed
    }
    printf("\033[32mInit succeded\033[37m\n");
    
    pinMode(PIN, OUTPUT);
    while (1)
    {
        digitalWrite(PIN, HIGH);
        delay(DELAY);
        digitalWrite(PIN, HIGH);
        delay(DELAY);

    }
    


    
    
    // Return 0 to indicate successful completion
    return 0;
}
