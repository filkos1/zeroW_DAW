
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

//values
unsigned char pressed[3] = {0,0,0};


// The main function
int main(int argc, char *argv[]) {

    if (wiringPiSetupPhys() == -1) {
        printf("WiringPi init failed\n");
        return 2; // Initialization failed
    }
    printf("\033[32mInit succeded\033[37m\n");
    
    //pin modes
    pinMode(O1, OUTPUT);
    pinMode(O2, OUTPUT);
    pinMode(O3, OUTPUT);
    pinMode(I1, INPUT);
    pinMode(I2, INPUT);
    pinMode(I3, INPUT);

    while (1) {
        //row 1
        digitalWrite(O1, HIGH);
        delay(10);
        unsigned int state = digitalRead(I1);
        if (state == HIGH) {
            printf("r1 c1 pressed\n");
        }
         

        delay(100);

    }
    

   
    
    
    // Return 0 to indicate successful completion
    return 0;
}
