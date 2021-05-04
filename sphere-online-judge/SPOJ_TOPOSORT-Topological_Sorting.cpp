/**
* SPOJ TOPOSORT - Topological Sorting
* Time: 0.41 sec
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1 based indexed

int main()
{
    int nJobs, nRelations, current, Size, visited, i, j;
    priority_queue <int, vector <int>, greater <int> > pque;    // min heap

    cin >> nJobs >> nRelations;

    vector <int> adj[nJobs + 1], res;
    int indegree[nJobs + 1];

    // initializing in-degree array
    for(i = 1; i <= nJobs; ++i)
        indegree[i] = 0;

    // input relations
    while(nRelations--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
        ++indegree[j];
    }

    // topological sort
    for(i = 1; i <= nJobs; ++i)
    {
        if(indegree[i] == 0)
            pque.push(i);
    }

    visited = 0;
    while(!pque.empty())
    {
        current = pque.top();
        Size = adj[current].size();

        res.push_back(current);
        pque.pop();
        ++visited;

        for(i = 0; i < Size; ++i)
        {
            if(--indegree[adj[current][i]] == 0)
                pque.push(adj[current][i]);
        }
    }

    // printing result
    if(visited < nJobs)
        cout << "Sandro fails.";
    else
    {
        Size = res.size();
        for(i = 0; i < Size; ++i)
            cout << res[i] << ' ';
    }
    cout << endl;

    return 0;
}
