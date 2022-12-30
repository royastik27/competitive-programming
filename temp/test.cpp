/**
 * Educational Codeforces Round 79 (Rated for Div. 2)
 * Problem C - Stack of Presents
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

class Solution
{

public:
    void solve()
    {
        set <int> st;

        st.insert(10);
        st.insert(5);
        st.insert(13);
        st.insert(3);
        st.insert(65);

        for(auto it = st.begin(); it != st.end(); ++it)
            st.erase(it);
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