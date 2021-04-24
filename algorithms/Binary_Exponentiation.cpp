#include <iostream>

using namespace std;

typedef long long int ll;

ll power(ll a, ll n)
{
    if(n == 0) return 1;

    if(n % 2 == 0)
        return power(a*a, n/2);
    else
        return a * power(a, n-1);
}


int main()
{
    ios_base::sync_with_stdio(false);

    ll a = 3;
    ll n = 13;

    cout << power(a, n) << '\n';

    return 0;
}
