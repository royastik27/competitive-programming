/**
 * Codeforces Round #813 (Div. 2)
 * Problem A - Wonderful Permutation
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {

public:
    int solve()
    {
        int cnt = 0, n, k, arr[100], i;

        cin >> n >> k;
        for(i = 0; i < n; ++i) cin >> arr[i];

        for(i = 0; i < k; ++i)
            if(arr[i] > k) ++cnt;

        return cnt;
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