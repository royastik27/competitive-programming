/**
* Codeforces Problem 20
* Codeforces Alpha Round #20 (Codeforces format)
* Problem C - Dijkstra?
* Time: 561 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define INF 100000000001

struct Vertex
{
    int node;
    long long int weight;
};

typedef struct Vertex Vertex;

// 1 based indexed

int main()
{
    int nVertices, nEdges, first, temp;
    Vertex second;

    cin >> nVertices >> nEdges;

    vector <Vertex> adj[nVertices + 1];
    long long int dist[nVertices + 1];
    int prev[nVertices + 1], curr, Size, i;

    while(nEdges--)
    {
        cin >> first >> second.node >> second.weight;

        adj[first].push_back(second);

        // swapping
        temp = first;
        first = second.node;
        second.node = temp;

        adj[first].push_back(second);
    }

    // shortest-path
    dist[1] = 0;
    prev[nVertices] = -1;

    for(i = 2; i <= nVertices; ++i)
        dist[i] = INF;

    priority_queue <int> que;

    que.push(1);

    while(!que.empty())
    {
        curr = que.top();
        Size = adj[curr].size();

        que.pop();

        for(i = 0; i < Size; ++i)
        {
            second = adj[curr][i];

            if(dist[curr] + second.weight < dist[second.node])
            {
                dist[second.node] = dist[curr] + second.weight;
                prev[second.node] = curr;
                que.push(second.node);
            }
        }
    }

    if(prev[nVertices] == -1)
        cout << -1 << '\n';
    else
    {
        stack <int> path;

        path.push(nVertices);

        while(path.top() != 1)
        {
            path.push(prev[path.top()]);
        }

        while(!path.empty())
        {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << '\n';
    }

    return 0;
}
