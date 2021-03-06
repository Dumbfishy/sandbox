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
    int next_prime;

    //other than 2 -> 3, all other primes will be at least 2 higher
    //than the current prime (primes are odd other than 2)
    if(current_prime == 2) {
        next_prime = current_prime + 1;
    } else {
        next_prime = current_prime + 2;
    }

    //to see if test number is prime 

    for ( int i = next_prime - 1; i > 1; i--) {
        if(next_prime % i == 0) {
            return getNextPrime(next_prime);
        }
    }

    return next_prime;
}
int main()
{
    //init variables
    int number = 0;
    int sum = 0;
    int prime_factor = 2;

    //Get input number from user
    number = getInt();

    //store input for unique sums 
    int second_number = number;

    //if the number can be divided by the prime do so and add it to the sum
    //otherwise find the next prime number
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

    int previous_prime = 0;
    sum = 0;
    prime_factor = 2;
    number = second_number;

    while (number > 1) {
        if( number % prime_factor == 0 && previous_prime != prime_factor) {
            number = number / prime_factor;
            sum += prime_factor;
            previous_prime = prime_factor;
            cout << "factor: " << prime_factor
                 << "  Current Sum: " << sum << endl;
        } else if (number % prime_factor == 0) {
            number = number / prime_factor;
            cout << "factor: " << prime_factor
                 << "  Current Sum: " << sum << endl;
        } else {
            prime_factor = getNextPrime(prime_factor);
        }
    }

    cout << "Sum of unique prime factors is: " << sum << endl;

    return 0;
}
