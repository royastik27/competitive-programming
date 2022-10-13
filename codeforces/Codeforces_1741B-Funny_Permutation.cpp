/**
 * Codeforces Round #826 (Div. 3)
 * Problem B - Funny Permutation
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
class Solution {
    
public:
    void solve()
    {
        int n;
 
        cin >> n;
 
        if(n == 3) cout << -1 << '\n';
        else
        {
            cout << n << ' ' << n - 1 << ' ';
 
            n -= 2;
            for(int i = 1; i <= n; ++i) cout << i << ' ';
            cout << '\n';
        }        
        
        return;
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
        sol.solve();
    
    return 0;
}