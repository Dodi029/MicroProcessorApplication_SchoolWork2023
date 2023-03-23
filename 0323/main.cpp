#include "AnalogIn.h"
#include "mbed.h"

// main() runs in its own thread in the OS
AnalogIn POT(A0);
int main()
{
    while (true) {
        float voltage=POT*3.3f;
        uint16_t value=POT.read_u16();
        printf("POT Value - %u, Voltage = %f \n",value, voltage);
        wait_us(500);
    }
}

