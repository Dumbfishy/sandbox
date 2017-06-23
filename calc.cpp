#include <iostream>

using namespace std;

int add(int x, int y);
int subtrat(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int getInteger();
char getOperation();

typedef int (*arithmeticFcn)(int, int);
              
arithmeticFnc getArithmeticFunction(char op);


int main()
{
    cout << "~~Calc~~" << endl;

    int x = getInteger();
    char op = getOperation();
    int y = getInteger();

    return 0;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

int getInteger()
{

    cout << "Enter an integer: ";
    
    int input;
    cin >> input;
    return input;
}

char getOperation()
{
    cout << "Enter operation (+,-,*,/): ";
    char oper;
    do {
        cin >> oper;
    } while (oper != '+' && oper !='-' && oper != '*' && oper != '/');

    return oper;
}

