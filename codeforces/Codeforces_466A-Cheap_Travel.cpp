/**
* Codeforces Round #266 (Div. 2)
* Problem A - Cheap Travel
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define LIMIT 150001

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, a, b, cost, special;

    cin >> n >> m >> a >> b;

    if(m > n)
    {
        if(b < n*a)
            cost = b;
        else cost = n*a;
    }
    else
    {
        special = floor((double)n / m);

        if(special*b < special*m*a)
            cost = special * b;
        else
            cost = special*m*a;

        n -= special*m;

        if(n)
        {
            if(b < n * a)
                cost += b;
            else
                cost += n*a;
        }
    }

    cout << cost << '\n';

    return 0;
}
