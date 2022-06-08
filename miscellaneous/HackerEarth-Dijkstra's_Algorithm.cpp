/**
* HackerEarth - Dijkstra's Algorithm
* Time: 11 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

#define INF 100001

int adj[9][9], Distance[9];

int shortestPath(int u, int v, int nVertices)
{
    int i, current;
    queue <int> que;

    // initializing
    for(i = 0; i < nVertices; ++i)
        Distance[i] = INF;
    Distance[u] = 0;

    que.push(u);

    while(!que.empty())
    {
        current = que.front();

        que.pop();

        for(i = 0; i < nVertices; ++i)
        {
            if(adj[current][i] > 0) // then connected
            {
                if(Distance[current] + adj[current][i] < Distance[i])
                {
                    Distance[i] = Distance[current] + adj[current][i];
                    que.push(i);
                }
            }
        }
    }

    return Distance[v];
}

int main()
{
    int nVertices, nQueries, i, j;

    cin >> nVertices;

    // getting input
    for(i = 0; i < nVertices; ++i)
    {
        for(j = 0; j < nVertices; ++j)
            cin >> adj[i][j];
    }

    cin >> nQueries;

    while(nQueries--)
    {
        cin >> i >> j;

        // swapping
        if(i > j)
        {
            i = i + j;
            j = i - j;
            i = i - j;
        }

        // shortest path between i and j
        cout << shortestPath(i, j, nVertices) << '\n';
    }

    return 0;
}
