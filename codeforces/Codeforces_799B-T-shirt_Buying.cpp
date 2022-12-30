/**
 * Playrix Codescapes Cup (Codeforces Round #413, rated, Div. 1 + Div. 2)
 * Problem B - T-shirt buying
 * TIME: 327 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>
 
using namespace std;

#define LIM 200000

class Solution
{
    set < pair <int, int> > st[4];
    set < pair <int, int> >::iterator it;

    int price[LIM], front[LIM], back, n, i, m;
public:
    void solve()
    {
        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> price[i];

        for(i = 0; i < n; ++i)
            cin >> front[i];

        for(i = 0; i < n; ++i)
        {
            cin >> back;

            st[front[i]].insert({ price[i], back });

            if(front[i] != back)
                st[back].insert({ price[i], front[i] });
        }

        cin >> m;

        while(m--)
        {
            cin >> i;

            it = st[i].begin();

            if(it == st[i].end())
                cout << "-1 ";
            else
            {
                if(it->second != i)
                    st[it->second].erase(st[it->second].find({ it->first, i }));

                cout << it->first << ' ';

                st[i].erase(it);
            }
        }
        cout << '\n';      

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