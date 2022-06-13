/**
* Codeforces
* URL: https://codeforces.com/contest/160/problem/D
* Get Minimum Spanning Tree First
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>
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

vector <pair<int, int> > adj[LIM];

int MST(int nVertices)
{
    int mn, mnCost, nSelected, i, x, y;

    multiset < pair<int, int>, cmp > s;  // my min heap // first -> node | second->cost
    multiset < pair<int, int> >::iterator dist[nVertices + 1], selected; // dist[i].first->node | dist[i].second->cost

    // INITIALIZING FIRST NODE
    s.insert(make_pair(1, 0));
    dist[1] = s.begin();
    
    multiset < pair<int, int> >::iterator check;
    // PROCESSING OTHER NODES
    for(i = 2; i <= nVertices; ++i)
    {
        check = s.insert(make_pair(i, INF));
        dist[i] = check;
    }

    cout << "\nOur heap is ready\n";
    for(auto it = s.begin(); it != s.end(); ++it)
        cout << it->first << ' ' << it->second << '\n';

    cout << "Set Size: " << s.size() << '\n';

    mnCost = 0;
    nSelected = 1;

    int lastSelected = 1;
    pair <int, int> child;

    bool visited[nVertices + 1];
    visited[1] = true;

    cout << "\nMAIN OPERATION:\n";
    while(nSelected != nVertices)   // check for cycle
    {
        // update costs of adjacent nodes of last selected one
        for(i = 0; i < adj[lastSelected].size(); ++i)
        {
            child = adj[lastSelected][i]; // child->first = node | child->second = weight

            if(!visited[child.first] && dist[child.first]->second > child.second)
            {
                cout << "cost of " << child.first << " became " << child.second << '\n';
                s.erase(dist[child.first]);
                dist[child.first] = s.insert(make_pair(child.first, child.second));
            }

            selected = s.begin();

            mnCost += selected->second;
            lastSelected = selected->first;
            s.erase(selected);

            visited[lastSelected] = true;

            ++nSelected;
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

    cout << "INPUT DONE\n";

    cout << MST(nVertices) << '\n';

    return 0;
}
