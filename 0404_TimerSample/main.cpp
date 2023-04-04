#include "DigitalOut.h"
#include "mbed.h"
#define SAMPLE_INTERVAL 10000

Timer tmr;
DigitalOut led(LED1);

// main() runs in its own thread in the OS
int main()
{
    tmr.start();
    while (true) {
        if(tmr.read_us()>SAMPLE_INTERVAL){
            tmr.reset();
            led=!led;
        }
    }
}

