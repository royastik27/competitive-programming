/**
* Educational Codeforces Round 143 (Rated for Div. 2)
* Problem C - Tea Tasting
* TIME: 217 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> a;

    multiset <ll> s;
    multiset <ll>::iterator it, UB, to_del;
public:
    void solve()
    {
        int n, i, no_mn, amount;
        ll ans, prop;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> amount;
            a.push_back(amount);
        }

        prop = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> amount;

            s.insert(a[i] + prop);

            UB = s.upper_bound(amount + prop);

            // for smaller and equal numbers
            no_mn = ans = 0;
            for(it = s.begin(); it != UB; ++it)
            {
                ans += *it - prop;
                ++no_mn;
            }

            // for greater numbers
            ans += ll(s.size() - no_mn) * amount;
            prop += amount;

            // removing smaller and equal numbers
            it = s.begin();
            while(it != UB)
            {
                to_del = it;
                ++it;
                s.erase(to_del);
            }

            cout << ans << ' ';
        }

        cout << '\n';

        a.clear();
        s.clear();

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