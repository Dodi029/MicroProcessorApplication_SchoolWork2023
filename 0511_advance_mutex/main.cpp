#include "mbed.h"
UnbufferedSerial pc(USBTX,USBRX);
MemoryPool<uint32_t,16> mpool;
Queue <uint32_t,16> queue;
Thread thread;
Mutex uart_mutex;
DigitalOut led(LED1);

void send_thread(void){
    uint32_t i=0;
    while(true){
        uint32_t *value=mpool.alloc();
        *value=i;
        queue.put(value);
        uart_mutex.lock();
        printf("Thread: %d\n", *value);
        uart_mutex.unlock();
        wait_us(400000);
        i++;
    }
}
int main() { 
    thread.start(&send_thread);
    while(true){
        osEvent evt=queue.get(0);
        if (evt.status==osEventMessage){
            led=!led;
            uint32_t *value =(uint32_t*)evt.value.p;
            uart_mutex.lock();
            printf("Main: %d\n", *value);
            uart_mutex.unlock();
            mpool.free(value);
        }
        uart_mutex.lock();
        printf("Main: waiting...\n");
        uart_mutex.unlock();
        wait_us(200000);
    }
}