/**
 * Codeforces Round #371 (Div. 2)
 * Problem C - Sonya and Queries
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

class Solution
{
    ll pattern(string str)
    {
        int i, len = str.length();
        ll pat = 0;

        for(i = 0; i < len; ++i)
            pat = pat * 10 + ((str[i]-'0') & 1);

        return pat;
    }
public:
    void solve()
    {
        int q;
        map <ll, int> mp;
        map <ll, int>::iterator it;
        ll pat;
        char op;
        string str;

        cin >> q;

        while(q--)
        {
            cin >> op;

            switch(op)
            {
                case '+':
                cin >> str;
                pat = pattern(str);
                ++mp[pat];
                break;

                case '-':
                cin >> str;
                pat = pattern(str);
                
                it = mp.find(pat);

                if(it->second == 1)
                    mp.erase(it);
                else --it->second;

                break;

                default:
                cin >> pat;
                cout << mp[pat] << '\n';
            }
        }

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