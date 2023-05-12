#include "DigitalOut.h"
#include "mbed.h"

SPI spi(p5, p6, p7);
DigitalOut cs(p8);

void writeByte(int reg, char data) {    // int형 reg와 char형 data 매개변수를 가짐
                                    // reg는 작성하려는 레지스터의 주소, data는 쓸 데이터를 의미
    cs = 0;                         // 핀을 Low로 설정하여 SPI 트랜잭션을 시작
    spi.write(reg);                 // SPI에 레지스터 주소를 작성
    spi.write(data);                // 데이터를 SPI에 작성
    cs = 1;                         // 핀을 HIGH로 설정하여 SPI 트랜잭션을 종료
}
// main() runs in its own thread in the OS
int main()
{
    while (true) {

    }
}

