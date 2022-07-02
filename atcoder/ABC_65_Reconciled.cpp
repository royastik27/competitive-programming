/**
 * AtCoder Beginner Contest 65
 * Problem C - Reconciled?
 * Time: 6 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MOD 1000000007

class Solution
{
    public:
    int solve()
    {
        int n, m, i;

        cin >> n >> m;

        int diff = abs(n - m);
        if(diff > 1) return 0;

        long long int ans = 1;

        for(i = 2; i <= n; ++i) ans = ans * i % MOD;

        for(i = 2; i <= m; ++i) ans = ans * i % MOD;

        if(!diff) ans = ans * 2 % MOD;

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution sol;

    cout << sol.solve() << '\n';
    
    return 0;
}