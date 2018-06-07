#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>

#define MAX_LEN 32


int main()
{

    std::string s;

    char ssid[MAX_LEN] = {"\0"};


    s = "This is my string";
    std::cout << s;
    std::cout << s.length() << std::endl;

    strncpy(ssid, s.c_str(),sizeof(ssid) - 2);
    std::cout << ssid << " " << strlen(ssid) << std::endl;


    strncpy(ssid, s.c_str(), 6);
    std::cout << ssid;

    strncpy(ssid, s.c_str(),sizeof(ssid) - 2);
    std::cout << ssid;

    //char max[MAX_LEN] = {'\0'};
    char max[MAX_LEN + 6];
    std::string more_max = "0123456789_0123456789_01234567890_1234";
    //char more_max = "0123456789_0123456789_01234567890_1234";

    strncpy(max, more_max.c_str(), sizeof(max));
    std::cout << max << std::endl;

    max[sizeof(max) - 1 ] = '\0';
    std::cout << max << std::endl;

    strncpy(max, more_max.c_str(), 15);
    std::cout << max << std::endl;

    max[15] = '\0';
    std::cout << max << std::endl;

    std::cout << sizeof(max) << std::endl;

    std::cout << max[0] << std::endl;
    std::cout << max[1] << std::endl;
    std::cout << max[14] << std::endl;
    std::cout << max[15] << std::endl;
    std::cout << (int)max[15] << std::endl;

    return 0;
}
