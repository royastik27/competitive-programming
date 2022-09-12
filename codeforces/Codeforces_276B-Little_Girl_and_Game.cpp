/**
 * Codeforces Round #169 (Div. 2)
 * Problem B - Little Girl and Game
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

class Solution {

public:
    bool solve()
    {
        string str;
        int odd, even, sum;
        map <char, int> mp;
        map <char, int>::iterator it;

        cin >> str;

        for(int i = 0; str[i] != '\0'; ++i)
            ++mp[str[i]];

        even = odd = 0;
        for(it = mp.begin(); it != mp.end(); ++it)
            if(it->second & 1) ++odd;
            else ++even;

        even += mp.size();

        return (odd < 2) || (even & 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    if(sol.solve()) cout << "First\n";
    else cout << "Second\n";
    
    return 0;
}