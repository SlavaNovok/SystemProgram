#include "mbed.h"

DigitalOut oled1(LED1);
// Объявляем пин кнопки 1 как вход прерывания
InterruptIn ibutton1(PB_10);
// Задержка, 1 секунда == 1000 мс
static auto sleep_time = 1000ms;
// main() runs in its own thread in the OS

void pressed()
{
// Управление скоростью мерцания светодиода
sleep_time -= 200ms;
if (sleep_time < 300ms)
sleep_time = 1000ms;
}



int main()
{


// Прикрепляем функцию для обработки нажатия

ibutton1.rise(&pressed); 
while (true) {
oled1 = 1; // Включение светодиода
ThisThread::sleep_for(sleep_time); // Задержка в 1 секунду
oled1 = 0; // Выключение светодиода
ThisThread::sleep_for(sleep_time);
}

}

