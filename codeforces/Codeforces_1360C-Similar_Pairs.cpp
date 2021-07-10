/**
 * Codeforces Round #644 (Div. 3)
 * Problem C - Similar Pairs
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, el, neven, nodd;
    bool m[102], isabs1;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        memset(m, 0, sizeof(m));
        neven = nodd = isabs1 = 0;

        for(i = 0; i < n; ++i) {
            cin >> el;

            if(el & 1) ++nodd;
            else ++neven;

            if(m[el-1] || m[el+1]) isabs1 = true;

            m[el] = true;
        }

        if(!(neven & 1) || !(nodd & 1)) cout << "YES\n";
        else if(isabs1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
