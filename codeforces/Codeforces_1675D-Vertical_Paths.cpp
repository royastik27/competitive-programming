/**
 * Codeforces Round #787 (Div. 3)
 * Problem D - Vertical Paths
 * TIME: 124 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 200001

class Solution {
    vector < vector <int> > ans;
    vector <int> adj[LIM];

    void get_path(int node, int pos)
    {
        ans[pos].push_back(node);

        int sz = adj[node].size(), i;

        if(sz)
            get_path(adj[node][0], pos);
        for(i = 1; i < sz; ++i)
        {
            ans.push_back(vector <int> ());
            get_path(adj[node][i], ans.size() - 1);
        }        

        return;
    }
public:
    void solve()
    {
        int n, i, j, sz, sz2, root;

        // input
        cin >> n;
        for(i = 1; i <= n; ++i) adj[i].clear();

        for(i = 1; i <= n; ++i)
        {
            cin >> j;

            if(j == i)
                root = i;
            else
                adj[j].push_back(i);
        }

        // clearing container
        sz = ans.size();
        for(i = 0; i < sz; ++i)
            ans[i].clear();
        ans.clear();

        // getting result
        ans.push_back(vector <int>());
        get_path(root, 0);

        // printing ans
        sz = ans.size();
        cout << sz << '\n';

        for(i = 0; i < sz; ++i)
        {
            sz2 = ans[i].size();
            cout << sz2 << '\n';

            for(j = 0; j < sz2; ++j)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }

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
    {
        sol.solve();
        if(TC) cout << '\n';
    }

    return 0;
}