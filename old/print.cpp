
#include <iostream>
#include <string>

using namespace std;


void printString(char word[]);

int main (void) 
{
    
    char word[] = "Hello, world!";
    printString(word);


    return 0;
}


void printString(char word[])
{
    
    for (int i = 0; ; i++)
    {
        if (word [i] == '\0') {
            break;
        } else {
            cout << word[i];
        }
    }


}

