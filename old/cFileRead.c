// Read mac from file

#include <stdio.h>
#include <stdint.h>

#define BUZZ_SIZE 1024
#define WIFI_MAC_FILE "wifiMac"

int main(int argc, char **argv)
{
    char buff[BUZZ_SIZE];
    uint8_t macAddr[6];
    int i = 0;
    FILE *file = NULL;

    file = fopen(WIFI_MAC_FILE, "r");

    if(file == NULL) {
        printf("Error opening / reading file :%s\n", WIFI_MAC_FILE);
        return -1;
    }

    if (fgets(buff, BUZZ_SIZE, file) != NULL) {
        printf("Read Device Mac from %s: %s\n",WIFI_MAC_FILE, buff);
    }


    /*
     * Mac Address should be stored as XX:XX:XX:XX:XX:XX format
     * move the string buffer ahead by 3 to account for the ":"
     */
    for (i = 0; i < 6; i++) {
        if (buff[i*3]) {

        }
        macAddr[i] = (uint8_t)strtol(&buff[i*3], NULL, 16);
    }


    printf("String read: %02x\n", macAddr[0]);
    printf("String read: %02x\n", macAddr[1]);
    printf("String read: %02x\n", macAddr[2]);
    printf("String read: %02x\n", macAddr[3]);
    printf("String read: %02x\n", macAddr[4]);
    printf("String read: %02x\n", macAddr[5]);


    printf("Print Hex: %i\n", *macAddr);

    if (file) {
        fclose(file);
    }
    return 0;
}



//
//

