/**
* Educational Codeforces Round 11
* Problem B - Seating On Bus
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, i, a;

    cin >> n >> m;

    a = 2*n;

    for(i = 1; i <= a; ++i) {
        a += i;

        if(a <= m) cout << a << ' ';

        if(i <= m) cout << i << ' ';

        a -= i;
    }
    cout << '\n';

    return 0;
}
