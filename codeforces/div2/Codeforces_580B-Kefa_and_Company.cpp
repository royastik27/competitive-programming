/**
 * Codeforces Round #321 (Div. 2)
 * Problem B - Kefa and Company
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    ll solve()
    {
        int n, d, coin, factor, i, j;
        ll ans = -1;
        vector < pair <int, int> > frnd;
        vector <ll> pre;

        cin >> n >> d;

        for(i = 0; i < n; ++i)
        {
            cin >> coin >> factor;
            frnd.push_back({ coin, factor });
        }

        sort(frnd.begin(), frnd.end());

        pre.push_back(frnd[0].second); // coin
        for(i = 1; i < n; ++i)
            pre.push_back(frnd[i].second + pre[i-1]);

        // DP
        for(i = 0, j = 0; j < n; ++j)
        {
            while(frnd[j].first - frnd[i].first >= d)
                ++i;

            ans = max(ans, (i == 0) ? pre[j] : pre[j]-pre[i-1]);
        }

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