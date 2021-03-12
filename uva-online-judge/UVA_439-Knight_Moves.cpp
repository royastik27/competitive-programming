/**
* UVA 439 - Knight Moves
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

#define INF 100

typedef struct
{
    int row, col;
}Grid;

int rowMove[8] = {-2, -2, -1, -1, 1, 1, 2, 2 },
colMove[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 0 based indexed

int find_moves(Grid src, Grid dest)
{
    Grid curr, nextGrid;
    int moves[8][8], i, j;

    for(i = 0; i < 8; ++i)
        for(j = 0; j < 8; ++j)
            moves[i][j] = INF;

    moves[src.row][src.col] = 0;

    queue <Grid> que;

    que.push(src);

    while(!que.empty())
    {
        curr = que.front();

        if(curr.row == dest.row && curr.col == dest.col)
            return moves[dest.row][dest.col];

        que.pop();

        for(i = 0; i < 8; ++i)
        {
            nextGrid.row = curr.row + rowMove[i];
            nextGrid.col = curr.col + colMove[i];

            if(nextGrid.row < 0 || nextGrid.row > 7 || nextGrid.col < 0 || nextGrid.col > 7)
                continue;

            if(moves[curr.row][curr.col] + 1 < moves[nextGrid.row][nextGrid.col])
            {
                moves[nextGrid.row][nextGrid.col] = moves[curr.row][curr.col] + 1;
                que.push(nextGrid);
            }
        }
    }

    return moves[dest.row][dest.col];
}

int main()
{
    Grid src, dest;
    char ch1[3], ch2[3];

    while(cin >> ch1 >> ch2)
    {
        src.col = ch1[0]-'a';
        src.row = ch1[1] - '1';

        dest.col = ch2[0]-'a';
        dest.row = ch2[1] - '1';

        cout << "To get from " << ch1 << " to " << ch2 << " takes " << find_moves(src, dest) << " knight moves.\n";
    }

    return 0;
}
