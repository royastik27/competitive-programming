/**
 * Codeforces Round #631 (Div. 2) - Thanks, Denis aramis Shitov!
 * Problem B - Dreamoon Likes Permutations
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 200000

class Solution {
    int a[LIM], n, i, num, mx;
    bool forw[LIM], back[LIM], vis[LIM];
    vector <int> ans;
public:
    void solve()
    {
        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[i];

        memset(forw, 0, n);
        memset(back, 0, n);

        // forward calculation
        mx = 0;
        memset(vis, 0, n);

        for(i = 0; i < n; ++i)
        {
            num = a[i];

            if(vis[num]) break;
            vis[num] = true;

            if(num > mx) mx = num;

            if(mx == i+1) forw[i] = true;
        }

        // backward calculation
        mx = 0;
        memset(vis, 0, n);

        for(i = n-1; i >= 0; --i)
        {
            num = a[i];

            if(vis[num]) break;
            vis[num] = true;

            if(num > mx) mx = num;

            if(mx == n-i) back[i] = true;
        }

        for(i = 1; i < n; ++i)
        {
            if(forw[i-1] && back[i])
                ans.push_back(i);
        }

        num = ans.size();
        cout << num << '\n';
        for(i = 0; i < num; ++i)
            cout << ans[i] << ' ' << (n - ans[i]) << '\n';

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