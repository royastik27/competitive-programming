/**
* Lyft Level 5 Challenge 2018 - Elimination Round
* Problem A - King Escape
* Time: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

#define LIMIT 1001
#define EMPTY_VALUE -1
#define TRUE 1
#define FALSE 2

using namespace std;

int board[LIMIT][LIMIT];

int n, ax, ay, cx, cy;

void play(int x, int y)
{
    if(board[x][y] != EMPTY_VALUE || x < 1 || x > n || y < 1 || y > n)
        return;

    else if(x == ax || y == ay || y == ay-(x-ax) || y == ay+(x-ax))
    {
        board[x][y] = FALSE;
        return;
    }

    board[x][y] = TRUE;

    if(x == cx && y == cy)
        return;

    play(x-1, y-1);
    play(x-1, y);
    play(x-1, y+1);

    play(x, y-1);
    play(x, y+1);

    play(x+1, y-1);
    play(x+1, y);
    play(x+1, y+1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int bx, by, i, j;

    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            board[i][j] = EMPTY_VALUE;

    play(bx, by);

    if(board[cx][cy] == TRUE)
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
