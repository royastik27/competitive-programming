/**
* 8VC Venture Cup 2017 - Elimination Round
* Problem C - PolandBall and Forest
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 10001

int parent[LIM];

int Find(int x)
{
    if(parent[x] < 0)
        return x;

    return Find(parent[x]);
}

void Union(int x, int y)
{
    int parentX = Find(x), parentY = Find(y);

    if(parentX == parentY) return;

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
    int nBalls, par, res;
    register int i;

    cin >> nBalls;

    memset(parent, -1, (nBalls+1) * sizeof(int));

    for(i = 1; i <= nBalls; ++i) {
        cin >> par;
        Union(par, i);
    }

    res = 0;
    for(i = 1; i <= nBalls; ++i) {
        if(parent[i] < 0) ++res;
    }

    cout << res << '\n';

    return 0;
}
