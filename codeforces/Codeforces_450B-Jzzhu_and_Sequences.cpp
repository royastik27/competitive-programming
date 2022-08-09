/**
 * Codeforces Round #257 (Div. 2)
 * Problem B - Jzzhu and Sequences
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MOD 1000000007

class Solution {

public:
    int solve()
    {
        int arr[6];

        cin >> arr[0] >> arr[1];

        for(int i = 2; i < 6; ++i)
            arr[i] = arr[i-1] - arr[i-2];

        int idx;
        cin >> idx;

        idx = idx % 6 - 1;
        if(idx < 0) idx += 6;

        int ans = arr[idx] % MOD;
        
        return (ans < 0) ? ans += MOD : ans;
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