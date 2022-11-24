/**
* CodeChef JOGGING - Jogging
* TIME: 0.03 sec
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MOD 1000000007

int getPower(int base, int power)
{
    if(power == 0) return 1;

    if(power & 1)
        return (long long int) base * getPower(base, power-1) % MOD;
    
    return getPower( (long long int)base*base % MOD, power / 2 );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, x, i;

    cin >> TC;

    while(TC--)
    {
        cin >> n >> x;

        cout << (long long int) x * getPower(2, n-1) % MOD << '\n';
    }

    return 0;
}
