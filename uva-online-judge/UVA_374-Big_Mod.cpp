/**
* UVA 374 - Big Mod
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int base, power, mod, res;

    while(cin >> base)
    {
        cin >> power >> mod;

        res = 1;

        while(power)
        {
            // if power is even
            if(power & 1)
                res = (long long)res * base % mod;

            base = (long long)base * base % mod;
            power >>= 1;    // power /= 2
        }

        cout << res << '\n';
    }

    return 0;
}
