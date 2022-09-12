/**
 * Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
 * Problem C - Jatayu's Balanced Bracket Sequence
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

class Solution {
    map <int, vector <int> > mp;
    map <int, vector <int> >::iterator it;
public:
    void solve()
    {
        string str;
        int i, n;

        cin >> str;
        n = str.length();

        for(i = 0; i < n; ++i)
            mp[str[i] - 'a' + 1].push_back(i+1);

        it = mp.find(str[0] - 'a' + 1);

        int cost = 0, sz, curr, last;
        last = str[n-1] - 'a' + 1;
        vector <int> ans;
        ans.push_back(1);

        if(str[0] - 'a' + 1 < last)
        {
            // go upward
            while(it != mp.end())
            {
                if(it->first > last) break;

                sz = it->second.size();

                for(i = 0; i < sz; ++i)
                {
                    curr = it->second[i];

                    if(curr == 1 || curr == n) continue;
                    
                    cost += abs(str[ans[ans.size() - 1] - 1] - str[curr-1]);
                    ans.push_back(curr);
                }

                ++it;
            }
        }
        else
        {
            // go downward
        }

        cost += abs(str[ans[ans.size() - 1] - 1] - str[ans[ans.size() - 2] - 1]);
        ans.push_back(n);
        
        cout << cost << ' ' << ans.size() << '\n';
        for(i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        mp.clear();

        return;        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)    
        sol.solve();
    
    return 0;
}