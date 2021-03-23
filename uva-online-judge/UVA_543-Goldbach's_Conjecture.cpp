/**
* UVA 543 - Goldbach's Conjecture
* AUTHOR: Astik Roy
**/

#include <iostream>

#define SEIVE_SIZE 1000000
#define NUMBER_PRIMES 78498

void readySeive(bool seive[], int primes[])
{
    int i, j;

    for(i = 2; i<=SEIVE_SIZE; i++)
        seive[i] = 1;

    for(i = 2; i*i<=SEIVE_SIZE; i++)
    {
        if(seive[i])
        {
            for(j = i*i; j<=SEIVE_SIZE; j+=i)
            {
                seive[j] = 0;
            }
        }
    }

    for(i = 2, j = -1; i<=SEIVE_SIZE; i++)
    {
        if(seive[i])
        {
            primes[++j] = i;
        }
    }
}

bool isPrime(int n)
{
    if(n == 2)
        return 1;
    for(int i = 2; i*i<=n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    bool seive[SEIVE_SIZE+1];
    int primes[NUMBER_PRIMES], i, n1, n2;

    readySeive(seive, primes);

    int data;

    while(1)
    {
        std::cin >> data;

        if(!data) break;

        n1 = n2 = 0;

        for(i = 0; primes[i]<data; i++)
        {
            if(isPrime(data-primes[i]))
            {
                n1 = primes[i];
                n2 = data - primes[i];
                break;
            }
        }

        level:
        if(!n1)
        {
            std::cout << "Goldbach's conjecture is wrong." << std::endl;
        }
        else
        {
            std::cout << data << " = " << n1 << " + " << n2 << std::endl;
        }
    }

    return 0;
}
