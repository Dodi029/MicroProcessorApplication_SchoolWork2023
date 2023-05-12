#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C myI2C(D14, D15);
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 64, 128);

// main() runs in its own thread in the OS
int main()
{
    OLED.clearDisplay();

    for(int i = 1; i<8; i++){
        OLED.drawCircle(32, 32, i*3, WHITE);
        if(i%2 == 0) {
            OLED.fillCircle(96, 32, 32 - i*3, BLACK);
        }
        else{
            OLED.fillCircle(96, 32, 32-i*3, WHITE);
        }
    }

    OLED.display();
    while (true) {
    }
}

