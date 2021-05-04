/**
* SPOJ LOCKER - Magic of the locker
* Time: 0.42s
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MOD 1000000007

long long int power(long long int base, long long int power)
{
    long long int res = 1;

    while(power)
    {
        if(power & 1)
            res = res*base % MOD;

        base = base * base % MOD;
        power >>= 1;
    }

    return res;
}

int main()
{
    int TC, rem;
    long long int n, quo;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        quo = n / 3;
        rem = n % 3;

        if(n == 1)
            cout << 1 << '\n';
        else if(rem == 0)
            cout << power(3, quo) << '\n';
        else if(rem == 2)
            cout << power(3, quo) * 2 % MOD << '\n';
        else
            cout << power(3, quo-1) * 4 % MOD << '\n';
    }

    return 0;
}
