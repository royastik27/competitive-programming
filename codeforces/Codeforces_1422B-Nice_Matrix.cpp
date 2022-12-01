/**
 * Codeforces Round #675 (Div. 2)
 * Problem B - Nice Matrix
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

#define LIM 100

class Solution
{
    int mat[LIM][LIM];
    vector <int> val;

    int find_min()
    {
        int i, j;
        ll mn = INT_MAX, res, sz = val.size();

        for(i = 0; i < sz; ++i)
        {
            res = 0;

            for(j = 0; j < sz; ++j)
                res += abs(val[i]-val[j]);

            mn = min(mn, res);
        }

        return int(mn);
    }
public:
    ll solve()
    {
        int row, col, halfRow, halfCol, i, j;
        ll ans = 0;

        cin >> row >> col;

        for(i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                cin >> mat[i][j];

        halfRow = (row-1)/2;    halfCol = (col-1)/2;

        for(i = 0; i <= halfRow; ++i)
        {
            for(j = 0; j <= halfCol; ++j)
            {
                val.push_back(mat[i][j]);

                if(col-j-1 != j)
                    val.push_back(mat[i][col-j-1]);

                if(row-i-1 != i)
                    val.push_back(mat[row-i-1][j]);

                if(col-j-1 != j && row-i-1 != i)
                    val.push_back(mat[row-i-1][col-j-1]);

                ans += find_min();
                val.clear();
            }
        }        

        return ans;
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
        cout << sol.solve() << '\n';

    return 0;
}