/**
 * Codeforces Round #586 (Div. 1 + Div. 2)
 * Problem B - Multiplication Table
 * TIME: 280 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

#define LIM 1000

class Solution{
    int arr[LIM][LIM];
public:
    void solve()
    {
        int n, i, j, a1;

        cin >> n;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                cin >> arr[i][j];

        a1 = arr[0][2] / sqrt((ll)arr[0][2] * arr[1][2] / arr[0][1]);

        cout << a1 << ' ';
        for(i = 1; i < n; ++i)
            cout << arr[0][i] / a1 << ' ';
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