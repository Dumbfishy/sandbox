#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv)
{
    uint8_t input_mac[6] = {0x2,0x65,0xFF,0xAB,0xCD,0x12};
    uint8_t *ptr = NULL;

    printf("&input_mac=%p, input_mac=%p, &input_mac[0]=%p\n",
            &input_mac, input_mac, &input_mac[0]);


    printf("&ptr=%p, ptr=%p\n array = %p", &ptr, ptr, input_mac);
    //printf("&int_ptr=%p, int_ptr=%p\n", &int_ptr, int_ptr);
    return(0);

}

