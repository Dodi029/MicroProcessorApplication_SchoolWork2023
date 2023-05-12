#include "mbed.h"
#define LED_PINS 9

BusOut leds(D4,D5,D6,D7,D8,D9,D10,D11,D12);

// main() runs in its own thread in the OS
int main()
{
    leds = 0x1FF;
    while (true) {
        for (int i = 0; i< LED_PINS; i++) {
            leds[i]=0;
            wait_us(100000);
            leds[i]=1;
        }
    }
}

