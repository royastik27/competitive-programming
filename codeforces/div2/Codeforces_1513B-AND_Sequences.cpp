/**
 * Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
 * Problem B - AND Sequences
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200000
#define MOD 1000000007

class Solution
{
    int n, i, AND, arr[LIM], cnt;

    int nPr(int n, int r)
    {
        int lim = n-r;
        ll res = 1;

        for(int i = n; i > lim; --i)
            res = res * i % MOD;

        return int(res);
    }

    int fact(int n)
    {
        ll res = 1;

        for(int i = 2; i <= n; ++i)
            res = res * i % MOD;

        return int(res);
    }
public:
    int solve()
    {
        cin >> n;

        cin >> arr[0];
        AND = arr[0];

        for(i = 1; i < n; ++i)
        {
            cin >> arr[i];

            AND &= arr[i];
        }

        cnt = 0;
        for(i = 0; i < n; ++i)
            if(arr[i] == AND) ++cnt;

        if(cnt < 2) return 0;

        return int(ll(nPr(cnt, 2)) * fact(n-2) % MOD);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        cout << sol.solve() << '\n';
 
    return 0;
}