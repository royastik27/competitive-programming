/**
 * Codeforces Round #817 (Div. 4)
 * Problem F - L-shapes
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define LIM 50

int r_move[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }, c_move[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };

class Solution {
    char grid[LIM][LIM];

    vector < pair<int, int> > first;
    vector < pair<int, int> > second;
public:
    Solution()
    {
        first.push_back(make_pair(0, 1));
        first.push_back(make_pair(0, 1));
        first.push_back(make_pair(1, 0));
        first.push_back(make_pair(1, 0));

        second.push_back(make_pair(1, 1));
        second.push_back(make_pair(1, 0));
        second.push_back(make_pair(1, 1));
        second.push_back(make_pair(1, -1));
    }
    bool solve()
    {
        int row, col, i, j, k, x1, y1, x2, y2, r, c, m;
        bool isPossible;

        cin >> row >> col;

        for(i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                cin >> grid[i][j];

        // PROCESSING
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                if(grid[i][j] == '*')
                {
                    for(k = 0; k < 4; ++k)
                    {
                        x1 = i + first[k].first;
                        y1 = j + first[k].second;

                        x2 = i + second[k].first;
                        y2 = j + second[k].second;

                        if(x1 < 0 || x2 < 0 || x1 == row || x2 == row || y1 < 0 || y2 < 0 || y1 == col || y2 == col) continue;

                        if(grid[x1][y1] == '*' && grid[x2][y2] == '*')
                        {
                            // No start around a star
                            isPossible = true;
                            
                            for(m = 0; m < 8; ++m)
                            {
                                r = x1 + r_move[m];
                                c = y1 + c_move[m];

                                if(r < 0 || r == row || c < 0 || c == col || (r == i && c == j) || (r == x2 && c == y2)) continue;

                                if(grid[r][c] == '*') { isPossible = false; break; }
                            }

                            for(m = 0; m < 8; ++m)
                            {
                                r = x2 + r_move[m];
                                c = y2 + c_move[m];

                                if(r < 0 || r == row || c < 0 || c == col || (r == i && c == j) || (r == x1 && c == y1)) continue;

                                if(grid[r][c] == '*') { isPossible = false; break; }
                            }

                            for(m = 0; m < 8; ++m)
                            {
                                r = i + r_move[m];
                                c = j + c_move[m];

                                if(r < 0 || r == row || c < 0 || c == col || (r == x1 && c == y1) || (r == x2 && c == y2)) continue;

                                if(grid[r][c] == '*') { isPossible = false; break; }
                            }
                            
                            if(isPossible)
                                grid[i][j] = grid[x1][y1] = grid[x2][y2] = '.';
                        }
                    }
                }
            }
        }

        // PRINTING RESULT
        for(i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                if(grid[i][j] == '*') return false;
        
        return true;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}