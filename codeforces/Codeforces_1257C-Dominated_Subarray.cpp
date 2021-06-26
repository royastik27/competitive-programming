/**
* Educational Codeforces Round 76 (Rated for Div. 2)
* Problem C - Dominated Subarray
* Time: 109 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, prev[LIM], el, dist, Mn;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        memset(prev, 0, sizeof(prev));

        Mn = LIM;
        for(i = 1; i <= n; ++i) {
            cin >> el;

            if(prev[el]) {
                dist = i - prev[el] + 1;

                if(dist < Mn) Mn = dist;
            }

            prev[el] = i;
        }

        if(Mn == LIM) cout << -1 << '\n';
        else cout << Mn << '\n';
    }

    return 0;
}
