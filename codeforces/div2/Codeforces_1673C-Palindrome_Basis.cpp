/**
* Codeforces Round 785 (Div. 2)
* Problem C - Palindrome Basis
* TIME: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

#define LIM 40000
#define MOD 1000000007

class Solution
{
    int n;
    vector <int> pal_num, dp;

    bool pal(int n)
    {
        vector <int> dig;

        while(n) {
            dig.push_back(n % 10);
            n /= 10;
        }

        int i, j, sz = dig.size();

        for(i = 0, j = sz-1; i < j; ++i, --j) {
            if(dig[i] != dig[j])
                return false;
        }

        return true;
    }
public:
    Solution()
    {
        int i, j, sz;

        // preparing pal_num
        for(i = 1; i <= LIM; ++i) {
            if(pal(i))
                pal_num.push_back(i);
        }

        // dp
        dp.resize(LIM+1);
        dp[0] = 1;

        sz = pal_num.size();

        for(i = 0; i < sz; ++i) {
            for(j = pal_num[i]; j <= LIM; ++j) {
                dp[j] = (ll(dp[j]) + dp[j - pal_num[i]]) % MOD;
            }
        }

        return;
    }
    void solve()
    {
        cin >> n;

        cout << dp[n] << '\n';

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