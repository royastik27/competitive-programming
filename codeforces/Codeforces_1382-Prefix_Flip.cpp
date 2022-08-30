/**
 * Codeforces Round #658 (Div. 2)
 * Problem C1 - Prefix Flip (Easy Version)
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

#define LIM 1000

class Solution {
    char str[LIM + 1];
    bool init[LIM], final[LIM];

    void reverse(int n)
    {
        int i;
        bool temp[LIM];

        for(i = 0; i <= n; ++i)
            temp[i] = init[i] ? 0 : 1;

        for(i = 0; i <= n; ++i)
            init[n-i] = temp[i];

        return;
    }
public:
    void solve()
    {
        int n, i;
        vector <int> ans;

        cin >> n >> str;

        for(i = 0; i < n; ++i)
            init[i] = (str[i] == '1') ? 1 : 0;

        cin >> str;
        for(i = 0; i < n; ++i)
            final[i] = (str[i] == '1') ? 1 : 0;

        for(i = n - 1; i >= 0; --i)
        {
            if(init[i] == final[i]) continue;

            if(init[0] == final[i])
            {
                ans.push_back(1);
                reverse(0);
            }

            ans.push_back(i+1);
            reverse(i);
        }
        
        n = ans.size();
        cout << n << '\n';
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        if(n) cout << '\n';

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