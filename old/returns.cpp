#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Employee {
    int employeeNumber;
    string employeeName;
};



int sumTo(int value);
void printEmployeeName(Employee employee);
void minmax(int value1, int value2);
int getIndexOfLargestValue(std::array<int,10> *array, int &largestIndex);
void getElement(std::array<int,10> *array, int index);


int main()
{

    cout << sumTo(7) << endl;



    return 0;
}

int sumTo(int value)
{
    int sum = 0;

    for (int i = 0; i < value; i++) {
        sum += i;
    }

    return sum;
}
