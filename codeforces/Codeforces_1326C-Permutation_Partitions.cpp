/**
 * Codeforces Global Round 7
 * Problem C - Permutation Partitions
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define MOD 998244353

class Solution {
    vector <pair <int, int> > vec;
public:
    void solve()
    {
        int n, k, i, ans = 1;
        ll sum = 0;

        cin >> n >> k;

        {
            int el;
            for(i = 0; i < n; ++i)
            {
                cin >> el;
                vec.push_back({el, i});
            }
        }

        sort(vec.begin(), vec.end(), greater<pair<int, int> >());

        vector <int> mxpos;
        for(i = 0; i < k; ++i)
        {
            sum += vec[i].first;
            mxpos.push_back(vec[i].second);
        }

        sort(mxpos.begin(), mxpos.end());

        {
            int sz = mxpos.size();

            --sz;
            for(i = 0; i < sz; ++i)
                ans = (ll)ans * (mxpos[i+1]-mxpos[i]) % MOD;
        }

        cout << sum << ' ' << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    sol.solve();

    return 0;
}
