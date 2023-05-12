#include "DigitalOut.h"
#include "InterruptIn.h"
#include "Timeout.h"
#include "mbed.h"

InterruptIn button(BUTTON1);
DigitalOut led(LED1);
Timeout timeout;

bool led_on = false;

void turn_on_led() {
    led_on = true;
    led = 1;
}

void turn_off_led() {
    led_on = false;
    led = 0;
}

void button_pressed() {
    if (led_on) {
        turn_off_led();
    } else {
        timeout.attach(&turn_on_led, 1.0);
    }
}

// main() runs in its own thread in the OS
int main()
{
    button.fall(&button_pressed);
}

// Timeout, InterruptIn, DigitalOut 객체를 생성하고
// led_on 변수에 led가 켜져 있는지 꺼저 있는지 여부를 저장한다
// 버튼이 눌리면 켜졌다는 신호를 저장하고 led를 키는 함수와 버튼이 눌리면 꺼졌다는 신호를 저장하고 led를 끄는 함수를 생성한다
// 버튼이 눌렸을 때 led상태가 true면, led를 끄는 함수를 실행하고, false 상태면 1초뒤에 led를 키는 함수를 실행한다