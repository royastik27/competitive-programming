/**
 * Codeforces Round #258 (Div. 2)
 * Problem B - Sort the Array
 * Time: 61 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100001

int main()
{
    ios_base::sync_with_stdio(0);

    int n, ara[LIM];
    register int i, s, e;

    cin >> n;

    for(i = 1; i <= n; ++i) cin >> ara[i];

    s = e = 1;

    for(i = 2; i <= n; ++i) {
        if(ara[i] < ara[i-1]) {

            if(s != e) { cout << "no\n"; return 0; }

            s = i - 1;

            for(e = i; e <= n && ara[e] <= ara[e-1]; ++e);
            --e;

            // swapping
            ara[s] = ara[s] + ara[e];
            ara[e] = ara[s] - ara[e];
            ara[s] = ara[s] - ara[e];

            if(ara[s] < ara[s-1]) { cout << "no\n"; return 0; }

            i = e;
        }
    }

    cout << "yes\n";
    cout << s << ' ' << e << '\n';

    return 0;
}
