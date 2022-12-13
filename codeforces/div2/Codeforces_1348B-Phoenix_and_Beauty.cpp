/**
 * Codeforces Round #638 (Div. 2)
 * Problem B - Phoenix and Beauty
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
class Solution
{
    set <int> st;
    set <int>::iterator it;
    vector <int> ans;
    int n, k;
public:
    void solve()
    {
        cin >> n >> k;

        int num, i, j;
        for(i = 0; i < n; ++i)
        {
            cin >> num;
            st.insert(num);
        }

        if(st.size() > k)
            cout << "-1\n";
        else
        {
            for(it = st.begin(); it != st.end(); ++it)
                ans.push_back(*it);

            while(ans.size() < k)
                ans.push_back(ans[ans.size()-1]);

            cout << (n*k) << '\n';
            for(i = 0; i < n; ++i)
            {
                for(j = 0; j < k; ++j)
                    cout << ans[j] << ' ';
            }
            cout << '\n';
        }

        st.clear();
        ans.clear();       
 
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