#include <iostream>

using namespace std;

int fact(int x)
{
    if (x == 0) {
        return 1;
    }
    return fact(x-1) * x;
}

int getInt()
{
    cout << "Enter a number : ";
    int x;
    cin >> x;
    return x;
}

int sumInt(int x)
{
    
    if (x == 0) {
        return 0;
    } 

    return (sumInt(x/10) + (x%10));

}

void binary(int y)
{
    int x;
    if (y > 0) {
        x = y % 2;
        y = y / 2;
        binary(y);
        cout << x;
    }
}


int main ()
{

    int y = getInt();

    cout << sumInt(y) << endl;

    binary(y);
    cout << endl;

    for (int i = 7; i > 0; i--) {
        std::cout << fact(i) << std::endl;
    }
    return 0;
}
