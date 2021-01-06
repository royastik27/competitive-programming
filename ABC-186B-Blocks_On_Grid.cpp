/**
* Atcoder Beginner Contest 186
* Problem B - Blocks on Grid
* Unique Solution
* Time: 10 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int row, column, minValue, nBlocks, res, sum, extra, i;

    cin >> row >> column;
    row = row * column;

    cin >> minValue;
    sum = minValue;
    res = 0;

    for(i = 2; i<=row; ++i)
    {
        cin >> nBlocks;

        sum += nBlocks;

        if(nBlocks != minValue)
        {
            if(nBlocks < minValue)
            {
                minValue = nBlocks;
                extra = sum - (minValue * i);
            }
            else if(nBlocks > minValue)
                extra = nBlocks - minValue;

                res += extra;
                sum -= extra;
        }
    }

    cout <<  res << '\n';

    return 0;
}

/* A Naive Solution */
/*
#include <iostream>

using namespace std;

#define MAX 100

int main()
{
    int row, col, i, j, minValue = MAX+1, res;

    cin >> row >> col;
    int grid[row][col];

    for(i = 0; i<row; ++i)
    {
        for(j = 0; j<col; ++j)
        {
            cin >> grid[i][j];

            if(grid[i][j] < minValue)
                minValue = grid[i][j];
        }
    }

    res = 0;
    for(i = 0; i<row; ++i)
    {
        for(j = 0; j<col; ++j)
            res += grid[i][j] - minValue;
    }

    cout << res << '\n';

    return 0;
}
*/
