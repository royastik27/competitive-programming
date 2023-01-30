/**
 * Codeforces Round #603 (Div. 2)
 * Problem D - Secret Passwords
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
    int n, i, len, ans, par[26], idx0, idx;
    string str;
    char ch;
    bool vis[26];

    int Find(int x)
    {
        if(par[x] < 0)
            return x;

        return par[x] = Find(par[x]);
    }

    void Union(int x, int y)
    {
        int parX = Find(x), parY = Find(y);

        if(parX == parY)
            return;

        if(par[parX] < par[parY])
        {
            par[parX] += par[parY];
            par[parY] = parX;
        }
        else
        {
            par[parY] += par[parX];
            par[parX] = parY;
        }

        return;
    }
public:
    int solve()
    {
        cin >> n;

        memset(vis, 0, sizeof(vis));
        memset(par, -1, sizeof(par));

        while(n--)
        {
            cin >> str;

            len = str.length();
            idx0 = int(str[0] - 'a');
            vis[idx0] = true;

            for(i = 1; i < len; ++i)
            {
                idx = int(str[i] - 'a');

                vis[idx] = true;

                Union(idx0, idx);
            }
        }

        ans = 0;
        for(i = 0; i < 26; ++i)
        {
            if(par[i] < 0 && vis[i])
                ++ans;
        }        
        
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