/**
 * Codeforces Round #181 (Div. 2)
 * Problem B - Coach
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <array>

using namespace std;

#define LIM 49

class Solution
{
    vector <int> adj[LIM], nodes;
    bool vis[LIM];

    void dfs(int node)
    {
        nodes.push_back(node);
        vis[node] = true;

        int i, sz = adj[node].size(), curr;

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(!vis[curr])
                dfs(curr);
        }
        
        return;
    }
public:
    void solve()
    {
        int n, m, i, j, sz;

        cin >> n >> m;

        vector <int> deg(n+1, 0), deg0;
        vector < array<int, 3> > ans;

        while(m--)
        {
            cin >> i >> j;

            adj[i].push_back(j);
            adj[j].push_back(i);

            ++deg[i]; ++deg[j];
        }

        for(i = 1; i <= n; ++i)
            if(!deg[i])
                deg0.push_back(i);

        memset(vis, 0, n+1);

        // dfs with deg > 1
        for(i = 1; i <= n; ++i)
        {
            if(deg[i] && !vis[i])
            {
                dfs(i);

                sz = nodes.size();

                if(sz > 3)
                {
                    cout << "-1\n";
                    return;
                }
                
                // possible sizes are 2 and 3
                if(sz == 2)
                {
                    if(deg0.empty()) { cout << "-1\n"; return; }

                    ans.push_back({ nodes[0], nodes[1], deg0[0] });

                    deg0.erase(deg0.begin());
                }
                else ans.push_back({ nodes[0], nodes[1], nodes[2] });

                nodes.clear();
            }
        }

        // printing answers
        sz = ans.size();

        for(i = 0; i < sz; ++i)
            cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';

        // remaining answers
        sz = deg0.size();
        for(i = 0; i < sz; i += 3)
            cout << deg0[i] << ' ' << deg0[i+1] << ' ' << deg0[i+2] << '\n';
        
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