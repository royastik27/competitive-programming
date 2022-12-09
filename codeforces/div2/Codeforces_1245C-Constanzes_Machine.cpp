/**
 * Codeforces Round #597 (Div. 2)
 * Problem C - Constanze's Machine
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
 
using namespace std;

typedef long long int ll;

#define MOD 1000000007
 
class Solution
{
public:
    int solve()
    {
        string str;
        char ch;
        int len, i, u, n;
        ll ans = 1;

        cin >> str;
        len = str.length();

        // DP
        vector <int> dp(len+1);
        dp[0] = dp[1] = 1;
        for(i = 2; i <= len; ++i)
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        
        // Genenrating answer
        u = n = 0;
        for(i = 0; i < len; ++i)
        {
            ch = str[i];
            if(ch == 'w' || ch == 'm')
                return 0;

            // for 'u'
            if(ch == 'u')
                ++u;
            else if(u)
            {
                ans = ans * dp[u] % MOD;
                u = 0;
            }

            // for 'n'
            if(ch == 'n')
                ++n;
            else if(n)
            {
                ans = ans * dp[n] % MOD;
                n = 0;
            }
        }

        if(u > 1)   ans = ans * dp[u] % MOD;

        if(n > 1)   ans = ans * dp[n] % MOD;
 
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