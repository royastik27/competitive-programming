/**
* Codeforces Round #261 (Div. 2)
* Problem B - Pashmak and Flowers
* Time: 264 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

#define INF 1000000001

int main()
{
    ios_base::sync_with_stdio(0);

    int nFlowers, beauty, Max, Min;
    map <int, int> Count;

    cin >> nFlowers;

    Max = 0;
    Min = INF;
    while(nFlowers--)
    {
        cin >> beauty;

        if(beauty > Max)
            Max = beauty;
        if(beauty < Min)
            Min = beauty;

        if(Count.insert(make_pair(beauty, 1)).second == false)
            ++Count[beauty];
    }

    cout << Max - Min << ' ';
    if(Max == Min)
        cout << (long long)Count[Max] * (Count[Max]-1) / 2 << '\n';
    else
        cout << (long long)Count[Max] * Count[Min] << '\n';

    return 0;
}
