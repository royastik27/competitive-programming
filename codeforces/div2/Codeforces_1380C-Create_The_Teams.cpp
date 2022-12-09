/**
 * Educational Codeforces Round 91 (Rated for Div. 2)
 * Problem C - Create The Teams
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define LIM 100000

class Solution
{
    int arr[LIM], dp[LIM+1];
public:
    int solve()
    {
        int n, x, i, quo, mx;

        cin >> n >> x;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr+n);

        dp[n] = 0;
        for(i = n-1; i >= 0; --i)
        {
            quo = int(ceil(double(x) / arr[i]));

            dp[i] = (quo <= n-i ? dp[i+quo] : -1) + 1;
        }

        mx = -1;
        for(i = 0; i < n; ++i)
            if(dp[i] > mx) mx = dp[i];

        return mx;
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