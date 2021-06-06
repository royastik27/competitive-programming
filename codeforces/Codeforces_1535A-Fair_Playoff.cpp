/**
* Educational Codeforces Round 110 (Rated for Div. 2)
* Problem A - Fair Playoff
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, a, b, c, d;

    cin >> TC;

    while(TC--) {
        cin >> a >> b >> c >> d;

        if(max(a, b) < min(c, d) || min(a, b) > max(c, d))
            cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
