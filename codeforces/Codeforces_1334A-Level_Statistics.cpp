/**
 * Educational Codeforces Round 85 (Rated for Div. 2)
 * Problem A - Level Statistics
 * Time: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, p1, p2, c1, c2;
    bool isPossible;

    cin >> TC;

    while(TC--) {
        cin >> n;

        cin >> p1 >> c1;

        isPossible = (p1 >= c1);

        --n;
        while(n--) {
            cin >> p2 >> c2;

            if(p2 < p1 || c2 < c1 || (p2 - p1) < (c2 - c1))
                isPossible = false;

            p1 = p2;
            c1 = c2;
        }

        cout << (isPossible ? "YES" : "NO") << '\n';
    }

    return 0;
}
