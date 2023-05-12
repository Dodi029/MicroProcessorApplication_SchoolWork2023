#include "mbed.h"
 BusIn pbs(D10, D11, D12, D13);
 BusOut fnd(D2, D3, D4, D5, D6, D7, D8, D9);
 uint16_t num[] = {0x88, 0xBE, 0xC4, 0x94, 0xB2, 0x91, 0x81, 0xBC, 0x80, 0xB0, 0x84, 0x83, 0xC7, 0x86, 0xC1, 0xE1};
// main() runs in its own thread in the OS
int main()
{
    pbs.mode(PullUp);
    fnd=0xFF;
    uint16_t cnt=0;
    while (true) {
        fnd=num[pbs^0x0F];
        wait_us(100000);
    }
}

