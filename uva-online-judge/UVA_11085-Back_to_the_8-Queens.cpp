/**
 * UVA 11085 - Back to the 8-Queens
 * Time: 0.070 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 8

class Solution {
    bool row[8], primary[15], secondary[15];
    int board[8], queen[8];

    int nqueen(int col)
    {
        if(col == LIM)
        {
            int cnt = 0;

            for(int i = 0; i < LIM; ++i)
                if(queen[i] != board[i]) ++cnt;
            
            return cnt;
        }

        int ans = 9;

        for(int i = 0; i < LIM; ++i)
        {
            if(row[i] || primary[i - col + 7] || secondary[i + col])
                continue;

            queen[col] = i + 1;

            row[i] = primary[i - col + 7] = secondary[i + col] = true;

            ans = min(nqueen(col + 1), ans);

            row[i] = primary[i - col + 7] = secondary[i + col] = false;
        }

        return ans;
    }
public:
    int solve(int first)
    {   memset(row, 0, sizeof(row));
        memset(primary, 0, sizeof(primary));
        memset(secondary, 0, sizeof(secondary));

        board[0] = first;

        for(int i = 1; i < LIM; ++i)
            cin >> board[i];

        return nqueen(0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int first, TC = 0;

    while(cin >> first)
        cout << "Case " << ++TC << ": " << sol.solve(first) << '\n';
    
    return 0;
}