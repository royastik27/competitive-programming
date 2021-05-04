/**
* SPOJ RPLA - Answer the boss!
* Time: 0.15 sec
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

int main()
{
    int TC, nEmployees, nRelations, indegree[MAX], current, Size, visited, i, j, k;
    vector <int> adj[MAX];
    queue <int> que;

    cin >> TC;

    for(k = 1; k <= TC; ++k)
    {
        cin >> nEmployees >> nRelations;

        // initializing indegree array
        for(i = 0; i < nEmployees; ++i)
            indegree[i] = 0;

        // input relations
        while(nRelations--)
        {
            cin >> i >> j;
            adj[j].push_back(i);
            ++indegree[i];
        }

        cout << "Scenario #" << k << ":\n";
        visited = 0;
        // topological sort
        for(i = 1; i <= nEmployees; ++i)
        {
            if(visited == nEmployees)
                break;

            for(j = 0; j < nEmployees; ++j)
            {
                if(indegree[j] == 0)
                {
                    indegree[j] = -1;
                    ++visited;
                    que.push(j);
                }
            }

            while(!que.empty())
            {
                current = que.front();
                Size = adj[current].size();

                for(j = 0; j < Size; ++j)
                    --indegree[adj[current][j]];

                cout << i << ' ' << current << '\n';

                adj[current].clear();
                que.pop();
            }
        }
    }

    return 0;
}
