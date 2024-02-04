/**
* Helvetic Coding Contest 2016 online mirror (teams, unrated)
* Problem C2 - Brain Network (medium)
* TIME: 77 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define LIM 100000

class Solution
{
    vector <int> adj[LIM+1];
    bool vis[LIM+1];
    int ans;

    int calc_latency(int node = 1)
    {
        vis[node] = true;

        int i, sz = adj[node].size(), child, mx1, mx2, c_depth;

        mx1 = mx2 = -1;

        for(i = 0; i < sz; ++i) {
            child = adj[node][i];

            if(!vis[child]) {
                c_depth = calc_latency(child);
                
                if(c_depth >= mx1) {
                    mx2 = mx1;
                    mx1 = c_depth;
                }
                else if(c_depth > mx2)
                    mx2 = c_depth;
            }
        }

        ans = max(ans, mx1+mx2+2);

        return mx1+1;
    }
public:
    void solve()
    {
        int n, m, i, u, v;

        cin >> n >> m;

        for(i = 0; i < m; ++i) {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = 0;
        memset(vis, 0, n+1);

        calc_latency();

        cout << ans << '\n';

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