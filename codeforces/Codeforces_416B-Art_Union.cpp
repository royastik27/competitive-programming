/**
 * Codeforces Round #241 (Div. 2)
 * Problem B - Art Union
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {
    int arr[50000][5];
public:
    void solve()
    {
        int m, n, i, j, prev = 0;

        cin >> m >> n;

        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
                cin >> arr[i][j];

            arr[i][0] += prev;
            prev = arr[i][0];
        }

        for(j = 1; j < n; ++j)
        {
            arr[0][j] += arr[0][j-1];

            for(i = 1; i < m; ++i)
            {
                if(arr[i][j-1] > arr[i-1][j])
                    arr[i][j] += arr[i][j-1];
                else arr[i][j] += arr[i-1][j];
            }
        }

        --n;
        for(i = 0; i < m; ++i)
            cout << arr[i][n] << ' ';
        cout << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}
