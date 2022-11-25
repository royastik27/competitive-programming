/**
 * Educational Codeforces Round 103 (Rated for Div. 2)
 * Problem B - Inflation
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution{

public:
    ll solve()
    {
        int n, k;
        ll ans = 0, inc, prev, x;

        cin >> n >> k >> prev;

        --n;
        while(n--)
        {
            cin >> inc;

            x = ceil((inc*100 - k*prev) / double(k));

            if(x > 0)
            {
                ans += x;
                prev += x;
            }

            prev += inc;
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