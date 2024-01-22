/**
* VK Cup 2012 Round 1
* Problem D - Distance in Tree
* TIME: 310 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define LIM 50000
#define KLIM 500

class Solution
{
    int n, k, vis[LIM+1], halfK, dp[LIM+1][KLIM+1];
    ll ans;
    vector <int> adj[LIM + 1];

    void count_pairs(int node = 1)
    {
        vis[node] = true;

        int i, j, sz, child, cnt;
        vector <int> cntHalfK;
        
        memset(dp[node], 0, sizeof(dp[node]));
        dp[node][0] = 1;

        sz = adj[node].size();
        for(i = 0; i < sz; ++i) {
            child = adj[node][i];

            if(!vis[child]) {
                count_pairs(child);

                for(j = 1; j <= k; ++j) // till k-1
                    dp[node][j] += dp[child][j-1];

                // for halfK
                if(halfK) {
                    if(cnt = dp[child][halfK-1])
                        cntHalfK.push_back(cnt);
                }

                // making unvisited again
                vis[child] = false;
            }
        }

        // via only one child
        ans += dp[node][k];

        // via two child with less than halfK
        int lim = (k+1) / 2 - 1;
        for(i = 0; i < sz; ++i) {
            child = adj[node][i];

            if(!vis[child]) {
                for(j = 0; j < lim; ++j)
                    ans += dp[child][j] * (dp[node][k-1-j] - dp[child][k-2-j]);
            }
        }

        // via two child with halfK each
        if(halfK && (sz = cntHalfK.size()) > 1) {
            int sum = 0;
            
            for(i = sz - 1; i >= 0; --i)
                sum += cntHalfK[i];
            
            for(i = 0; i+1 < sz; ++i) {
                sum -= cntHalfK[i];
                ans += cntHalfK[i] * sum;
            }
        }
    }
public:
    void solve()
    {
        int i, u, v;

        cin >> n >> k;

        if(k & 1) halfK = 0;
        else halfK = k/2;

        for(i = 1; i < n; ++i) {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = 0;
        memset(vis, 0, sizeof(vis));
        count_pairs();

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