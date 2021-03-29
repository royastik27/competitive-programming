/**
* Educational Codeforces Round 92 (Rated for Div. 2)
* Problem A - LCM Problem
* Time: 77 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int TC, left, right, x, y;

    cin >> TC;

    while(TC--)
    {
        cin >> left >> right;

        x = y = -1;

        if(left * 2 <= right)
        {
            x = left;
            y = left * 2;
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
