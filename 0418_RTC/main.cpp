#include "DigitalOut.h"
#include "mbed.h"
#define REG_SEC (0x02) //sec Register
#define REG_MIN (0x03) //min Register
#define REG_HOUR (0x04) // hour register
#define PCF8563_ADDR (0xA2) // PCF8563 i2c address

DigitalOut myled(LED1);
I2C i2c(I2C_SDA, I2C_SCL);

void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
char readByte(uint8_t address, uint8_t subAddress);
uint8_t bcdToDec(uint8_t val);
uint8_t decToBcd(uint8_t val);

void writeByte(uint8_t address, uint8_t regAddress, uint8_t data){
    char data_write[2];
    data_write[0] = regAddress;
    data_write[1] = data;
    i2c.write(address, data_write, 2, 0);
}

char readByte(uint8_t address, uint8_t regAddress){
    char data[1];
    char data_write[1];
    data_write[0] = regAddress;
    i2c.write(address, data_write, 1, 1);
    i2c.read(address, data, 1, 0);
    return data[0];
}

uint8_t bcdToDec(uint8_t val){
    return ((val/16)*10 + (val%16));
}

uint8_t decToBcd(uint8_t val){
    return ((val/10)*16 + (val%10));
}
// main() runs in its own thread in the OS
int main()
{
    // writeByte(PCF8563_ADDR, REG_SEC, decToBcd(1)); // 시간 설정용
    // writeByte(PCF8563_ADDR, REG_MIN, decToBcd(2));
    // writeByte(PCF8563_ADDR, REG_HOUR, decToBcd(3));
    while (true) {
        char s=readByte(PCF8563_ADDR,REG_SEC);
        char m=readByte(PCF8563_ADDR,REG_MIN);
        char h=readByte(PCF8563_ADDR,REG_HOUR);
        printf("Time= %02u:%02u:%02u\n", bcdToDec(h&0x3F),
        bcdToDec(m&0x7F), bcdToDec(s&0x07F));

        myled = !myled;
        wait_us(1000);
    }
}

