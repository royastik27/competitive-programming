  
/**
* LightOJ 1019 - Brush (V)
* Time: 19 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1000000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, k = 0, n, m, u, v, w, dist[101], i, adj[101][101], curr;
    queue <int> que;

    cin >> TC;

    while(TC--) {

        cin >> n >> m;

        // initializing
        for(i = 1; i <= n; ++i)
            dist[i] = INF;

        memset(adj, -1, sizeof(adj));

        // getting input
        for(i = 0; i < m; ++i) {
            cin >> u >> v >> w;

            if(adj[u][v] == -1 || w < adj[u][v])
                adj[u][v] = adj[v][u] = w;
        }

        // finding the shortest path
        que.push(1);
        dist[1] = 0;

        while(!que.empty()) {
            curr = que.front();

            for(i = 1; i <= n; ++i) {
                if(adj[curr][i] != -1 && dist[i] > dist[curr] + adj[curr][i]) {
                    dist[i] = dist[curr] + adj[curr][i];
                    que.push(i);
                }
            }

            que.pop();
        }

        cout << "Case " << ++k << ": ";
        if(dist[n] == INF) cout << "Impossible\n";
        else cout << dist[n] << '\n';
    }

    return 0;
}
