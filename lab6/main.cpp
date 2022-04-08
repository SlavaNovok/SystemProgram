#include "mbed.h"
#include "BME280.h"

BME280 sensor(PB_9, PB_8);
DigitalOut oled1(LED1);
// main() runs in its own thread in the OS
int main()
{

    while (1) {
        printf("%d degC, %d hPa, %d %%\n", 
        (int)sensor.getTemperature(), 
        (int)sensor.getPressure(), 
        (int)sensor.getHumidity());
        
        if ((int)sensor.getTemperature() > 29) {
        oled1 = 1;                
    }

        else {
            oled1 = 0;
        }
        wait_us(500000 );
    }   
}

