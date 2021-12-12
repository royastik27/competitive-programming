/**
 * Codeforces Round #756 (Div. 3)
 * Problem D - Weights Assignment For Tree Edges
 * Time: 124 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 200001

vector <int> adj[LIM];
int weight[LIM], res[LIM], root;

void dfs(int x)
{
    int i, sz, diff;

    sz = adj[x].size();
    for(i = 0; i < sz; ++i) {
        diff = weight[adj[x][i]] - weight[x];

        if(diff <= 0) {
            res[root] = -1;
            continue;
        }

        res[adj[x][i]] = diff;
        dfs(adj[x][i]);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, x;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        // getting the tree
        for(i = 1; i <= n; ++i) {
            cin >> x;
            if(x == i) {root = x; continue;}
            adj[x].push_back(i);
        }

        // assigning weights choronologically
        for(i = 0; i < n; ++i) {
            cin >> x;
            weight[x] = i;
        }

        res[root] = 0;

        // printing the result
        dfs(root);
        if(res[root] == -1) cout << -1;
        else for(i = 1; i <= n; ++i) cout << res[i] << ' ';
        cout << '\n';

        for(i = 1; i <= n; ++i) adj[i].clear();
    }

    return 0;
}
