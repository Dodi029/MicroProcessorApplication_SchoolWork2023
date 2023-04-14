#include "mbed.h"
#include "BufferedSerial.h"
#include <string>

DigitalOut led1(LED1);
BufferedSerial pc(USBTX, USBRX);

volatile bool gotPacket = false;
volatile float data[3];

void onSerialRx() {
    static char serialInBuffer[32];
    static int serialCount = 0;

    while (pc.readable()) {
        char byteIn = pc.getc();

        if (byteIn == '\n') {
            serialInBuffer[serialCount] = 0;
            float d0, d1, d2;
            if (sscanf(serialInBuffer, "%f,%f,%f", &d0, &d1, &d2) == 3 ) {
                data[0] = d0; data[1] = d1; data[2] = d2;
                gotPacket = true;
            }
            serialCount = 0;
        }
        else {
            serialInBuffer[serialCount] = byteIn;
            if (serialCount<32)
                serialCount++;
        }
    }
}

int main() {
    pc.attach(&onSerialRx);

    while (true) {
        if (gotPacket) {
            gotPacket = false;
            pc.printf("data=%.3f,#.3f,%.3f\n\r", data[0], data[1], data[2]);
        }
        led1 =! led1;
        wait_us(20);
    }
}