#include <stdio.h>

#include "mbed.h"
#include "EthernetInterface.h"
#include "wizfi310-driver/WizFi310Interface.h"

#define WIFI_SSID "Penfoldlo"
#define WIFI_PASSWORD "deadbeef01"

DigitalOut led1(LED1);

int main(int argc, const char **argv) {
    led1 = 0;
    printf("Sleeping\n");
    wait_ms(3000);
    printf("main started\n");
    WizFi310Interface net(D1, D0, true);
    

    net.connect(WIFI_SSID, WIFI_PASSWORD, NSAPI_SECURITY_WPA_WPA2, 0);

    printf("connect done\n");
    const char *ip = net.get_ip_address();
    if (ip == NULL) {
        printf("Failed to connect to network. Not sure why\n");
        while(1) {
            led1 = 1;
            wait(0.05);
            led1 = 0;
            wait(0.05);
        }
    }
    printf("IP address is %s\n", ip ? ip: "No IP");
  
    while(1) {
        led1 = 1;
        wait(4);
        led1 = 0;
        wait(4);
    }
}

