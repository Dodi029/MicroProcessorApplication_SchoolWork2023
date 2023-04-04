#include "mbed.h"

Timer watch;
// main() runs in its own thread in the OS
int main()
{
    while (true) {
        watch.reset();
        watch.start();
        printf("PRINT 15bytes!\n");
        watch.stop();
        printf("It takes about %5u us\n", watch.read_us());
        wait_us(1000000);
    }
}

