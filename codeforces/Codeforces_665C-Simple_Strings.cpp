/**
 * Educational Codeforces Round 12
 * Problem C - Simple Strings
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {

    char check(char a, char b)
    {
        for(char ch = 'a'; ch <= 'z'; ++ch)
        {
            if(ch == a || ch == b)
                continue;

            return ch;
        }

        return '#';
    }

public:
    void solve()
    {
        string str;

        cin >> str;

        int i, sz = str.length();

        --sz;
        for(i = 1; i < sz; ++i)
        {
            if(str[i] == str[i-1])
                str[i] = check(str[i-1], str[i+1]);
        }

        if(str[sz] == str[sz-1])
            str[sz] = (str[sz-1] == 'a') ? 'b' : 'a';

        cout << str << '\n';

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