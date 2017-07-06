#include <iostream>

using namespace std;

int getInt()
{
    int x;
    cout << "enter an integer: ";
    cin >> x;
    return x;
}

int getNextPrime(int current_prime)
{
    int next_prime = current_prime + 1;

    for ( int i = next_prime - 1; i > 1; i--) {
        if(next_prime % i == 0) {
            return getNextPrime(next_prime);
        }
    }

    return next_prime;
}
int main()
{

    int number = 0;
    int sum = 0;
    int prime_factor = 2;

    number = getInt();

    while (number > 1) {
        if( number % prime_factor == 0) {
            number = number / prime_factor;
            sum += prime_factor;
            cout << "factor: " << prime_factor
                 << "  Current Sum: " << sum << endl;
        } else {
            prime_factor = getNextPrime(prime_factor);
        }
    }

    cout << "Sum of prime factors is: " << sum << endl;


    return 0;
}
