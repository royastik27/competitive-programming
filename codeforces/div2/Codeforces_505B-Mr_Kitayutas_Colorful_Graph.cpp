/**
 * Codeforces Round #286 (Div. 2)
 * Problem B - Mr. Kitayuta's Colorful Graph
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 100

class Node
{
public:
    int next, color;
};

class Solution
{
    vector <Node> adj[LIM+1];
    bool vis[LIM+1], done[LIM+1];
    int u, v;

    bool dfs(int node, int color)
    {
        vis[node] = true;

        if(node == v)
            return true;

        int sz = adj[node].size(), curr;
        bool ans = false;

        for(int i = 0; i < sz; ++i)
        {
            curr = adj[node][i].next;

            if(!vis[curr] && adj[node][i].color == color)
                ans |= dfs(curr, color);
        }

        return ans;
    }
public:
    void solve()
    {
        int n, m, q, i, sz, ans, curr, color;
        Node obj;

        cin >> n >> m;

        for(i = 0; i < m; ++i)
        {
            cin >> u >> v >> obj.color;
            
            obj.next = v;
            adj[u].push_back(obj);

            obj.next = u;
            adj[v].push_back(obj);
        }

        cin >> q;

        while(q--)
        {
            cin >> u >> v;

            sz = adj[u].size();
            ans = 0;
            memset(done, 0, m+1);

            for(i = 0; i < sz; ++i)
            {
                curr = adj[u][i].next;
                color = adj[u][i].color;

                if(done[color]) continue; // one color for once
                
                memset(vis, 0, n+1);
                vis[u] = true;

                if(dfs(curr, color))
                {
                    ++ans;
                    done[color] = true;
                }
            }

            cout << ans << '\n';
        }

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