/**
* 10th CPU CSE Programming Contest
* Problem A - Defeat The Thugs
* TIME: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 100001

class Solution
{
    vector <int> adj[LIM];
    int cost[LIM], inDeg[LIM], level[LIM-1];
    bool visited[LIM];

    void dfs(int node, int lev = 0)
    {
        visited[node] = true;
        // update level cost
        level[lev] = max(level[lev], cost[node]);

        int i, sz = adj[node].size(), adj_node;

        ++lev;
        for(i = 0; i < sz; ++i)
        {
            adj_node = adj[node][i];

            if(!visited[adj_node])
                dfs(adj_node, lev);
        }
        
        return;
    }
public:
    void solve()
    {
        int n, i, v, c;
        ll ans;

        cin >> n;

        memset(inDeg, 0, (n+1)*sizeof(int));

        for(i = 1; i <= n; ++i)
        {
            cin >> v >> c;

            if(v != -1)
            {
                adj[v].push_back(i);
                ++inDeg[i];
            }
            
            cost[i] = c;
        }

        memset(visited, 0, n+1);
        memset(level, 0, n * sizeof(int));

        for(i = 1; i <= n; ++i)
            if(!inDeg[i])
                dfs(i);

        ans = 0;
        for(i = 0; i < n; ++i)
            ans += level[i];

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