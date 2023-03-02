/**
 * Codeforces Round #468 (Div. 1, based on Technocup 2018 Final Round)
 * Problem A - Peculiar apple-tree
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 100000

class Solution
{
    vector <int> adj[LIM+1];
    int level[LIM];

    void dfs(int node = 1, int lev = 0)
    {
        int i, sz = adj[node].size();
        ++level[lev];

        ++lev;

        for(i = 0; i < sz; ++i)
            dfs(adj[node][i], lev);

        return;
    }
public:
    int solve()
    {
        int n, i, j, ans;

        cin >> n;

        for(i = 2; i <= n; ++i)
        {
            cin >> j;

            adj[j].push_back(i);
        }

        memset(level, 0, n*sizeof(int));
        dfs();

        ans = 0;
        for(i = 0; i < n; ++i)
            if(level[i] & 1)
                ++ans;

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    cout << sol.solve() << '\n';
 
    return 0;
}