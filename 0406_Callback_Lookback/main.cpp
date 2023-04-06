#include "mbed.h"

BufferedSerial pc(USBTX, USBRX);
DigitalOut led(LED1);
char buf;
void serialEvent(){
    if(pc.read(&buf,1)){
        pc.write(&buf, 1);
    }
} 

int main(){
    printf("Loop back program start!\n");
    pc.attach(&serialEvent);
    while(1){
        led=!led;
        wait_us(10000);
    }
}