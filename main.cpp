#include <stdio.h>

#include "mbed.h"
#include "EthernetInterface.h"
#include "wizfi310-driver/WizFi310Interface.h"

#define WIFI_SSID "APD Surveillance Van #24"
#define WIFI_PASSWORD "XXXXXXXXXXXXX"
WizFi310Interface net(D1, D0, true);

DigitalOut led1(LED1);
DigitalOut led2(LED2);


int main(int argc, const char **argv) {
    printf("main started\n");

    net.connect(WIFI_SSID, WIFI_PASSWORD, NSAPI_SECURITY_WPA_WPA2, 0);

    printf("connect done\n");
    const char *ip = net.get_ip_address();
    if (ip == NULL) {
        printf("Failed to connect to network. Not sure why\n");
        while(1) {
            led2 = 1;
            wait(0.05);
            led2 = 0;
            wait(0.05);
        }
    }
    printf("IP address is %s\n", ip ? ip: "No IP");
    while(1) {
        led1 = 1;
        wait(0.5);
        led1 = 0;
        wait(0.5);
    }
}

