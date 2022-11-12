/**
 * Codeforces Round #728 (Div. 1)
 * Problem A - Great Graphs
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

#define LIM 1001
#define INF 

class Solution {

public:
    int solve()
    {
        int n, m, i, j, ans = 0, energy[LIM], mn, mn_pos, cnt, neigh;
        bool adj[LIM][LIM];
        memset(adj, 0, sizeof(adj));

        cin >> n >> m;
        for(i = 1; i <= n; ++i) cin >> energy[i];

        vector <int> cost(n+1, 0);

        while(m--)
        {
            cin >> i >> j;
            adj[i][j] = adj[j][i] = true;
            cost[i] += energy[j];
            cost[j] += energy[i];
        }

        cout << "Cost:\n";
        for(i = 1; i <= n; ++i)
            cout << cost[i] << ' ';
        cout << '\n';

        cnt = 0;

        while(cnt < n)
        {
            mn = INT_MAX;

            for(i = 1; i <= n; ++i)
            {
                // find the minimum cost from non-visited ones
                if(cost[i] != -1 && cost[i] < mn)
                {
                    mn = cost[i];
                    mn_pos = i;
                }
            }

            cout << "Found Min: " << mn_pos << '\n';

            // code here
            for(i = 1; i <= n; ++i)
            {
                if(adj[mn_pos][i])
                {
                    cost[i] -= energy[mn_pos];
                    adj[i][mn_pos] = false;
                }
            }

             cout << "Cost:\n";
        for(i = 1; i <= n; ++i)
            cout << cost[i] << ' ';
        cout << '\n';
            
            ++cnt;
            ans += mn;
            cost[mn_pos] = -1;

            cout << "ans: " << ans << '\n';
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