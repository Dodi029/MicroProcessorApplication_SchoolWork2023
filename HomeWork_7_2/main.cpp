#include "mbed.h"

const int N = 10000;
float x[N];

float RMS() {
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i] * x[i];
    }
    return sqrt(sum / N);
}

// main() runs in its own thread in the OS
int main() {
    Timer timer;
    float rms;
    
    for (int i = 0; i < N; i++) {
        x[i] = i + 1;
    }
    
    timer.start();
    rms = RMS();
    timer.stop();
    
    printf("RMS = %f, Time = %d us\n", rms, timer.elapsed_time().count());
}

// time 클래스 멤버 함수 중 하나인 .elapsed_time 함수는 타이머가 시작된 이후 지난 시간을 us 단위로 반환하는 함수를 사용한다
// 함수를 호출하기 전에 Timer 클래스의 start() 함수로 타이머를 시작하고, stop() 함수를 통해 정지해야 한다