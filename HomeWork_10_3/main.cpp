#include "mbed.h"
BusIn pbs(D10, D11, D12, D13);
BusOut fnd(D2, D3, D4, D5, D6, D7, D8, D9);
uint16_t seg[]={0x02, 0x01, 0x08, 0x10, 0x20, 0x40, 0x08, 0x04};
// A, B, G, E, D, C, G, F 에 해당하는 데이터를 seg 배열에 저장
Timer tmr;
// main() runs in its own thread in the OS
int main()
{
    pbs.mode(PullUp);
    fnd=0xFF;
    tmr.start();
    uint16_t n_cnt=0, cnt=0;

    while (true) {
        if (tmr.read_us()>1000) {       // 1초마다 수행하도록 함
            tmr.reset();            // 타이머를 리셋 시킴
            if(cnt%100==0) {            // cnt값이 100까지 증가한다면 seg값을 변경   
                fnd=!seg[n_cnt++%8];  // 꺼져있는 seg를 킴
            }
            cnt++;
        }
    }
}

