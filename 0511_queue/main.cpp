#include "mbed.h"
typedef struct {
    float voltage, current;
    uint32_t counter;
} message_t;
MemoryPool < message_t, 16 > mpool;
Queue < message_t, 16 > queue;
Thread thread;
void generator (void) {
    uint32_t i = 0;
    while (true) {
        i++;
        message_t *message = mpool.alloc();
        message->voltage = (i*0.1) * 33;
        message->current = (i*0.1) * 11;
        message->counter = i;
        queue.put(message);
        wait_us(1000000);
    }
}
// main() runs in its own thread in the OS
int main()
{
    thread.start(&generator);
    while(true) {
        osEvent evt = queue.get();
        if(evt.status == osEventMessage) {
            message_t * message = (message_t*)evt.value.p;
            printf("\nVoltage: %.2 V\n", message->voltage);
            printf("Current: %.2f A\n", message->current);
            printf("Number of cycles: %u\n", message->counter);
            mpool.free(message);
        }
    }
}

