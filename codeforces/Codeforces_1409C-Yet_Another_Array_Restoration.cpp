/**
 * Codeforces Round #667 (Div. 3)
 * Problem C - Yet Another Array Restoration
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define INF 2354

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, x, y, mx, temp_mx, diff, left, a, side, gap, i;

    cin >> TC;

    while(TC--) {
        cin >> n >> x >> y;

        mx = INF;
        diff = y - x;

        for(i = n - 1; i >= 1; --i) {
            if(diff % i == 0) {
                a = diff / i;

                side = n - i - 1;

                left = (x - 1) / a;
                if(side < left) left = side;

                temp_mx = y + (n - i - 1 - left) * a; 

                if(temp_mx < mx) {
                    mx = temp_mx;
                    gap = a;
                }
            }
        }

        for(i = 0; i < n; ++i) {
            cout << mx << ' ';
            mx -= gap;
        }
        cout << '\n';
    }

    return 0;
}
