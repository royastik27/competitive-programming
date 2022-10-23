#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 1000000007

int power(int base, ll p)
{
    if(p == 0) return 1;

    if(p & 1)
        return (ll)base * power(base, p-1) % MOD;
    else return power((ll)base*base % MOD, p/2);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 4;
    ll n = 16382LL;

    cout << power(a, n) << '\n';

    return 0;
}
