#include "mbed.h"

DigitalOut testled(PC_7);
// Объявляем пин кнопки 1 как вход прерывания
InterruptIn ibutton1(BUTTON1);
// Задержка, 1 секунда == 1000 мс
static auto sleep_time = 1000ms;
// main() runs in its own thread in the OS

#define PRINT_FLAG 5
Thread thread;
void print_thread() {
    while (ThisThread::flags_get() != PRINT_FLAG) {
        printf("Hello\n");
        testled = 0;
        ThisThread::sleep_for(500ms);
    }
    printf("Bye\n");
   testled = 1; 
}

//void pressed() {
    // Управление скоростью мерцания светодиода
//    sleep_time -= 200ms;
//    if (sleep_time < 300ms)
//        sleep_time = 1000ms;
//}

int main() {
    testled = 1;
    // Вывод текста в терминал
    thread.start(print_thread);
    ThisThread::sleep_for(5s);
    
    // Задаем потоку значение флага PRINT_FLAG
    thread.flags_set(PRINT_FLAG);
    
    // Прикрепляем функцию для обработки нажатия
    //ibutton1.rise(&pressed); 
    //while (true) {
     //   testled = !testled;
    //    ThisThread::sleep_for(sleep_time);

    //}

}
