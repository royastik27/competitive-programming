/**
* UVA 11953 - Battleships
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 100

char grid[LIMIT][LIMIT];
int Size;
bool alive;

void isAlive(int x, int y)
{
    // base case
    if(x < 0 || x == Size || y < 0 || y == Size || grid[x][y] == '.')
        return;

    if(grid[x][y] == 'x')
        alive = true;

    grid[x][y] = '.';

    // vertical and horizontal traversing
    isAlive(x-1, y);
    isAlive(x+1, y);
    isAlive(x, y-1);
    isAlive(x, y+1);
}

int countShips()
{
    int i, j, Count = 0;

    for(i = 0; i < Size; ++i)
    {
        for(j = 0; j < Size; ++j)
        {
            if(grid[i][j] != '.')
            {
                alive = false;
                isAlive(i, j);
                if(alive) ++Count;
            }
        }
    }

    return Count;
}

int main()
{
    int TC, k, i, j;

    cin >> TC;

    for(k = 1; k<=TC; ++k)
    {
        cin >> Size;

        // getting input
        for(i = 0; i<Size; ++i)
            for(j = 0; j<Size; ++j)
                cin >> grid[i][j];

        cout << "Case " << k << ": " << countShips() << '\n';
    }

    return 0;
}
