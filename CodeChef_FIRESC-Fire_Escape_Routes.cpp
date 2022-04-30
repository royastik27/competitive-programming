/**
* CodeChef FIRESC - Fire Escape Routes
* Time: 0.07 sec
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100001

int parent[LIM];

int getParent(int x)
{
    if(parent[x] < 0) return x;

    return getParent(parent[x]);
}

void join(int u, int v)
{
    int parU = getParent(u);
    int parV = getParent(v);

    if(parU < parV) // parent of U is greater
    {
        parent[parU] += parent[parV];
        parent[parV] = parU;
    }
    else if(parU > parV) // as equal cases are ignored
    {
        parent[parV] += parent[parU];
        parent[parU] = parV;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, friendships, u, v, routes, captains, i;

    cin >> TC;

    while(TC--)
    {
        cin >> n >> friendships;

        memset(parent, -1, (n+1)*sizeof(int));

        while(friendships--)
        {
            cin >> u >> v;

            join(u, v);
        }

        routes = 0;
        captains = 1;
        for(i = 1; i <= n; ++i)
        {
            if(parent[i] < 0)
            {
                ++routes;

                captains = (long long int)captains * (0 - parent[i]) % 1000000007;
            }
        }

        cout << routes << ' ' << captains << '\n';
    }

    return 0;
}
