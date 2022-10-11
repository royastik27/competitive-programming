/**
 * Codeforces Round #806 (Div. 4)
 * Problem F - Yet Another Problem About Pairs Satisfying an Inequality
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200001

class Solution {
    long long int dp[LIM];
public:
    long long int solve()
    {
        long long int ans = 0;
        int n, i, el;

        cin >> n;

        dp[0] = 0;
        for(i = 1; i <= n; ++i)
        {
            cin >> el;

            dp[i] = dp[i-1];

            if(el < i)
                { if(el) ans += dp[el - 1]; ++dp[i]; }
        }
        
        return ans;
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