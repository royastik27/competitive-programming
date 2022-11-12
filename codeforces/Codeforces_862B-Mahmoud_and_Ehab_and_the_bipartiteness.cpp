/**
 * Codeforces Round #435 (Div. 2)
 * Problem B - Mahmoud and Ehab and the bipartiteness
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

#define LIM 100001

#define WHITE 1
#define BLACK 2

class Solution {
    vector <int> adj[LIM];
    int color[LIM] = {}, white = 0;

    void make_color(int node, int parColor)
    {
        int currColor = (parColor == WHITE) ? BLACK : WHITE;
        int i, sz = adj[node].size(), curr;

        color[node] = currColor;
        
        if(currColor == WHITE) // if black parent
            ++white;

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(color[curr]) continue;
            make_color(curr, currColor);
        }

        return;
    }
public:
    ll solve()
    {
        int n, i, j, k, deg[LIM] = {};
        ll ans = 0;

        cin >> n;

        for(k = 1; k < n; ++k)
        {
            cin >> i >> j;

            adj[i].push_back(j);
            adj[j].push_back(i);

            ++deg[i]; ++deg[j];
        }

        make_color(1, BLACK);

        for(i = 1; i <= n; ++i)
            if(color[i] == BLACK) // black nodes
                ans += white - deg[i];

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