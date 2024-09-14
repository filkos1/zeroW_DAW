
//libraries
#include <stdio.h>  
#include <wiringPi.h>
//pins (all in phys addr)
#define BUTTON_MORE (35)
#define BUTTON_LESS (37)
#define LED (12)
//some other stuff
#define DELAY (500) //in ms

void ISRmore(void) {
    printf("more delay\n");

}
void ISRless(void) {
    printf("less delay\n");

}




// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetupPhys() == -1) {
        printf("WiringPi init failed\n");
        return 2; // Initialization failed
    }
    printf("\033[32mInit succeded\033[37m\n");
    
    //pin modes
    pinMode(LED, OUTPUT);
    pinMode(BUTTON_MORE, INPUT);
    pinMode(BUTTON_LESS, INPUT);

    //pull-up resistors
    pullUpDnControl(BUTTON_MORE, PUD_UP);
    pullUpDnControl(BUTTON_LESS, PUD_UP);

    if (wiringPiISR(BUTTON_MORE, INT_EDGE_FALLING, &ISRmore) < 0) {
        printf("Unable to setup ISR\n");
        return 5;
    }
    
    if (wiringPiISR(PIN, INT_EDGE_FALLING, &ISRless) < 0) {
        printf("Unable to setup ISR\n");
        return 5;
    }



    while (1) {
        digitalWrite(LED, HIGH);
        delay(DELAY);
        digitalWrite(LED, LOW);
        delay(DELAY);

    }
    


    
    
    // Return 0 to indicate successful completion
    return 0;
}
