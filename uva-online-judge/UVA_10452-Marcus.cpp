/**
* UVA 10452 - Marcus
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 9

#define FORTH 1
#define LEFT 2
#define RIGHT 3

char path[LIM][LIM], match[] = "IEHOVA#";
int ans[7];

void move(int row, int col, int pos)
{
    // cout << "Called with: Row: " << row << " and Col: " << col << '\n';
    if(pos == 7) return;
    
    // LEFT CHECKING
    if(path[row][col-1] == match[pos])
    {
        ans[pos] = LEFT;
        move(row, col-1, pos+1);
    }
    // RIGHT CHECKING
    else if(path[row][col+1] == match[pos])
    {
        ans[pos] = RIGHT;
        move(row, col+1, pos+1);
    }
    // FORTH MOVE
    else
    {
        ans[pos] = FORTH;
        move(row-1, col, pos+1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, i, j, row, col;

    cin >> TC;

    while(TC--)
    {
        // INPUT SECTION
        cin >> row >> col;

        for(i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                cin >> path[i][j];

        // STARTING DFS FROM STARTING POSITION
        for(i = 0; i < col; ++i)
            if(path[row-1][i] == '@')
            {
                move(row-1, i, 0);
                break;
            }

        // PRINTING RESULT
        for(i = 0; i < 6; ++i)
        {
            switch(ans[i])
            {
                case FORTH:
                cout << "forth ";
                break;
                case LEFT:
                cout << "left ";
                break;
                case RIGHT:
                cout << "right ";
            }
        }
        switch(ans[6])
        {
            case FORTH:
            cout << "forth\n";
            break;
            case LEFT:
            cout << "left\n";
            break;
            case RIGHT:
            cout << "right\n";
        }
    }

    return 0;
}
