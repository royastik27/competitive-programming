/**
 * Codeforces Round #240 (Div. 2)
 * Problem D - Mashmokh and ACM
 * TIME: 373 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define LIM 2001
#define MOD 1000000007

class Solution
{
    int dp[LIM][LIM];
public:
    int solve()
    {
        int n, k, root, i, j, d, ans = 0;

        cin >> n >> k;

        for(j = 1; j <= k; ++j)
            dp[1][j] = 1;

        for(i = 2; i <= n; ++i)
        {
            dp[i][1] = 1;

            for(j = 2; j <= k; ++j)
            {
                root = int(ceil(sqrt(i)));
                dp[i][j] = 0;

                for(d = 1; d < root; ++d)
                {
                    if(i % d == 0)
                        dp[i][j] = (dp[i][j] +  (dp[d][j-1] + dp[i/d][j-1]) % MOD) % MOD;
                }

                if(d*d == i)
                    dp[i][j] = (dp[i][j] + dp[d][j-1]) % MOD;
            }
        }

        for(i = 1; i <= n; ++i)
            ans = (ans + dp[i][k]) % MOD;

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';

    return 0;
}