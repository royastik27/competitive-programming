/**
 * Educational Codeforces Round 57 (Rated for Div. 2)
 * Problem B - Substring Removal
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 998244353

class Solution {

public:
    int solve()
    {
        int n, i, left, right, ans;
        string str;

        cin >> n >> str;

        left = right = 1;

        for(i = 1; i < n; ++i)
            if(str[i] == str[0]) ++left;
            else break;

        for(i = n-2; i >= 0; --i)
            if(str[i] == str[n-1]) ++right;
            else break;

        if(str[0] == str[n-1])
            ans = (ll)(left+1) * (right+1) % MOD;
        else ans = left + right + 1;

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
