/**
 * Educational Codeforces Round 33 (Rated for Div. 2)
 * Problem C - Rumor
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 100001

class Solution {
    vector <int> adj[LIM];
    int cost[LIM];
    bool visited[LIM];

    ll go(int node)
    {
        visited[node] = true;
        ll mn = cost[node];

        int sz = adj[node].size();

        for(int i = 0; i < sz; ++i)
            if(!visited[adj[node][i]])
                mn = min(mn, go(adj[node][i]));

        return mn;
    }
public:
    ll solve()
    {
        int n, m, el, i;

        cin >> n >> m;
        for(i = 1; i <= n; ++i) cin >> cost[i];

        while(m--)
        {
            cin >> i >> el;
            adj[i].push_back(el);
            adj[el].push_back(i);
        }

        ll total = 0;
        memset(visited, 0, n+1);

        for(i = 1; i <= n; ++i)
        {
            if(!visited[i])
                total += go(i);
        }
        
        return total;
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