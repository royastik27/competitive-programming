/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    multiset <ll> st;
    multiset <ll>::iterator UB;
public:
    void solve()
    {
        int n, x, y, i, num;
        ll ans;
        
        cin >> n >> x >> y;

        cin >> num;

        st.insert(num * ll(x));

        ans = 0;
        for(i = 1; i < n; ++i)
        {
            cin >> num;

            if(x == 0)
                continue;

            UB = upper_bound(st.begin(), st.end(), num*ll(y));

            ans += distance(UB, st.end());

            st.insert(num * ll(x));
        }

        cout << ans << '\n';

        st.clear();

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