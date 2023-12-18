/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 1000
#define MOD 998244353

class Solution
{
    int fact[LIM+1];
public:
    Solution()
    {
        fact[0] = 1;

        for(int i = 1; i <= LIM; ++i) {
            fact[i] = (ll)fact[i-1] * i % MOD;
        }
    }
    void solve()
    {
        int n, num, mx1, mx2, diff, i, ans, cnt;

        cin >> n >> num;

        mx1 = mx2 = num;
        cnt = 1;

        for(i = 1; i < n; ++i) {
            cin >> num;

            if(num >= mx1) {
                mx2 = mx1;
                mx1 = num;
                cnt = 1;
            }
            else if(num == mx2)
                ++cnt;
        }

        diff = mx1 - mx2;

        if(diff >= 2)
            ans = 0;
        else if(!diff)
            ans = fact[n];
        else { // mx1 - mx2 = 1
            ans = fact[n];

            for(i = cnt+1; i <= n; ++i) {
                cout << "(" << i << "-1)! and " << "(" << n << "-" << i << ")!\n";
                ans -= (ll)fact[i-1] * fact[n-i] % MOD;

                ans %= MOD;
            }

            ans = (ans+MOD) % MOD;
        }

        cout << ans << '\n';

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