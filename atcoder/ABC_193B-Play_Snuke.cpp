/**
* AtCoder Beginner Contest 193
* Problem B - Play Snuke
* Time: 97 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define INF 1000000001

int main()
{
    int nShops, time, yen, inStock, min;

    cin >> nShops;

    min = INF;
    while(nShops--)
    {
        cin >> time >> yen >> inStock;

        if((inStock - time) > 0 && yen < min)
            min = yen;
    }

    if(min == INF)
        cout << -1;
    else
        cout << min;

    cout << '\n';

    return 0;
}
