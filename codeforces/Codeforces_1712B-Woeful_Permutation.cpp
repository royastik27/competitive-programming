/**
 * Codeforces Round #813 (Div. 2)
 * Problem B - Woeful Permutation
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100001

class Solution {

public:
    void solve()
    {
        int n, ans[LIM], i;
        bool vis[LIM + 1];
        memset(vis, 0, sizeof(vis));

        cin >> n;
        vis[0] = true;
        vis[n + 1] = true;

        for(i = n; i > 0; --i)
        {
            if(!vis[i + 1]) { ans[i] = i + 1; vis[i+1] = true; }
            else if(!vis[i - 1]){ ans[i] = i - 1; vis[i-1] = true; }
            else { ans[i] = i; vis[i] = true; }
        }
        
        for(i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';

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