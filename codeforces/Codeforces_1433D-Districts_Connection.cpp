/**
 * Codeforces Round #677 (Div. 3)
 * Problem D - Districts Connection
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 5001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, first, pos, ara[LIM];
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        cin >> first;

        pos = 0;
        for(i = 2; i <= n; ++i) {
            cin >> ara[i];
            if(ara[i] != first) pos = i;
        }

        if(!pos) cout << "NO\n";
        else {
            cout << "YES\n" << 1 << ' ' << pos << '\n';

            for(i = 2; i <= n; ++i) {
                if(i == pos) continue;

                if(ara[i] == first) cout << pos;
                else cout << 1;

                cout << ' ' << i << '\n';
            }
        }
    }

    return 0;
}
