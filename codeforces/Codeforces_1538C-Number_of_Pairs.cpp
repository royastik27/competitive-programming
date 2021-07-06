/**
 * Codeforces Round #725 (Div. 3)
 * Problem C - Number of Pairs
 * Time: 140 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 200000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, ara[LIM], left, right, low, high;
    long long int res;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n >> left >> right;

        for(i = 0; i < n; ++i)
            cin >> ara[i];

        sort(ara, ara+n);

        res = 0;
        for(i = 0; i < n; ++i) {
            high = right - ara[i];
            if(high < 0) continue;

            low = left - ara[i];
            if(low < 0) low = 0;

            res += upper_bound(ara, ara+n, high) - lower_bound(ara, ara+n, low);

            if(ara[i] >= low && ara[i] <= high) --res;
        }

        cout << res / 2 << '\n';
    }

    return 0;
}
