/**
* SPOJ SOCNETC - Social Network Community
* Time: 0.06 sec
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 100001

int parent[LIMIT], high;

int Find(int x)
{
    if(parent[x] < 0)
        return x;

    return Find(parent[x]);
}

void Union(int x, int y)
{
    int parentX, parentY, weight;

    parentX = Find(x);
    parentY = Find(y);

    // not creating friends when the community size is greater
    weight = parent[parentX] + parent[parentY];
    if((0 - weight) > high)
        return;

    if(parent[parentX] < parent[parentY])
    {
        parent[parentX] += parent[parentY];
        parent[parentY] = parentX;
    }
    else
    {
        parent[parentY] += parent[parentX];
        parent[parentX] = parentY;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int nUsers, nQueries, x, y;
    char op;

    memset(parent, -1, sizeof(parent));

    cin >> nUsers >> high >> nQueries;

    while(nQueries--)
    {
        cin >> op >> x;

        switch(op)
        {
        case 'A':
            cin >> y;
            Union(x, y);
            break;
        case 'E':
            cin >> y;
            if(Find(x) == Find(y))
                cout << "Yes\n";
            else cout << "No\n";
            break;
        case 'S':
            cout << (0 - parent[Find(x)]) << '\n';
            break;
        }
    }

    return 0;
}
