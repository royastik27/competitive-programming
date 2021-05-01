#include <iostream>
#include <cmath>

using namespace std;

#define LIMIT 100000
#define PRIME_LIMIT 10000

int primes[PRIME_LIMIT];

void seive()
{
    int i, j, root;
    bool isPrime[LIMIT + 1];

    for(i = 3; i <= LIMIT; i += 2)
        isPrime[i] = true;

    root = sqrt(LIMIT);

    for(i = 3; i <= root; i += 2)
    {
        if(isPrime[i])
        {
            for(j = i*i; j <= LIMIT; j += i+i)
                isPrime[j] = false;
        }
    }

    j = 0;
    primes[j++] = 2;
    for(i = 3; i <= LIMIT; i += 2)
    {
        if(isPrime[i])
            primes[j++] = i;
    }

    cout << "Total " << j << " primes.\n";
    cout << "Last prime: " << primes[j-1] << '\n';
}

int main()
{
    seive();


    return 0;
}
