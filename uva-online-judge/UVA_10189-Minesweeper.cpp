/**
* UVa 10189 - Minesweeper
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int row, col;

char field[100][100];

void incre(int x, int y)
{
    if(x < 0 || x == row || y < 0 || y == col || field[x][y] == '*')
        return;

    ++field[x][y];

    return;
}

int main()
{
    register int i, j;
    int k = 0;
    char ch;

    while(1)
    {
        cin >> row >> col;

        if(!row && !col) break;

        // getting input
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                cin >> ch;

                if(ch == '*') field[i][j] = ch;
                else field[i][j] = '0';
            }
        }

        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                if(field[i][j] == '*')
                {
                    incre(i, j-1);
                    incre(i, j+1);
                    incre(i-1, j-1);
                    incre(i-1, j);
                    incre(i-1, j+1);
                    incre(i+1, j-1);
                    incre(i+1, j);
                    incre(i+1, j+1);
                }
            }
        }

        if(k) cout << '\n';

        cout << "Field #" << ++k << ":\n";
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
                cout << field[i][j];

            cout << '\n';
        }
    }

    return 0;
}
