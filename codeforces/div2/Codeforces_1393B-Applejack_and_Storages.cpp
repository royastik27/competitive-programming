/**
 * Codeforces Round #662 (Div. 2)
 * Problem B - Applejack and Storages
 * TIME: 124 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

#define LIM 100001

class Solution
{
    int n, num, curr, freq[LIM];
    multiset <int> st;
    multiset <int>::iterator it;
    char op;

    bool check()
    {
        if(st.empty()) return false;

        it = --st.end();

        if(*it >= 8)
            return true;

        if(*it < 4)
            return false;

        int last;
        if(st.size() > 1)
        {
            last = *it;
            --it;

            if((*it >= 4) || (last >= 6 && *it >= 2))
                return true;
        }

        if(st.size() > 2)
        {
            last = *it;
            --it;

            if(last >= 2 && *it >= 2)
                return true;
        }

        return false;
    }
public:
    void solve()
    {
        cin >> n;

        memset(freq, 0, sizeof(freq));

        while(n--)
        {
            cin >> num;
            ++freq[num];
        }

        for(int i = 1; i < LIM; ++i)
            if(freq[i]) st.insert(freq[i]);

        cin >> n;

        while(n--)
        {
            cin >> op >> num;

            curr = freq[num];

            if(curr)
                st.erase(st.find(curr));

            if(op == '+')
            {
                ++curr;
                ++freq[num];
            }
            else
            {
                --curr;
                --freq[num];
            }

            if(curr) st.insert(curr);

            if(check()) cout << "YES\n";
            else cout << "NO\n";
        }

        st.clear();        

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