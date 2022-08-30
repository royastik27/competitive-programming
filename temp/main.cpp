/**
 * LightOJ 1238 - Power Puff Girls
 * TIME: 4 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define LIM 50

class Solution {
    char grid[LIM][LIM];

    vector < pair<int, int> > first;
    vector < pair<int, int> > second;

    Solution()
    {
        first.push_back(make_pair(0, 1));
        first.push_back(make_pair(0, 1));
        first.push_back(make_pair(1, 0));
        first.push_back(make_pair(1, 0));

        second.push_back(make_pair(1, 1));
        second.push_back(make_pair(1, 0));
        second.push_back(make_pair(1, 1));
        second.push_back(make_pair(-1, -1));
    }
public:
    bool solve()
    {
        int row, col, i, j, k, x1, y1, x2, y2;

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
    // cin.tie(NULL);

    Solution sol;

    int TC;
    cin >> TC;
    
    while(TC--)
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}