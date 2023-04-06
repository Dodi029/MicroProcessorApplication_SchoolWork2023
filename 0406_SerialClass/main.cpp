#include "mbed.h"

BufferedSerial pc(USBTX, USBRX);
// main() runs in its own thread in the OS
int main()
{
    int n, m;
    while (true) {
        pc.printf("Type two integers:");
        pc.scanf("%d%d", &n,&m);
        pc.printf("\nYou typed %d and %d\n",n ,m);
    }
}

