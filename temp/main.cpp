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

        for(pos = sz - 1; pos >= 0; --pos)
        {
            if(str[pos] < '5')
                continue;

            for(j = pos - 1; j >= 0; --j)
            {
                if(str[j] < '9')
                    break;
            }

            if(j < 0)
            {
                str = "1";

                for(j = 0; j < sz; ++j) 
                    str.push_back('0');
            }
            else
            {
                ++str[j];

                i = j;

                for(j = j + 1; j < sz; ++j)
                    str[j] = '0';
            }
        }

        cout << str << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    while(TC--)
        sol.solve();

    return 0;
}