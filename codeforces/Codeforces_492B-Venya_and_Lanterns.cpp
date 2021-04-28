/**
* Codeforces Round #280 (Div. 2)
* Problem B - Vanya and Lanterns
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, len, lantern[1000];
    double Max, red;
    register int i;

    cout << fixed << setprecision(9);

    cin >> n >> len;

    for(i = 0; i < n; ++i)
        cin >> lantern[i];

    sort(lantern, lantern+n);

    Max = max(lantern[0]-0, len-lantern[n-1]);

    for(i = 1; i < n; ++i)
    {
        red = (lantern[i] - lantern[i-1]) / 2.0;

        if(red > Max)
            Max = red;
    }

    cout << Max << '\n';

    return 0;
}
