#include "mbed.h"
#include "mbed_events.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
InterruptIn sw(BUTTON1);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t1;
Thread t2;

void rise_handler(void) {
    printf("rise_handler in context %p\r\n", Thread::gettid());
    // Toggle LED
    led1 = !led1;   
}

void fall_handler(void) {
    printf("fall_handler in context %p\r\n", Thread::gettid());
    // Toggle LED
    led2 = !led2;
    printf("test");
}

int main() {
    // Start the event queue
    t1.start(callback(&queue, &EventQueue::dispatch_forever));
    t2.start(callback(&queue, &EventQueue::dispatch_forever));
    printf("Starting in context %p\r\n", Thread::gettid());
    // The 'rise' handler will execute in IRQ context
    sw.rise(queue.event(rise_handler));
    // The 'fall' handler will execute in the context of thread 't'
    sw.fall(queue.event(fall_handler));
    while(true){
        led3 = !led3;
        Thread::wait(2000);
    }
}