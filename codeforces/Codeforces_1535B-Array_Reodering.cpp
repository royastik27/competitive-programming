/**
* Educational Codeforces Round 110 (Rated for Div. 2)
* Problem B - Array Reodering
* Time: 374 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;

    return GCD(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, ara[2000], res;
    register int i, j;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> ara[i];

        res = 0;
        for(i = 0; i < n-1; ++i) {
            for(j = i+1; j < n; ++j) {
                if(GCD(ara[i], 2*ara[j]) > 1 || GCD(ara[j], 2*ara[i]) > 1)
                    ++res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
