/**
* Codeforces Round 271 (Div. 2)
* Problem D - Flowers
* TIME: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define LIM 100000
#define MOD 1000000007

class Solution
{
    vector <int> dp, p_sum;
public:
    void solve()
    {
        int t, k, i, left, right;

        cin >> t >> k;

        dp.resize(LIM+1, 1);
        p_sum.resize(LIM+1);

        for(i = 1; i < k; ++i)
            p_sum[i] = (p_sum[i-1] + dp[i]) % MOD;

        for(i = k; i <= LIM; ++i) {
            dp[i] = (dp[i-1] + dp[i-k]) % MOD;

            p_sum[i] = (p_sum[i-1] + dp[i]) % MOD;
        }

        while(t--) {
            cin >> left >> right;

            cout << ((p_sum[right] - p_sum[left-1] + MOD) % MOD) << '\n';
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