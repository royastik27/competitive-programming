/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    string str;
public:
    void solve()
    {
        int sz, pos, j;

        cin >> str;

        sz = str.length();

        prop_pos = sz;
        prop = 0; 

        for(i = sz - 1; i >= 0; --i)
        {
            if(str[i] < '5')
            {
                if(prop)
                {
                    ++str[i];
                    prop_pos = i + 1;
                    prop = 0;
                }
            }
            else
            {
                if(prop)
                {
                    if(str[i] == '9')
                        continue;
                    else
                    {
                        ++str[i];
                        prop_pos = i + 1;
                    }
                }
                else
                    ++prop;
            }
        }

        if(prop)
        {
            cout << 1;

            for(i = 0; i < sz; ++i)
                cout << '0';
            cout << '\n';
        }
        else
        {
            for(i = prop_pos; i < sz; ++i)
                str[i] = '0';

            cout << str << '\n';
        }

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