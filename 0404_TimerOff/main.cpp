#include "DigitalOut.h"
#include "mbed.h"

Timeout tmo;
DigitalOut led1(LED1);
DigitalOut led2(D7, 1);

void flip(){
    led2 = !led2;
}

// main() runs in its own thread in the OS
int main()
{
    tmo.attach(&flip, 10.0);        // flip after 10 seconds
    while (true) {
        led1 = !led1;
        wait_us(200);
    }
}

