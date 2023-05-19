/**
* CodeChef COW3E - SIMPLE MODIFICATION
* A problem of 2D Prefix Sum
* Cannot submit and check because this problem is unavailable for submission
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 1010
// #define LIM 10

class Solution
{
    int arr[LIM][LIM], add[LIM + 1][LIM + 1];
    ll pre_sum[LIM][LIM];
public:
    void solve()
    {
        int n, m, u, q, i, j, k, r1, r2, c1, c2;
        ll linear_pre;

        cin >> n >> m >> u >> q;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                cin >> arr[i][j];
                
                add[i][j] = 0;
            }

        while(u--)
        {
            cin >> k >> r1 >> c1 >> r2 >> c2;

            add[r1][c1] += k;
            add[r2+1][c1] -= k;
            add[r1][c2+1] -= k;
            add[r2+1][c2+1] += k;
        }

        // ROW WISE PRESUM FOR add[][]
        for(i = 0; i < n; ++i)
            for(j = 1; j < m; ++j)
                add[i][j] += add[i][j-1];

        // COL WISE PRESUM FOR add[][]
        // + ADDING WITH ORIGINAL ARRAY
        for(j = 0; j < m; ++j)
        {
            arr[0][j] += add[0][j];

            for(i = 1; i < n; ++i)
            {
                add[i][j] += add[i-1][j];
                arr[i][j] += add[i][j];
            }
        }

        // THE PRESUM OF ORIGINAL ARRAY

        // READY pre_sum[0]
        pre_sum[0][0]= arr[0][0];

        for(j = 1; j < m; ++j)
            pre_sum[0][j] = pre_sum[0][j-1] + arr[0][j];

        // READY pre_sum[i], 1 <= i < n
        for(i = 1; i < n; ++i)
        {
            linear_pre = 0;

            for(j = 0; j < m; ++j)
            {
                linear_pre += arr[i][j];

                pre_sum[i][j] = pre_sum[i-1][j] + linear_pre;
            }
        }

        // PRINTING
        // cout << "ARRAY:\n";
        // for(i = 0; i < n; ++i)
        // {
        //     for(j = 0; j < m; ++j)
        //         cout << arr[i][j] << ' ';
        //     cout << '\n';
        // }

        while(q--)
        {
            cin >> r1 >> c1 >> r2 >> c2;

            cout << (pre_sum[r2][c2] - (r1 ? pre_sum[r1-1][c2] : 0) - (c1 ? pre_sum[r2][c1-1] : 0) + (r1 && c1 ? pre_sum[r1-1][c1-1] : 0)) << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}