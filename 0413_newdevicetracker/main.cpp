#include "mbed.h"

I2C i2c(I2C_SDA, I2C_SCL);
// main() runs in its own thread in the OS
int main()
{
    uint8_t count=0;
    while (true) {
        printf("\nScanning I2C devidces....\n");
        count = 0;
        for (int adr=0;adr<256;adr++){
            if(i2c.read(adr,0,0)==0){
                count++;
                printf("found @ 0x%02X \n", adr);
            }
            wait_us(5);
        }
        printf("\n Total %2d devices are found\n", count);
        wait_us(1000);
    }
}

