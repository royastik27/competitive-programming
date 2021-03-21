/**
* UVA 10699 - Count the factors
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define SQRT_LIMIT 1000

vector <int> prime;

void seive()
{
    bool isPrime[SQRT_LIMIT + 1];
    int i, j, sqrt = 32;

    for(i = 1; i <= SQRT_LIMIT; ++i)
        isPrime[i] = true;

    for(i = 3; i <= sqrt; i+=2)
    {
        for(j = i*i; j <= SQRT_LIMIT; j += (2*j))
            isPrime[j] = false;
    }

    prime.push_back(2);

    for(i = 3; i <= SQRT_LIMIT; i+=2)
    {
        if(isPrime[i])
            prime.push_back(i);
    }
}

void print_primes()
{
    cout << "Primes:\n";
    for(int i = 0; i < prime.size(); ++i)
        cout << prime[i] << ' ';
    cout << '\n';
}

int main()
{
    seive();
    //print_primes();

    int num, i, temp, res;

    while(cin >> num && num)
    {
        temp = num;
        res = 0;

        for(i = 0; prime[i]*prime[i] <= temp; ++i)
        {
            if(temp % prime[i] == 0)
            {
                ++res;

                while(temp % prime[i] == 0)
                    temp /= prime[i];
            }
        }

        if(temp)
            ++res;

        cout << num << " : " << res << '\n';
    }

    return 0;
}
