/**
 * Codeforces Round #804 (Div. 2)
 * Problem B - Almost Ternary Matrix
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    int ans[50];

    public:
    void solve()
    {
        int row, col, i, j;

        cin >> row >> col;
        int halfRow = row / 2, halfCol = col / 2;

        ans[0] = 1; ans[1] = 0;
        for(i = 2; i < col; i += 2)
        {
            ans[i] = ans[i-1];
            ans[i+1] = ans[i] ^ 1;
        }

        for(i = 0; i < halfRow; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                cout << ans[j] << ' ';
                ans[j] ^= 1;
            }
            cout << '\n';

            for(j = 0; j < col; ++j)
                cout << ans[j] << ' ';
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