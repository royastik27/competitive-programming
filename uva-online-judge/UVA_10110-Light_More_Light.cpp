/**
* UVa 10110 - Light, more light
* Unique Solution, but not the simplest approach
* Square numbers have odd number of divisors
* Time: 0.700 sec
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define LIMIT 65600

typedef long long int ll;

int primes[6552];

void seive()
{
    bool isPrime[LIMIT + 1];

    memset(isPrime, 1, sizeof(isPrime));

    int i, j, root;

    root = sqrt(LIMIT);
    for(i = 3; i <= root; i+=2)
    {
        if(isPrime[i]) {
            for(j = i*i; j <= LIMIT; j += i+i)
                isPrime[j] = false;
        }
    }

    j = 0;
    primes[j++] = 2;

    for(i = 3; i <= LIMIT; i+=2)
    {
        if(isPrime[i])
            primes[j++] = i;
    }

    return;
}

ll NOD(ll n)
{
    int i, pow;
    ll nod = 1;

    for(i = 0; (long long)primes[i]*primes[i] <= n; ++i)
    {
        pow = 0;

        while(n % primes[i] == 0){
            ++pow;
            n /= primes[i];
        }

        nod *= (pow+1);
    }

    if(n > 1) nod *= 2;

    return nod;
}

int main()
{
    seive();

    ll num, nod;

    while(cin >> num && num)
    {
        nod = NOD(num);

        // if number of divisors is odd
        if(nod & 1) cout << "yes\n";
        // otherwise
        else cout << "no\n";
    }

    return 0;
}
