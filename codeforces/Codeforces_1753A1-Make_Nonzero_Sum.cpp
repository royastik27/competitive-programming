/**
 * Codeforces Round #829 (Div. 1)
 * Problem A1 - Make Nonzero Sum (easy version)
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector <int> ans;
public:
    void solve()
    {
        int n, i, el, dp = 0;

        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> el;

            if(ans.size() & 1)
            {
                if(el == dp)
                    ans.push_back(i);
                else
                {
                    ans.push_back(i-1);
                    ans.push_back(i);
                    ans.push_back(i);
                }
                dp = 0;
            }
            else
            {
                ans.push_back(i);
                dp = el;
            }
        }

        n = ans.size();
        if(n & 1) cout << "-1\n";
        else
        {
            cout << n / 2 << '\n';
            for(i = 0; i < n; i+=2)
                cout << ans[i] << ' ' << ans[i+1] << '\n';
        }        

        ans.clear();
        
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
