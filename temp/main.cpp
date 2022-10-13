/**
 * Codeforces Round #826 (Div. 3)
 * Problem A - Compare T-Shirt Sizes
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;

#define LIM 200001
 
class Solution {
    int arr[LIM], que[LIM];
    long long pre[LIM];
    map <int, int> mp;
public:
    void solve()
    {
        int n, q, i;

        cin >> n >> q;

        arr[0] = pre[0] = 0;

        for(i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            pre[i] = pre[i-1] + arr[i];
        }

        for(i = 0; i < q; ++i)
        {
            cin >> que[i];
            mp
        }

        mp.clear();
        
        return;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    Solution sol;
    int TC;
 
    cin >> TC;
 
    while(TC--)
        sol.solve();
    
    return 0;
}