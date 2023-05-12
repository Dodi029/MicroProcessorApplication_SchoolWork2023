#include "mbed.h"
Mutex mutex;
Thread t2, t3;
int cnt=0;
DigitalOut led(LED1);

void notify(const char* name, int ct) {
    printf("%s: %3d\n\r", name, ct);
}
void thread_plus(const char *args) {
    while (true) {
        mutex.lock();
        led = !led;
        notify((const char*)args, ++cnt);
        mutex.unlock();
        wait_us(490000);
    }
}

void thread_mius(const char *args) {
    while (true) {
        mutex.lock();
        notify((const char*)args, --cnt);
        mutex.unlock();
        wait_us(1000000);
    }
}
// main() runs in its own thread in the OS
int main()
{
    t2.start(callback(&thread_plus, (const char *)"Th 2"));
    t3.start(callback(&thread_mius, (const char *)"Th 3"));

    thread_mius((const char *)"Th 1");
}

