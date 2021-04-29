/**
* Codeforces Round #646 (Div. 2)
* Problem A - Odd Selection
* Unique Solution
* Time: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int TC, len, x, el, nEven, nOdd;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> len >> x;

        nEven = nOdd = 0;
        for(i = 0; i < len; ++i)
        {
            cin >> el;

            (el & 1) ? ++nOdd : ++nEven;
        }

        // considering odd number of odds
        if(!(nOdd & 1)) --nOdd;

        // filling up with odds
        if(nOdd >= x)
        {
            if(x & 1) x = 0;    // if x is even
            else x = 1;
        }
        else
            x -= nOdd;

        // filing up with even
        if(nEven >= x && nOdd > 0)
            cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
