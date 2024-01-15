/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    multiset <int> s1, s2;
    multiset <int>::iterator mn, mx, to_del;
public:
    void solve()
    {
        cin >> n >> m;

        a.resize(n);
        b.resize(m);

        for(i = 0; i < n; ++i)
            cin >> a[i];

        for(i = 0; i < m; ++i) {
            cin >> b[i];
            s1.insert(b[i]);
            s2.insert(b[i]);
        }

        sort(a.begin(), a.end());

        ans1 = ans2 = 0;
        // forward pass
        for(i = 0; i < n; ++i) {
            mn = s1.begin();
            mx = --s1.end();

            mn_diff = a[i] - *mn;
            if(mn_diff < 0) mn_diff = 0 - mn_diff;

            mx_diff = *mx - a[i];
            if(mx_diff < 0) mx_diff = 0 - mx_diff;

            if(mn_diff > mx_diff) {
                ans1 += mn_diff;
                to_del = mn;
            }
            else {
                ans1 += mx_diff;
                to_del = mx;
            }

            s1.erase(to_del);
        }

        // backward pass
        for(i = n-1; i >= 0; --i) {
            //
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}