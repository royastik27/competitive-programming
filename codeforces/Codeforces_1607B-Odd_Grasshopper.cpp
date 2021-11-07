/**
 * Codeforces Round #753 (Div. 3)
 * Problem B - Odd Grasshopper
 * Time: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, rem;
    long long int x0, n, i;

    cin >> TC;

    while(TC--) {
        cin >> x0 >> n;

        rem = n % 4;

        for(i = n - rem + 1; i <= n; ++i) {
            if(x0 & 1) x0 += i;
            else x0 -= i;
        }

        cout << x0 << '\n';
    }

    return 0;
}
