#include <iostream>
#include <bignum>

using namespace std;

int main()
{
    cout << "fib sequence" << endl;

    unsigned long long answer;
    unsigned long long previous = 0;
    unsigned long long current = 1; 

    for (int i = 2; i < 300; i++) {
        answer = previous + current;
        previous = current;
        current = answer;
        cout << "#" << i+1 << ":" << answer << endl;
    }
    cout << "Answer is: " << answer << endl;

}
