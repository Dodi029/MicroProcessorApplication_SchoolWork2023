#include "DigitalIn.h"
#include "mbed.h"
#include <cstdlib>
DigitalIn but1(BUTTON1);
BusOut fnd(D2, D3, D4, D5, D6, D7, D8, D9);
uint16_t num[] = {0x88, 0xBE, 0xC4, 0x94, 0xB2, 0x91, 0x81};
        // FND DATA 0~6사이의 숫자 저장
// main() runs in its own thread in the OS
int main()
{
    fnd=0xFF; // data[0]
    uint16_t cnt=0;
    while (true) {
        if(!but1) {
            cnt = rand(0, 5)+1;
            fnd=num[cnt];
            wait_us(100000);     // 바운싱을 예방하기 위한 대기 시간
        }
    }
}
