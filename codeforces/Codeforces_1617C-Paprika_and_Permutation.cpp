/**
 * Codeforces Round #761 (Div. 2)
 * Problem C - Paprika and Permutation
 * TIME: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

#define LIM 100000

class Solution
{
    multiset <int> st;
    multiset <int>::iterator it;

    bool vis[LIM+1];
public:
    int solve()
    {
        int n, num, ans = 0, i;

        cin >> n;
        memset(vis, 0, n+1);

        for(i = 0; i < n; ++i)
        {
            cin >> num;

            if(num > n || vis[num])
                st.insert(num);
            else vis[num] = true;
        }

        for(i = 1; i <= n; ++i)
        {
            if(vis[i]) continue;

            if((it = st.lower_bound(i*2 + 1)) != st.end())
            {
                st.erase(it);
                ++ans;
            }
            else
            {
                ans = -1;
                break;
            }
        }

        st.clear();

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