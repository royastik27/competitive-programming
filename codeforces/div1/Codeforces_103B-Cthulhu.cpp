/**
 * Codeforces Beta Round #80 (Div. 1 Only)
 * Problem B - Cthulhu
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 101

class Solution
{
    vector <int> adj[LIM];
    bool vis[LIM];

    int check(int node, int parent = 0)
    {
        vis[node] = true;

        int i, sz = adj[node].size(), curr, ans = 0;

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(curr == parent) continue;

            if(vis[curr]) ++ans;
            else ans += check(curr, node);
        }

        return ans;
    }
public:
    bool solve()
    {
        int n, m, i, j;
        
        cin >> n >> m;

        memset(vis, 0, n+1);

        while(m--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        int res = check(1);

        for(i = 1; i <= n; ++i)
            if(!vis[i])
                return false;

        return res == 2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
      
    if(sol.solve()) cout << "FHTAGN!\n";
    else cout << "NO\n";
 
    return 0;
}