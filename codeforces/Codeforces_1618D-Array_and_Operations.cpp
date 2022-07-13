/**
 * Codeforces Round #760 (Div. 3)
 * Problem D - Array and Operations
 * Time: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 100

class Solution
{
    int arr[LIM];

    public:
    int solve()
    {
        int n, k, ans = 0, i;

        // INPUT
        cin >> n >> k;
        for(i = 0; i < n; ++i) cin >> arr[i];

        sort(arr, arr+n);

        // GETTING ANS
        for(i = 0; i < k; ++i)
            ans += arr[n - k - i - 1] / arr[n - i - 1];

        int lim = n - 2*k;
        for(i = 0; i < lim; ++i)
            ans += arr[i];

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