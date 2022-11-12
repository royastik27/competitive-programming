/**
 * Educational Codeforces Round 65 (Rated for Div. 2)
 * Problem C - News Distribution
 * TIME: 327 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 500001

class Solution {
    int par[LIM];

    int Find(int x)
    {
        if(par[x] < 0)
            return x;

        return Find(par[x]);
    }

    void Union(int x, int y)
    {
        int parX = Find(x), parY = Find(y);

        if(parX == parY) return;

        if(par[parX] <= par[parY])
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
    void solve()
    {
        int n, m, k, per, fr;

        cin >> n >> m;
        memset(par, -1, (n+1)*sizeof(int));

        while(m--)
        {
            cin >> k;

            if(!k) continue;
            
            cin >> per;

            per = Find(per);
            --k;
            while(k--)
            {
                cin >> fr;
                Union(per, fr);
            }
        }

        for(int i = 1; i <= n; ++i)
            cout << 0 - par[Find(i)] << ' ';
        cout << '\n';
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