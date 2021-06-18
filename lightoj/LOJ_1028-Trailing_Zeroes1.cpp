/**
* LightOJ 1028 - Trailing Zeroes (I)
* Time: 306 ms
* AUTHOR: Astik Roy
**/

#include <stdio.h>
#include <cmath>

using namespace std;

#define PRIME_LIMIT 78504
#define LIMIT 1000100

int primes[PRIME_LIMIT];

void seive()
{
    int i, j, root = sqrt(LIMIT), k = -1;
    bool isPrime[LIMIT + 1];

    for(i = 3; i <= LIMIT; i += 2)
        isPrime[i] = true;

    primes[++k] = 2;

    for(i = 3; i <= root; i += 2)
    {
        if(isPrime[i])
        {
            for(j = i*i; j <= LIMIT; j += i + i)
            isPrime[j] = false;
        }
    }

    for(i = 3; i <= LIMIT; i += 2)
    {
        if(isPrime[i])
            primes[++k] = i;
    }

    return;
}

int main()
{
    int TC, NOD, k = 0, power, root, i;
    long long int num;

    seive();

    scanf("%d", &TC);

    while(TC--)
    {
        scanf("%lld", &num);

        root = sqrt(num);

        NOD = 1;

        for(i = 0; (long long int)primes[i]*primes[i] <= num; ++i)
        {
            if(num % primes[i] == 0)
            {
                power = 0;
                while(num % primes[i] == 0)
                {
                    ++power;
                    num /= primes[i];
                }
                NOD *= (power+1);
            }
        }

        // maximum one prime factor more than the square root
        if(num > 1) NOD *= 2;

        printf("Case %d: %d\n", ++k, NOD-1);
    }

    return 0;
}
