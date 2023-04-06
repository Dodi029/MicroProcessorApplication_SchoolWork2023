#include "mbed.h"

Serial pc(USBTX, USBRX);
// main() runs in its own thread in the OS
int main()
{
    printf("Loop back program start!\n");
    while (true) {
        if (pc.readable()){
            pc.putc(pc.getc());
        }
        wait_us(10);
    }
}

