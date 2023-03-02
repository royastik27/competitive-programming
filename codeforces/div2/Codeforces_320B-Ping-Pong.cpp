/**
 * Codeforces Round #189 (Div. 2)
 * Problem B - Ping-Pong (Easy Version)
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 100

class Solution
{
    vector <int> adj[LIM];
    bool vis[LIM];
    int des;

    bool go(int node)
    {
        vis[node] = true;

        int i, sz = adj[node].size(), curr;
        bool ans = false;

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(curr == des) return true;

            if(!vis[curr])
                ans |= go(curr);
        }

        return ans;
    }
public:
    void solve()
    {
        int n, op, x, y, p, q, i, sz = 0;
        vector < pair <int, int> > vec;

        cin >> n;

        while(n--)
        {
            cin >> op >> x >> y;

            if(op == 1)
            {
                for(i = 0; i < sz; ++i)
                {
                    // i, sz
                    p = vec[i].first; q = vec[i].second;

                    if((x < p && p < y) || (y > q && q > x))
                        adj[i].push_back(sz);

                    if((x > p && x < q) || (y > p && y < q))
                        adj[sz].push_back(i);
                }

                vec.push_back({ x, y });
                ++sz;
            }
            else
            {
                memset(vis, 0, sizeof(vis));

                --x; --y;
                des = y;

                cout << (go(x) ? "YES\n" : "NO\n");
            }
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