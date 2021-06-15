/**
* Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
* Problem A - Colour the Flag
* Time: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 50

int n, m;

bool checkGrid(char ch, char grid[LIM][LIM])
{
    int i, j;

    for(i = 0; i < m; ++i) {

        if(grid[0][i] == '.')
            grid[0][i] = ch;
        else
            if(grid[0][i] != ch) return false;

        ch = (ch == 'W') ? 'R' : 'W';
    }

    for(i = 1; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            if(grid[i][j] == '.')
                grid[i][j] = (grid[i-1][j] == 'W') ? 'R' : 'W';
            else if(grid[i][j] == grid[i-1][j]) return false;
        }
    }

    return true;
}

void printGrid(char grid[LIM][LIM])
{
    int i, j;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j)
            cout << grid[i][j];
        cout << '\n';
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC;
    char grid[LIM][LIM], temp[LIM][LIM];
    register int i, j;

    cin >> TC;

    while(TC--) {
        cin >> n >> m;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j) {
                cin >> grid[i][j];
                temp[i][j] = grid[i][j];
            }

        if(checkGrid('W', grid)) {
            cout << "YES\n";
            printGrid(grid);
        }
        else if(checkGrid('R', temp)) {
            cout << "YES\n";
            printGrid(temp);
        }
        else
            cout << "NO\n";
    }

    return 0;
}
