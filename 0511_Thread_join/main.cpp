#include "mbed.h"
Thread thread;
DigitalOut led1(LED1), led2(D7);
volatile bool running = true;
void blink(DigitalOut *led) {
    while (running) {
        *led = !*led;
        wait_us(200000);
    }
}
// main() runs in its own thread in the OS
int main()
{
    thread.start(callback(&blink, &led1));
    led2 = 1;
    wait_us(500000);
    running = false;    // 쓰레드 끄기
    thread.join();
    led2 = 0;
}

