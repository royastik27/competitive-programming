/**
* UVA 10305 - Ordering Task
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define LIMIT 100

int main()
{
    int n, m, i, n1, n2, indegree[LIMIT+1], current;
    vector <int> adj[LIMIT+1];
    queue <int> res;

    while(1)
    {
        cin >> n >> m;

        if(!n) break;

        for(i = 1; i<=n; i++)
        {
            adj[i].clear();
            indegree[i] = 0;
        }

        for(i = 0; i<m; i++)
        {
            cin >> n1 >> n2;

            adj[n1].push_back(n2);
            ++indegree[n2];
        }

        for(i = 1; i<=n; i++)
        {
            if(indegree[i] == 0)
                res.push(i);
        }

        while(!res.empty())
        {
            for(i = 0; i < adj[res.front()].size(); i++)
            {
                current = adj[res.front()][i];

                if(--indegree[current] == 0)
                    res.push(current);
            }

            cout << res.front();
            if(res.size() == 1) cout << '\n';
            else cout << ' ';
            res.pop();
        }
    }

    return 0;
}
