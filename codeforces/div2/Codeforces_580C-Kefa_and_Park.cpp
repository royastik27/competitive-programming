/**
 * Codeforces Round #321 (Div. 2)
 * Problem C - Kefa and Park
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
 
using namespace std;

#define LIM 200001

class Solution
{
    int n, m;
    bool cat[LIM], vis[LIM];
    vector <int> adj[LIM];

    int cnt(int node, int consec = 0)
    {
        vis[node] = true;

        if(cat[node]) ++consec;
        else consec = 0;

        // special case
        if(consec > m)
            return 0;

        int sz = adj[node].size(), ans = 0, curr, child = 0;

        for(int i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(!vis[curr])
            {
                ++child;
                ans += cnt(adj[node][i], consec);
            }
        }

        return child ? ans : 1;
    }
public:
    int solve()
    {
        int i, x, y;

        cin >> n >> m;

        for(i = 1; i <= n; ++i)
        {
            cin >> cat[i];
            vis[i] = false;
        }

        for(i = 1; i < n; ++i)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }        
        
        return cnt(1);
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