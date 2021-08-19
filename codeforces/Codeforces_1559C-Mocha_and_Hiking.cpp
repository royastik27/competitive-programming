/**
 * Codeforces Round #738 (Div. 2)
 * Problem C - Mocha and Hiking
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, curr, prev, bp;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        cin >> prev;

        bp = (prev == 1) ? 0 : -1; // check when n = 1

        for(i = 1; i < n; ++i) {
            cin >> curr;

            if(prev == 0 && curr == 1) bp = i;

            prev = curr;
        }

        if(prev == 0) bp = n;
        
        // printing the result
        for(i = 1; i <= bp; ++i) cout << i << ' ';
        cout << n+1 << ' ';
        for(i = bp+1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
