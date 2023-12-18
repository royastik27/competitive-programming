/**
* Codeforces Round 674 (Div. 3)
* Problem D - Non-zero Segments
* TIME: 124 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, i, el, ans;
        ll sum;
        set <ll> st;
        pair < set<ll>::iterator, bool > check;

        cin >> n;

        ans = sum = 0;
        st.insert(0);

        for(i = 0; i < n; ++i)
        {
            cin >> el;

            sum += el;
            
            check = st.insert(sum);

            if(!check.second) { // not inserted
                st.clear();
                st.insert(0);
                st.insert(el);
                sum = el;

                ++ans;
            }
        }

        cout << ans << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}