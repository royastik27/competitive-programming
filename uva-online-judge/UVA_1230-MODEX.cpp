/**
* UVa 1230 - MODEX
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int TC, base, power, mod, res;

    cin >> TC;

    while(TC--)
    {
        cin >> base >> power >> mod;

        res = 1;

        while(power)
        {
            // if power is odd
            if(power & 1)
                res = res * base % mod;

            base = base * base % mod;
            power >>= 1;
        }

        cout << res << '\n';
    }

    // the last zero
    cin >> TC;

    return 0;
}
