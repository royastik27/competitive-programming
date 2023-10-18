/**
* Codeforces Round 903 (Div. 3)
* Problem E - Block Sequence
* TIME: 61 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200000

class Solution
{
    int dp[LIM + 1], a[LIM];
public:
    void solve()
    {
        int n, i;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[i];

        dp[n] = 0;
        for(i = n-1; i >= 0; --i)
        {
            if(i + a[i] > n-1)
                dp[i] = 1 + dp[i+1];
            else
                dp[i] = min(1 + dp[i+1], dp[i+a[i]+1]);
        }

        cout << dp[0] << '\n';

        return;
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
        sol.solve();

    return 0;
}