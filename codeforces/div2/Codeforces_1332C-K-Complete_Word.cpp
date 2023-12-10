/**
* Codeforces Round 630 (Div. 2)
* Problem C - K-Complete Word
* TIME: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

#define LIM 200000

class Solution
{
    int n, freq[26];
    bool vis[LIM];
    string str;
    vector <int> adj[LIM];

    inline int pal_pair(int idx)
    {
        return (n-1 - idx);
    }

    void connect(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node)
    {
        vis[node] = true;
        
        ++freq[str[node]-'a'];

        int i, sz = adj[node].size(), adj_node;

        for(i = 0; i < sz; ++i)
        {
            adj_node = adj[node][i];

            if(!vis[adj_node]) dfs(adj_node);
        }
        
        return;
    }
public:
    void solve()
    {
        int k, i, j, lim, ans, total, mx;

        cin >> n >> k >> str;
        
        // connecting periods
        lim = min(k, n-k);
        
        for(i = 0; i < lim; ++i)
            for(j = i+k; j < n; j += k)
                connect(i, j);

        // connecting palindromic pairs
        lim = n / 2;
        for(i = 0; i < lim; ++i)
            connect(i, pal_pair(i));

        // generating answer
        memset(vis, 0, n);

        ans = 0;
        for(i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                dfs(i);

                total = mx = 0;
                for(j = 0; j < 26; ++j)
                {
                    total += freq[j];
                    mx = max(mx, freq[j]);
                }

                ans += total - mx;

                memset(freq, 0, sizeof(freq));
            }
        }

        cout << ans << '\n';

        for(i = 0; i < n; ++i)
            adj[i].clear();

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}