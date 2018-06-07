// Read mac from file

#include <stdio.h>
#include <stdint.h>

#include <linux/kernel.h>
#include <linux/fcntl.h>
//#define BUZZ_SIZE 1024
#define WIFI_MAC_FILE "wifiMac"
#define BUFF_SIZE 18

int main(int argc, char **argv)
{
   int i = 0;
   int fd = 0;
   uint8_t macAddr[6];
   char buff[BUFF_SIZE];

    fd = open(WIFI_MAC_FILE, O_RDONLY, 0);

    if(fd < 0) {
        printf("Error opening / reading file :%s\n", WIFI_MAC_FILE);
        return -1;
    } else {
        if (read(fd, buff, BUFF_SIZE) == BUFF_SIZE) {
        	printf("Read Device Mac from %s: %s\n",WIFI_MAC_FILE, buff);
            /*
             * Mac Address should be stored as XX:XX:XX:XX:XX:XX format
             * increment the string buffer ahead by 3 to account for the ":"
             */
            for (i = 0; i < 6; i++) {
                macAddr[i] = (uint8_t)strtol(&buff[i*3], NULL, 16);
            }
        }
    }
    close(fd);
    printf("String read: %02x\n", macAddr[0]);
    printf("String read: %02x\n", macAddr[1]);
    printf("String read: %02x\n", macAddr[2]);
    printf("String read: %02x\n", macAddr[3]);
    printf("String read: %02x\n", macAddr[4]);
    printf("String read: %02x\n", macAddr[5]);


    printf("Print Hex: %i\n", *macAddr);

    return 0;
}



//
//

