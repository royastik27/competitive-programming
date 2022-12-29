/**
 * Codeforces Round #788 (Div. 2)
 * Problem C - Where is the Pizza?
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100000
#define MOD 1000000007

class Solution
{
    int a[LIM], b[LIM], posA[LIM+1], posB[LIM+1], n, i, ans;
    bool vis[LIM];

    bool run(int pos, int val)
    {        
        if(vis[pos])
            return false;

        vis[pos] = true;

        if(b[pos] == val)
            return true;

        return run(posA[b[pos]], val);
    }
public:
    int solve()
    {
        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> a[i];
            posA[a[i]] = i;
        }

        for(i = 0; i < n; ++i)
        {
            cin >> b[i];
            posB[b[i]] = i;
        }

        memset(vis, 0, n);
        for(i = 0; i < n; ++i)
        {
            cin >> ans;

            vis[i] = ans;
        }

        ans = 1;
        for(i = 0; i < n; ++i)
        {
            if(a[i] == b[i])
                continue;

            if(run(i, a[i]))
                ans = ans * 2 % MOD;
        }
        
        return ans;
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