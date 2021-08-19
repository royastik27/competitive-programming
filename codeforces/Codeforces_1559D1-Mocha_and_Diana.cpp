/**
 * Codeforces Round #738 (Div. 2)
 * Problem D1 - Mocha and Diana (Easy Version)
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 1001

int par[2][1001];

int Find(int x, bool active)
{
    if(par[active][x] < 0) return x;

    return par[active][x] = Find(par[active][x], active);
}

void Union(int u, int v, bool active)
{
    int parU = Find(u, active), parV = Find(v, active);

    if(par[active][parU] < par[active][parV]) { // parU is weighter
        par[active][parU] += par[active][parV];
        par[active][parV] = parU;
    }
    else {
        par[active][parV] += par[active][parU];
        par[active][parU] = parV;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int nNodes, n1, n2, u, v, sz;
    bool mx;
    vector <int> conn;
    register int i, j;

    cin >> nNodes >> n1 >> n2;

    memset(par, -1, sizeof(par));

    mx = (n1 < n2); // ID of the maximum connected graph

    while(n1--) {
        cin >> u >> v;
        Union(u, v, 0);
    }
    while(n2--) {
        cin >> u >> v;
        Union(u, v, 1);
    }

    // getting parents of the maximum connected graph
    for(i = 1; i <= nNodes; ++i)
        if(par[mx][i] < 0) conn.push_back(i);

    sz = conn.size();
    cout << sz - 1 << '\n';

    for(i = 1; i < sz; ++i) {   // omitting first parent
        for(j = 1; j <= nNodes; ++j) {
            if(Find(conn[i], 0) != Find(j, 0) && Find(conn[i], 1) != Find(j, 1)) {
                Union(conn[i], j, 0);
                Union(conn[i], j, 1);
                cout << conn[i] << ' ' << j << '\n';
                break;
            }
        }
    }

    return 0;
}
