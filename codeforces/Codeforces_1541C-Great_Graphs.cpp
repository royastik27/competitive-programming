/**
 * Codeforces Round #728 (Div. 2)
 * Problem C - Great Graphs
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 100000

class Solution {    
    int arr[LIM], diff[LIM];
public:
    ll solve()
    {
        int n, i;
        ll prev, ans, curr;

        cin >> n;
        for(i = 0; i < n; ++i) cin >> arr[i];

        sort(arr, arr+n);

        diff[0] = 0;
        diff[1] = arr[1];
        for(i = 2; i < n; ++i)
            diff[i] = arr[i] - arr[i-1];

        prev = ans = 0;
        --n;
        for(i = 1; i < n; ++i)
        {
            curr = diff[i] + (ll)diff[i+1] * i + prev;
            ans += curr;
            prev = curr;
        }

        return 0 - ans;
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