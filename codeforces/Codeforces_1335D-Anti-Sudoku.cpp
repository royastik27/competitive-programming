/**
 * Codeforces Round #634 (Div. 3
 * Problem D - Anti-Sudoku
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {
    char grid[9][9];

    void change(int i, int j)
    {
        if(grid[i][j] == '9') grid[i][j] = '1';
        else grid[i][j] = '9';
        return;
    }
    
public:
    void solve()
    {
        int i, j;

        for(i = 0; i < 9; ++i)
            for(j = 0; j < 9; ++j) cin >> grid[i][j];

        change(0, 0);
        change(1, 3);
        change(2, 6);

        change(3, 1);
        change(4, 4);
        change(5, 7);

        change(6, 2);
        change(7, 5);
        change(8, 8);

        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j) cout << grid[i][j];
            cout << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC;
    cin >> TC;

    while(TC--)
        sol.solve();
    
    return 0;
}