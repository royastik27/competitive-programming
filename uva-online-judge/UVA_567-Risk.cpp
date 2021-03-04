/**
* UVA 567 - Risk
* Time: 130 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 20

vector <int> adj[21];
int destination[21];

int get_dest(int src, int dest)
{
    int i, curr, node, size;
    for(i = 1; i <= 20; ++i)
        destination[i] = INF;

    queue <int> que;

    que.push(src);
    destination[src] = 0;

    while(!que.empty())
    {
        curr = que.front();

        if(curr == dest)
            return destination[curr];

        que.pop();

        size = adj[curr].size();
        for(i = 0; i < size; ++i){
            node = adj[curr][i];

            if(destination[node] == INF){
                destination[node] = destination[curr] + 1;
                que.push(node);
            }
        }
    }

    return destination[curr];
}

int main()
{
    int TC = 0, num, node, nQuery, src, dest, i;

    while(cin >> num)
    {
        if(TC){
            for(i = 1; i <= 20; ++i)
                adj[i].clear();
        }

        while(num--){
            cin >> node;
            adj[1].push_back(node);
            adj[node].push_back(1);
        }

        for(i = 2; i < 20; ++i){
            cin >> num;
            while(num--){
                cin >> node;
                adj[i].push_back(node);
                adj[node].push_back(i);
            }
        }

        cin >> nQuery;

        cout << "Test Set #" << ++TC << '\n';

        while(nQuery--)
        {
            cin >> src >> dest;

            if(src < 10) cout << ' ';
            cout << src << " to ";
            if(dest < 10) cout << ' ';

            cout << dest << ": " << get_dest(src, dest) << '\n';
        }
        cout << '\n';
    }

    return 0;
}
