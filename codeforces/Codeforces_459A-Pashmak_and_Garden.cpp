/**
* Codeforces Round #261 (Div. 2)
* Porblem A - Pashmak and Garden
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int x1, x2, y1, y2, temp;

    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2)
    {
        temp = abs(y2-y1);
        x1 += temp;
        x2 += temp;
    }
    else if(y1 == y2)
    {
        temp = abs(x2-x1);
        y1 += temp;
        y2 += temp;
    }
    else
    {
        // for diagonal
        if(abs(x2-x1) != abs(y2-y1))
        {
            cout << -1 << '\n';
            return 0;
        }
        else
        {
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
    }

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';

    return 0;
}
