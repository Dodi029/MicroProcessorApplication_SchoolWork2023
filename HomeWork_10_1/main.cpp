#include "mbed.h"
#define LED_PINS 3

BusOut leds(D4,D5,D6);

int main(){
    leds = 0x1FF; // RGB가 켜지도록 정해둠
    while(true){
        for(int i = 0; i < LED_PINS ; i++){  // 3개가 반복되므로 반복문을 3으로 설정
            leds[i] = 1;        // 반복문 횟수에 따라 순서대로 LED를 킴
            wait_us(100000);        // 1초 대기
            leds[i] = 0;        // 다시 LED를 끔
        }
    }
}