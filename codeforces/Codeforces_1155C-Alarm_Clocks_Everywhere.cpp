/**
 * Educational Codeforces Round 63 (Rated for Div. 2)
 * Problem C - Alarm Clocks Everywhere
 * TIME: 280 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution{

public:
    void solve()
    {
        int n, m, i;
        ll el, gcd = 0;
        vector <ll> x, p;

        cin >> n >> m >> el;

        x.push_back(el);

        for(i = 1; i < n; ++i)
        {
            cin >> el;
            x.push_back(el);
            gcd = __gcd(gcd, el - x[i-1]);
        }

        for(i = 0; i < m; ++i)
            { cin >> el; p.push_back(el); }

        for(i = 0; i < m; ++i)
            if(gcd % p[i] == 0)
            {
                cout << "YES\n" << x[0] << ' ' << i+1 << '\n';
                return;
            }

        cout << "NO\n";
        
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