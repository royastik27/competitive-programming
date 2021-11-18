/**
 * Codeforces Round #744 (Div. 3)
 * Problem C - Ticks
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int n, m, k;
char grid[10][19];

int dfsVisit(int i, int j, int dis = 1)
{
    // checking boundary
    if(i-dis < 0 || j-dis < 0 || j+dis == m) return 0;

    if((grid[i-dis][j-dis] == '*' || grid[i-dis][j-dis] == 'v') && (grid[i-dis][j+dis] == '*' || grid[i-dis][j+dis] == 'v'))
        return 1 + dfsVisit(i, j, dis+1);

    return 0;
}

void dfs()
{
    int i, j, h, cnt;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            if(grid[i][j] == '*' || grid[i][j] == 'v') {

                // count the size of the tick
                cnt = dfsVisit(i, j);

                // if any valid tick
                if(cnt >= k) {
                    grid[i][j] = 'v';
                    for(h = 1; h <= cnt; ++h)
                        grid[i-h][j-h] = grid[i-h][j+h] = 'v';
                }
            }
        }
    }

    return;
}

void printGrid()
{
    int i, j;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

void printRes()
{
    int i, j;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            if(grid[i][j] == '*') {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC;
    register int i, j;

    cin >> TC;

    while(TC--){
        cin >> n >> m >> k;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
                cin >> grid[i][j];

        dfs();
        printRes();
        //printGrid();
    }

    return 0;
}
