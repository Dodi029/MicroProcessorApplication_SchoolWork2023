#include "mbed.h"

Ticker tic;
DigitalOut led1(LED1);
DigitalOut led2(D7);

// main() runs in its own thread in the OS

void toggle() {
    led1 = !led1;
}

int main()
{
    tic.attach(&toggle, 0.1);
    while (true) {
        led2 =! led2;
        wait_us(1000);
    }
}

