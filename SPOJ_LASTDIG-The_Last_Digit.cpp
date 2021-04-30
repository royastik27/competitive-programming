/**
* SPOJ LASTDIG - The last digit
* Time: 0.01s
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int TC, a, b, res;

    cin >> TC;

    while(TC--)
    {
        cin >> a >> b;

        res = 1;
        while(b)
        {
            if(b & 1)
                res = res * a % 10;

            a = a*a % 10;
            b >>= 1;
        }

        cout << res << '\n';
    }

    return 0;
}
