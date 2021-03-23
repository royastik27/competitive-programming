/**
* UVA 11466 - Largest Prime Divisor
* Time: 80 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define LIMIT 100000
#define SQRT 10000000
#define PRIME_LIMIT 664579

vector <int> prime;

void seive()
{
    bool isPrime[LIMIT + 1];

    int i, j, root;

    for(i = 3; i <= LIMIT; i += 2)
        isPrime[i]  = true;

    root = ceil(sqrt(LIMIT));
    for(i = 3; i <= root; i += 2)
    {
        for(j = i*i; j <= LIMIT; j += 2 * i)
            isPrime[j] = false;
    }

    prime.push_back(2);

    for(i = 3; i <= LIMIT; i += 2)
    {
        if(isPrime[i])
            prime.push_back(i);
    }
}

void segmented_seive()
{
    int low, high, part, i, j;

    low = LIMIT;
    high = 2 * LIMIT;

    while(high <= SQRT)
    {
        bool isPrime[LIMIT + 1];

        for(i = 1; i <= LIMIT; i += 2)
            isPrime[i] = true;

        for(i = 1; prime[i] * prime[i] <= high; ++i)
        {
            part = ceil((double)low / prime[i])*prime[i];
            for(j = part; j <= high; j += prime[i])
            {
                isPrime[j - low] = false;
            }
        }

        for(i = 1; i <= LIMIT; i += 2)
        {
            if(isPrime[i])
                prime.push_back(i + low);
        }

        low = high;
        if(low == SQRT)
            break;

        high = low + LIMIT;

        if(high > SQRT)
            high = SQRT;
    }
}

void print_primes()
{
    cout << "Primes:\n";
    for(int i = 0; i < prime.size(); ++i)
        cout << prime[i] << ' ';
    cout << '\n';
}

bool isPrime(int num)
{
    if(num % 2 == 0)
        return false;

    for(int i = 3; i*i <= num; ++i)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    seive();
    segmented_seive();

    long long int num, LPD;
    int i, Count, root;

    while(cin >> num && num)
    {
        if(num < 0)
            num = 0 - num;

        root = ceil(sqrt(num));

        Count = 0;

        for(i = 0; prime[i] <= root; ++i)
        {
            if(num % prime[i] == 0)
            {
                LPD = prime[i];
                ++Count;

                while(num % prime[i] == 0)
                    num /= prime[i];
            }
        }

        if(num > 1)
        {
            ++Count;
            LPD = num;
        }

        if(Count > 1)
            cout << LPD << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
