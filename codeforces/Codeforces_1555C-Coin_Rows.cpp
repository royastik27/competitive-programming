/**
 * Educational Codeforces Round 112 (Rated for Div. 2)
 * Problem C - Coin Rows
 * Time: 108 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100001
#define INF 1000000000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, nCols, coins, r1[LIM], pre, post[LIM], res;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> nCols;

        for(i = 0; i < nCols; ++i) {
            cin >> r1[i];
        }

        post[nCols-1] = 0;
        for(i = nCols-2; i >= 0; --i)
            post[i] = post[i+1] + r1[i+1];

        res = INF;
        pre = 0;
        for(i = 0; i < nCols; ++i) {
            cin >> coins;
            res = min(max(pre, post[i]), res);
            pre += coins;
        }

        cout << res << '\n';
    }

    return 0;
}
