/**
 * CodeChef KNIGHTATTACK - The Attack of Knight
 * Time: 0.00 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int x2, y2;
int rowMove[] = { -2, -2, -1, -1, 1, 1, 2, 2 }, colMove[] = { -1, 1, -2, 2, -2, 2, -1, 1};

bool place(int x, int y)
{
    // Make sure the peice is in the board
    if(x < 1 || x > 8 || y < 1 || y > 8) return false;

    int i;
    for(i = 0; i < 8; ++i)
    {
        if(x + rowMove[i] == x2 && y + colMove[i] == y2)
            return true;
    }
        
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, x1, y1, i;
    bool possible;

    cin >> TC;

    while(TC--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        possible = false;

        for(i = 0; i < 8; ++i)
            if(place(x1 + rowMove[i], y1 + colMove[i]))
                { possible = true; break; }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
