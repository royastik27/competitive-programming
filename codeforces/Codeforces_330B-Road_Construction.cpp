/**
 * Codeforces Round #192 (Div. 2)
 * Problem B - Road Construction
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 1001

class Solution {

public:
    void solve()
    {
        int n, m, i, j;
        bool deg[LIM];
        memset(deg, 0, sizeof(deg));

        cin >> n >> m;

        while(m--)
        {
            cin >> i;
            deg[i] = true;
            cin >> i;
            deg[i] = true;
        }

        for(i = 1; i <= n; ++i)
        {
            if(!deg[i])
            {
                cout << n - 1 << '\n';

                for(j = 1; j <= n; ++j)
                {
                    if(j == i) continue;
                    cout << i << ' ' << j << '\n';
                }

                break;
            }
        }

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