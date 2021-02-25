/**
* UVA 10004 - Bicoloring
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LIMIT 200

#define GRAY 1
#define WHITE 2
#define BLACK 3

int color[LIMIT];

int main()
{
    int nNodes, nEdges, i, j, current, currentColor, isBicolored;
    vector <int> adj[LIMIT];
    queue <int> que, temp;

    while(cin >> nNodes && nNodes)
    {
        cin >> nEdges;

        // initializing
        for(i = 0; i<nNodes; ++i)
        {
            color[i] = GRAY;
            adj[i].clear();
        }
        isBicolored = true;

        // getting edges
        while(nEdges--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        // BFS
        que.push(0);
        color[0] = WHITE;
        currentColor = WHITE;

        while(!que.empty() && isBicolored)
        {
            currentColor = (currentColor == WHITE) ? BLACK : WHITE;

            while(!que.empty())
            {
                current = que.front();

                for(i = 0; i < adj[current].size(); ++i)
                {
                    // if not visited, give the node a color and take into consider
                    if(color[adj[current][i]] == GRAY)
                    {
                        color[adj[current][i]] = currentColor;
                        temp.push(adj[current][i]);
                    }
                    // otherwise match with the expected color
                    else if(color[adj[current][i]] != currentColor)
                        isBicolored = false;
                }
                que.pop();
            }

            // cut to main queue
            while(!temp.empty())
            {
                que.push(temp.front());
                temp.pop();
            }
        }

        if(isBicolored) cout << "BICOLORABLE.\n";
        else    cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
