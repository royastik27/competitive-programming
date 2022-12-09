/**
 * Codeforces Round #300
 * Problem B - Quasi Binary
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
class Solution
{
public:
    void solve()
    {
        string num;
        int ans[9] = {}, digit, mx, i, j, sz;
 
        cin >> num;
 
        sz = num.length();
        mx = 0;
 
        for(i = 0; i < sz; ++i)
        {
            digit = int(num[i]-'0');
            if(digit > mx) mx = digit;
 
            for(j = 0; j < digit; ++j)
                ans[j] = ans[j] * 10 + 1;
 
            for(; j < 9; ++j)
                ans[j] *= 10;
        }
 
        cout << mx << '\n';
        for(i = 0; i < mx; ++i)
            cout << ans[i] << ' ';
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