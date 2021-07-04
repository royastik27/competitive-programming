/**
 * Codeforces Round #665 (Div. 2)
 * Problem B - Ternary Sequence
 * Time: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, x1, y1, z1, x2, y2, z2, temp, sum;

    cin >> TC;

    while(TC--) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // for 2-1 pairs
        temp = min(z1, y2);
        sum = 2 * temp;
        z1 -= temp;
        y2 -= temp;

        // for 2-2 pairs
        z2 -= min(z1, z2);

        // for 1-1 pairs
        y1 -= min(y1, y2);
        // for 1-0 pairs
        y1 -= min(y1, x2);
        // for 1-2 pairs
        sum -= 2 * min(y1, z2);

        cout << sum << '\n';
    }

    return 0;
}
