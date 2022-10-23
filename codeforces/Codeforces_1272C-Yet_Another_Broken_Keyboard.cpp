/**
 * Codeforces Round #605 (Div. 3)
 * Problem C - Yet Another Broken Keyboard
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

typedef long long int ll;
 
class Solution {    

public:
    ll solve()
    {
        string str;
        int n, k, i, mp = 0, idx, cnt;
        ll ans = 0;

        cin >> n >> k >> str;

        {
            char ch;

            while(k--)
            {
                cin >> ch;
                idx = int(ch - 'a');
                mp |= (1 << idx);
            }
        }

        cnt = 0;
        for(i = 0; i < n; ++i)
        {
            idx = int(str[i] - 'a');

            if(mp & (1 << idx))
                ++cnt;
            else
            {
                ans += (ll) cnt * (cnt+1) / 2;
                cnt = 0;
            }
        }

        ans += (ll) cnt * (cnt+1) / 2;

        return ans;
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