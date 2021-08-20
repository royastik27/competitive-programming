/**
 * Codeforces Round #171 (Div. 2)
 * Problem B - Books
 * Time: 92 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100001

int pre[LIM], n;

int bound(int val)
{
    int b = 0, e = n, mid;

    while(b <= e) {
        mid = (b + e) / 2;

        if(val >= pre[mid])
            b = mid + 1;
        else
            e = mid - 1;
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int total, res;
    register int i;

    cin >> n >> total;

    pre[0] = 0;
    for(i = 1; i <= n; ++i) {
        cin >> pre[i];
        pre[i] += pre[i-1];
    }

    res = 0;
    for(i = 1; i <= n; ++i) {
        res = max(bound(pre[i-1]+total) - i, res);
    }

    cout << res << '\n';

    return 0;
}
