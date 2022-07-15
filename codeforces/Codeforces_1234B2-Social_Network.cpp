/**
 * Codeforces Round #590 (Div. 3)
 * Problem B2 - Social Network (hard version)
 * Time: 249 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <list>
#include <set>

using namespace std;

class Solution
{
public:
    void solve()
    {
        int n, k, el;

        cin >> n >> k;

        list <int> ls;
        set <int> st;
        set <int>::iterator it;

        while(n--)
        {
            cin >> el;

            it = st.find(el);

            if(it == st.end())
            {
                if(ls.size() == k)
                {
                    // REMOVE LAST CHILD
                    st.erase(st.find(ls.back()));
                    ls.pop_back();
                }

                // ADD AT FRONTs
                st.insert(el);                
                ls.push_front(el);
            }
        }

        // PRINTING RESULT
        cout << ls.size() << '\n';
        for(list <int>::iterator it = ls.begin(); it != ls.end(); ++it)
            cout << *it << ' ';
        cout << '\n';

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