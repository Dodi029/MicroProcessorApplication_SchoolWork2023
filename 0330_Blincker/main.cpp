#include "DigitalOut.h"
#include "mbed.h"

class Blinker{
    DigitalOut _led;
    Ticker _tick;
    void blink() {
        _led = !_led;
    }
    public:
    Blinker(PinName pin): _led(pin) {
        _led = 0;
    }
    void begin(float sec) {
        _tick.attach(callback(this, &Blinker::blink), sec);
    }
};
// main() runs in its own thread in the OS
Blinker blink(LED1);
DigitalOut led2(D7);

int main()
{
    blink.begin(0.1);
    while (true) {
        led2 = !led2;
        wait_us(1000);
    }
}

