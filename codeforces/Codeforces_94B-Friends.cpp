/**
 * Codeforces Beta Round #76 (Div. 2 Only)
 * Problem B - Friends
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 11

class Solution{
public:
    bool solve()
    {
        int m, i, j, k;
        bool adj[LIM][LIM] = {};

        cin >> m;

        while(m--)
        {
            cin >> i >> j;
            adj[i][j] = adj[j][i] = true;
        }

        for(i = 1; i <= 5; ++i)
        {
            for(j = 1; j <= 5; ++j)
            {
                if(j == i) continue;

                for(k = 1; k <= 5; ++k)
                {
                    if(k == i || k == j) continue;

                    if(adj[i][k] == adj[i][j] && adj[j][k] == adj[i][j])
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    if(sol.solve()) cout << "WIN\n";
    else cout << "FAIL\n";

    return 0;
}