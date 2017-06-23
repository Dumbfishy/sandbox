
#include <iostream>
#include <string>

using namespace std;


void swap(int &x, int &y);

int main (void) 
{

    int x = 5;
    int y = 9;
    cout << "x = " << x << ", y = " << y << endl;

    swap(x,y);

    cout << "x = " << x << ", y = " << y << endl;
    
    return 0;
}


void swap(int &x, int &y)
{
    int tmp = 0;

    tmp = x;
    x = y;
    y = tmp;

}

