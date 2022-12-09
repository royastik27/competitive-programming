/**
 * Codeforces Round #177 (Div. 2)
 * Problem B - Polo the Penguin and Matrix
 * TIME: 498 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int solve()
    {
        int row, col, d, num, diff, i, j, op, ans;
        vector <int> vec;

        cin >> row >> col >> d;

        row *= col;

        for(i = 0; i < row; ++i)
        {
            cin >> num;
            vec.push_back(num);
        }

        ans = INT_MAX;
        for(i = 0; i < row; ++i)
        {
            op = 0;
            for(j = 0; j < row; ++j)
            {
                diff = abs(vec[i] - vec[j]);
                if(diff % d)
                {
                    op = INT_MAX;
                    break;
                }
                else op += diff / d;
            }

            ans = min(ans, op);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';

    return 0;
}