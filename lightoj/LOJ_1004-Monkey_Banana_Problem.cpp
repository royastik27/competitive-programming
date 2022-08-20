/**
 * LightOJ 1004 - Monkey Banana Problem
 * TIME: 43 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100

class Solution {
    int arr[LIM][LIM];    
public:
    int solve()
    {
        int n, i, j;

        cin >> n;

        cin >> arr[0][0];

        for(i = 1; i < n; ++i)
        {
            cin >> arr[i][0];
            arr[i][0] += arr[i-1][0];

            for(j = 1; j < i; ++j)
            {
                cin >> arr[i][j];
                arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
            }

            cin >> arr[i][i];
            arr[i][i] += arr[i-1][i-1];
        }

        for(i = n - 2; i >= 0; --i)
        {
            for(j = 0; j <= i; ++j)
            {
                cin >> arr[i][j];
                arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
            }
        }

        return arr[0][0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC, k = 0;
    cin >> TC;

    while(TC--)
        cout << "Case " << ++k << ": " << sol.solve() << '\n';
    
    return 0;
}