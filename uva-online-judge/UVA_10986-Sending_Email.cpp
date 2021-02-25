/**
* UVA 10986 - Sending Email
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define LIMIT 20000
#define INT_MAX 2147483647

vector <pair <int, int>> adj[LIMIT];

int bfs(int no_server, int n1, int n2)
{
    int discovery_time[no_server], i, j, current, time;
    pair <int, int> temp;

    for(i = 0; i<no_server; ++i)
        discovery_time[i] = INT_MAX;

    discovery_time[n1] = 0;

    queue <int> q;
    q.push(n1);

    while(!q.empty())
    {
        current = q.front();

        for(i = 0; i<adj[current].size(); ++i)
        {
            temp = adj[current][i];

            time = discovery_time[current] + temp.second;

            if(time < discovery_time[temp.first])
            {
                discovery_time[temp.first] = time;
                q.push(temp.first);
            }
        }
        q.pop();
    }

    return discovery_time[n2];
}

int main()
{
    int test, no_server, no_cable, n1, n2, i, j, t, w, res;

    cin >> test;

    for(int k = 1; k<=test; ++k)
    {
        cin >> no_server >> no_cable >> n1 >> n2;

        //best case
        if(no_cable == 0)
        {
            cout << "Case #" << k << ": unreachable\n";
            continue;
        }

        //clearing the vector
        for(i = 0; i<no_server; ++i)
            adj[i].clear();

        //adding connection
        for(i = 0; i<no_cable; ++i)
        {
            cin >> j >> t >> w;

            adj[j].push_back(make_pair(t, w));
            adj[t].push_back(make_pair(j, w));
        }

        cout << "Case #" << k << ": ";
        res = bfs(no_server, n1, n2);

        if(res == INT_MAX)
            cout << "unreachable\n";
        else
            cout << res << '\n';
    }

    return 0;
}
