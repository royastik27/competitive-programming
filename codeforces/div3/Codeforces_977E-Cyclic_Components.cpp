/**
 * Codeforces Round #479 (Div. 3)
 * Problem E - Cyclic Components
 * TIME: 171 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 200001

class Solution
{
    int n, m, i, j, ans;
    bool vis[LIM];
    vector <int> adj[LIM];

    bool dfs(int node)
    {
        vis[node] = true;

        int i, sz = adj[node].size(), curr;

        // base case
        bool ans = (sz == 2);

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(!vis[curr])
                ans &= dfs(curr);
        }

        return ans;
    }
public:
    int solve()
    {
        cin >> n >> m;

        while(m--)
        {
            cin >> i >> j;
            
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        memset(vis, 0, n+1);

        ans = 0;
        for(i = 1; i <= n; ++i)
        {
            if(!vis[i])
                ans += dfs(i);
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