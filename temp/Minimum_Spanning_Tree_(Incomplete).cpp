/**
* Codeforces
* URL: https://codeforces.com/contest/160/problem/D
* Get Minimum Spanning Tree First
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

#define LIM 100001
#define INF 1000001

class cmp
{
  public:
  bool operator()(const pair <int, int> &a, const pair <int, int> &b) const
  {
    return a.second < b.second;
  }
};

// typedef struct
// {
//     int vertex;
//     set < pair<int, int>, cmp >::iterator dist;
// }Vertex;

vector <pair<int, int> > adj[LIM];

int MST(int nVertices)
{
    int mn, mnCost, selected, i, x, y;

    set < pair<int, int>, cmp > s;  // my min heap
    set < pair<int, int>, cmp >::iterator dist[nVertices + 1]; // dist[i].first->node | dist[i].second->cost

    // INITIALIZING FIRST NODE
    s.insert(make_pair(1, 0));
    dist[1] = s.begin();
    
    pair < set < pair<int, int>, cmp >::iterator, bool> check;
    // PROCESSING OTHER NODES
    for(i = 2; i <= nVertices; ++i)
    {
        check = s.insert(make_pair(i, INF));
        dist[i] = check.first;
    }

    mnCost = 0;
    selected = 1;

    int lastSelected = 1;
    pair <int, int> child;

    while(selected != nVertices)
    {
        // update costs of adjacent nodes of last selected one
        for(i = 0; i < adj[lastSelected].size(); ++i)
        {
            child = adj[lastSelected][i]; // child->first = node | child->second = weight

            if(dist[child->first].)
        }
    }

    return mnCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int nVertices, nEdges, i, u, v, cost;

    cin >> nVertices >> nEdges;

    for(i = 0; i < nEdges; ++i)
    {
        cin >> u >> v >> cost;

        adj[u].push_back(make_pair(v, cost));
        adj[v].push_back(make_pair(u, cost));
    }

    cout << MST(nVertices) << '\n';

    return 0;
}
