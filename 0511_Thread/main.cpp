#include "mbed.h"
DigitalOut led1(LED1), led2(D7);
Thread thread;

void led1_thread(){
    while(true) {
        led1 = !led1;
        wait_us(100000);
    }
}
// main() runs in its own thread in the OS
int main()
{
    thread.start(&led1_thread);
    while (true) {
        led2 = !led2;
        wait_us(500000);
    }
}

