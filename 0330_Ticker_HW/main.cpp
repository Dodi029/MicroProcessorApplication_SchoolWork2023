#include "mbed.h"

Ticker tic1, tic2;

DigitalOut led1(LED1);
DigitalOut led2(D7);

void toggle1() {
    led1 = !led1;
}

void toggle2(){
    led2 = !led2;
}
// main() runs in its own thread in the OS
int main()
{
    tic1.attach(&toggle1, 0.1);
    tic2.attach(&toggle2, 1.0);
}