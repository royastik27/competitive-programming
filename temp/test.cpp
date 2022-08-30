/**
 * LightOJ 1238 - Power Puff Girls
 * TIME: 4 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 100001

class Solution {
    vector <int> adj[LIM], ans;
    bool change[LIM];

    void go(int node)
    {
        int i, sz = adj[node].size(), prop = 0, child;

        for(i = 0; i < sz; ++i)
        {
            child = adj[node][i];
            go(child);

            if(change[child]) prop 
        }


        return;
    }
public:
    void solve()
    {
        int n, i, deg[LIM], start;
        vector <bool> cn;

        cin >> n;
        memset(change, 0, n+1);
        memset(deg, 0, (n+1)*sizeof(int));

        start = 0;
        for(i = 1; i < n; ++i)
        {
            cin >> i >> j;
            adj[j].push_back(i);

            ++deg[i];
            if(!deg[i]) start= i;
        }

        for(i = 0; i < n; ++i)
        {
            cin >> i;
            cn.push_back(i);
        }

        for(i = 0; i < n; ++i)
        {
            cin >> i;
            if(i != cn[i]) change[i+1] = true;
        }

        go(start);

        int sz = ans.size();
        cout << sz << '\n';
        for(i = 0; i < sz; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        return;
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