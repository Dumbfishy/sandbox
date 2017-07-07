#include <iostream>
#include <array>

using namespace std;

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int getInteger();
char getOperation();

typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFunction(char op);

struct arithmeticStruct {
    char op;
    arithmeticFcn Ptr;
};

static arithmeticStruct arithmeticArray[] = {
    {'+',add},
    {'-',subtract},
    {'*',multiply},
    {'/',divide}        
};

int main()
{
    cout << "~~Calc~~" << endl;


    int x = getInteger();
    char op = getOperation();
    int y = getInteger();
    
    arithmeticFcn Ptr = getArithmeticFunction(op);

    cout << "Results: " << Ptr(x,y) << endl;

    return 0;
}

arithmeticFcn getArithmeticFunction(char op)
{

    for (int i = 0; i < 4; i++) {
        if (arithmeticArray[i].op == op) {
            return arithmeticArray[i].Ptr;
        }
    }

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

