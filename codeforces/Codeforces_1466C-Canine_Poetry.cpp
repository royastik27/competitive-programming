/**
 * Good Bye 2020
 * Problem 1466C - Canine poetry
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    public:
    int solve()
    {
        string str;
        int len, i, cnt = 0;

        cin >> str;
        len = str.length();

        if(len > 1 && str[1] == str[0]) { str[1] = '*'; ++cnt; }

        for(i = 2; i < len; ++i)
        {
            if(str[i] == str[i-1] || str[i] == str[i-2])
                { str[i] = '*'; ++cnt; }
        }
        
        return cnt;
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