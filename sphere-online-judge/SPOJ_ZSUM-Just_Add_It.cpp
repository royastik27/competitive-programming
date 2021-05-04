/**
* SPOJ ZSUM - Just Add It
* Time: 0.05s
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MOD 10000007

int power(int base, int index)
{
    if(index == 0) return 1;

    if(index & 1)
        return (long long)base * power(base, index-1) % MOD;
    else
        return power((long long)base * base % MOD, index >> 1);
}

int main()
{
    int n, k;

    while(cin >> n >> k && n)
        cout << (power(n, k) + power(n, n) + 2*power(n-1, k) + 2*power(n-1, n-1)) % MOD << '\n';

    return 0;
}
