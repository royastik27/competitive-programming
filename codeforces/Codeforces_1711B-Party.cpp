/**
 * Codeforces Round #810 (Div. 2)
 * Problem B - Party
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

#define LIM 100001

class Solution {
    int unhappy[LIM], deg[LIM];
    vector <int> adj[LIM];
public:
    int solve()
    {
        int n, m, i, j, mn, sz, curr;

        cin >> n >> m;

        for(i = 1; i <= n; ++i) adj[i].clear();

        for(i = 1; i <= n; ++i) cin >> unhappy[i];
        
        memset(deg, 0, (n+1)*sizeof(int));

        for(curr = 0; curr < m; ++curr)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
            ++deg[i]; ++deg[j];
        }

        if(!(m & 1)) return 0;

        mn = INT_MAX;
        for(i = 1; i <= n; ++i)
        {
            if(deg[i] & 1)
                mn = min(mn, unhappy[i]);
            else
            {
                sz = adj[i].size();
                for(j = 0; j < sz; ++j)
                {
                    curr = adj[i][j];
                    if(!(deg[curr] & 1))
                        mn = min(mn, unhappy[i]+unhappy[curr]);
                }
            }
        }        

        return mn;
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
        cout << sol.solve() << '\n';

    return 0;
}