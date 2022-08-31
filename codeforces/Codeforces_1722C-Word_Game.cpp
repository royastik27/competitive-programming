/**
 * Codeforces Round #817 (Div. 4)
 * Problem C - Word Game
 * TIME: 108 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    map <string, vector <int> > mp;
    map <string, vector <int> >::iterator it;
public:
    void solve()
    {
        int mark[3] = {0}, n, i, j;
        string str;

        cin >> n;

        for(i = 0; i < 3; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cin >> str;

                mp[str].push_back(i);
            }
        }

        int sz;
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            sz = it->second.size();

            if(sz == 1)
                mark[it->second[0]] += 3;
            else if(sz == 2)
                { ++mark[it->second[0]]; ++mark[it->second[1]]; }
        }

        cout << mark[0] << ' ' << mark[1] << ' ' << mark[2] << '\n';

        mp.clear();
        
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