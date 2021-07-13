/**
 * Codeforces Round #453 (Div. 2)
 * Problem B - Coloring a Tree
 * Time: 249 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 10001

vector <int> adj[LIM];
int clr[LIM], curr[LIM];

void color(int node, int _clr)
{
    curr[node] = _clr;

    for(int i = 0; i < adj[node].size(); ++i)
        color(adj[node][i], _clr);
}

int dfs(int node = 1)
{
    int res = 0;

    if(curr[node] != clr[node]) {
        ++res;
        color(node, clr[node]);
    }

    for(int i = 0; i < adj[node].size(); ++i)
        res += dfs(adj[node][i]);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int nVertices, par;
    register int i;
    
    cin >> nVertices;

    // getting input
    for(i = 2; i <= nVertices; ++i) {
        cin >> par;
        adj[par].push_back(i);
    }
    for(i = 1; i <= nVertices; ++i)
        cin >> clr[i];

    memset(curr, 0, sizeof(clr));
    
    // call the function
    cout << dfs() << '\n';

    return 0;
}
