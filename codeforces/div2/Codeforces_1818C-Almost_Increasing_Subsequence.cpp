/**
* Codeforces Round 869 (Div. 2)
* Problem C - Almost Increasing Subsequence
* A totally different solution
* TIME: 218 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200001

class Solution
{
    int dp[LIM];
public:
    Solution()  { dp[0] = 0; }
    void solve()
    {
        int n, q, i, prev, num, nonInc, ans, left, right;

        cin >> n >> q;

        prev = nonInc = 0;

        for(i = 1; i <= n; ++i)
        {
            cin >> num;

            if(num <= prev)
                ++nonInc;
            else
                nonInc = 0;

            if(nonInc > 1)
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-1] + 1;

            prev = num;
        }

        while(q--)
        {
            cin >> left >> right;

            ans = dp[right] - dp[left-1];

            if(right == left)
                ans = 1;
            else if(dp[left] == dp[left-1] && dp[left] == dp[left+1])
                ans += 2;
            else if(dp[left] == dp[left-1] || dp[left] == dp[left+1])
                ++ans;

            cout << ans << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}