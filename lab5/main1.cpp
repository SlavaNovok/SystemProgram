#include "mbed.h"

DigitalOut testled(PC_7);
InterruptIn ibutton1(BUTTON1);
static auto sleep_time = 1000ms;

typedef struct {
    float voltage; /* результат измерения напряжения */
    float current; /* результат измерения тока*/
    uint32_t counter;
    int test;
} message_t;
/*здесь используется объект класса MemoryPool, для определения и
управления пулом памяти фиксированного размера, информацию об этом
классе изучите в документации */
MemoryPool<message_t, 16> mpool;
Queue<message_t, 16> queue;
Thread thread;
/* поток отправитель */

void pressed() {
    // Управление скоростью мерцания светодиода
    sleep_time -= 200ms;
    if (sleep_time < 300ms)
        sleep_time = 1000ms;
}

void send_thread(void) {
    uint32_t i = 0;
    while (true) {
        i++; /* так как настоящие данные брать неоткуда здесь они
        генерируются*/
        message_t *message = mpool.alloc();
        message->voltage = (i * 0.1) * 33;
        message->current = (i * 0.1) * 11;
        message->counter = i;
        message->test = testled;
        
        queue.put(message);
        ThisThread::sleep_for(sleep_time);
    }
}

int main(void) {
    thread.start(callback(send_thread));
    ibutton1.rise(&pressed);
    while (true) {
        osEvent evt = queue.get();
        if (evt.status == osEventMessage) {
            message_t *message = (message_t *)evt.value.p;
            printf("\nVoltage: %.2f V\n\r", message->voltage);
            printf("Current: %.2f A\n\r", message->current);
            printf("Number of cycles: %u\n\r", message->counter);
            printf("diod: %u\n\r", message->test);
            mpool.free(message);
            testled = !message->test;
        }
        
    }
    
}