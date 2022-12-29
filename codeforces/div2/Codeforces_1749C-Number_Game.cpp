/**
 * Educational Codeforces Round 138 (Rated for Div. 2)
 * Problem C - Number Game
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

class Solution
{
    multiset <int> st;
    multiset <int>::iterator it;
    int n, num, k;
public:
    int solve()
    {
        cin >> n;

        while(n--)
        {
            cin >> num;
            st.insert(num);
        }

        k = 0;

        if(*st.begin() == 1)
        {
            ++k;
            st.erase(st.begin());
        }

        while(st.size() && *st.begin() == 1)
        {
            st.erase(st.begin());

            if(st.size() && (it = st.upper_bound(k+1)) != st.begin())
            {
                --it;
                st.erase(it);
                ++k;
            }
            else break;
        }

        st.clear();

        return k;
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