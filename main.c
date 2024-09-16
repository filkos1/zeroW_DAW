
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
unsigned char pressed[MAX_PRESSED] = {0};
unsigned char nextArr = 0;


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

        //row 1
        digitalWrite(O1, HIGH);
        delay(10);
        if (digitalRead(I1) == HIGH) {
            pressed[nextArr] = 11;
            nextArr ++;
        }
        if (digitalRead(I2) == HIGH) {
            pressed[nextArr] = 12;
            nextArr ++;
        }
        if (digitalRead(I3) == HIGH) {
            pressed[nextArr] = 13;
            nextArr ++;
        }
        digitalWrite(O1, LOW);

        //row 2
        digitalWrite(O2, HIGH);
        delay(10);
        if (digitalRead(I1) == HIGH) {
            pressed[nextArr] = 21;
            nextArr ++;
        }
        if (digitalRead(I2) == HIGH) {
            pressed[nextArr] = 22;
            nextArr ++;
        }
        if (digitalRead(I3) == HIGH) {
            pressed[nextArr] = 23;
            nextArr ++;
        }
        digitalWrite(O2, LOW);



        digitalWrite(O3, HIGH);
        delay(10);
        if (digitalRead(I1) == HIGH) {
            pressed[nextArr] = 31;
            nextArr ++;
        }
        if (digitalRead(I2) == HIGH) {
            pressed[nextArr] = 32;
            nextArr ++;
        }
        if (digitalRead(I3) == HIGH) {
            pressed[nextArr] = 33;
            nextArr ++;
        }
        digitalWrite(O3, LOW);
         
        printf("\rPressed buttons are ");
        for (int i = 0; i < nextArr; i++) {
            printf("%d ", pressed[i]);
        }
        delay(100);

    }
    

   
    
    
    // Return 0 to indicate successful completion
    return 0;
}
