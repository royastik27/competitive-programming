/**
 * AIM Tech Round 4 (Div. 2)
 * Problem B - Rectangles
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

#define LIM 50

class Solution {

    ll power(ll base, int p)
    {
        if(!p) return 1;

        if(p & 1)
            return base * power(base, p-1);
        else return power(base*base, p/2);
    }

public:
    ll solve()
    {
        int n, m, i, j, zero, one, arr[LIM][LIM];

        cin >> n >> m;

        ll ans = 0;

        for(i = 0; i < n; ++i)
        {
            zero = one = 0;

            for(j = 0; j < m; ++j)
            {
                cin >> arr[i][j];

                if(!arr[i][j]) ++zero;
                else ++one;
            }

            ans += power(2, zero) + power(2, one) - 2;
        }

        for(i = 0; i < m; ++i)
        {
            zero = one = 0;

            for(j = 0; j < n; ++j)
            {
                if(!arr[j][i]) ++zero;
                else ++one;
            }

            ans += power(2, zero) + power(2, one) - 2 - n;
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
