/**
 * Codeforces Round #771 (Div. 2)
 * Problem C - Inversion Graph
 * Time: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int solve()
    {
        int n, mx, el, ans = 1;

        cin >> n >> el;

        stack <int> st;
        st.push(el);

        for(int i = 1; i < n; ++i)
        {
            cin >> el;

            if(el > st.top()) st.push(el);
            else
            {
                mx = st.top();

                while(!st.empty() && el < st.top())
                    st.pop();

                st.push(mx);
            }
        }

        return st.size();
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