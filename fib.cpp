#include <iostream>
#include <gmp.h>

int main()
{

    /*
    unsigned long answer = 0;
    unsigned long long  current = 1;
    unsigned long long previous = 0;
    */

    mpz_t answer;
    mpz_t current;
    mpz_t previous;

    mpz_init(answer);
    mpz_init(current);
    mpz_init(previous);

    mpz_set_ui(answer,0);
    mpz_set_ui(current,1);
    mpz_set_ui(previous,0);

    for (int i = 2; i < 50; i++) {
        /*
        answer = current + previous;
        previous = current;
        current = answer;
        std::cout << "#" << i+1 << " : " << answer << std::endl;
        */

        mpz_add(answer,current,previous);
    }

    std::cout << "Answer: " << answer << std::endl;

    return 0;
}   
