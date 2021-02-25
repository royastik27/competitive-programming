/**
* UVA 11518 - Dominos 2
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>

int adj[10001][10001], node, count;
_Bool visited[10001];

void dfsVisit(int x)
{
    if(visited[x])
        return;

    count++;
    visited[x] = 1;

    int i;
    for(i = 1; i<=node; i++)
    {
        if(adj[x][i] == 1 && visited[i] == 0)
        {
            dfsVisit(i);
        }
    }
}


int main()
{
    int test, edge, toFall, i, j, n1, n2, data;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d %d", &node, &edge, &toFall);

        for(i = 1; i<=node; i++)
        {
            for(j = 1; j<=node; j++)
            {
                adj[i][j] = 0;
            }
            visited[i] = 0;
        }

        for(i = 0; i<edge; i++)
        {
            scanf("%d %d", &n1, &n2);

            adj[n1][n2] = 1;
        }

        count = 0;
        for(i = 0; i<toFall; i++)
        {
            scanf("%d", &data);
            dfsVisit(data);
        }

        printf("%d\n", count);
    }

    return 0;
}
