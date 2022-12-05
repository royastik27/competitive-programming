/**
 * Codeforces Round #306 (Div. 2)
 * Problem A - Two Substrings
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
 
using namespace std;

class Solution
{

public:
    bool solve()
    {
        int len, i;
        string str;

        cin >> str;

        len = str.length();

        if(len < 4) return false;

        vector <int> ab, ba;

        // For AB
        for(i = 1; i < len; ++i)
            if(str[i-1] == 'A' && str[i] == 'B')
                ab.push_back(i);

        // For BA
        for(i = 1; i < len; ++i)
            if(str[i-1] == 'B' && str[i] == 'A')
                ba.push_back(i);

        if(!ab.size() || !ba.size())
            return false;
        
        return abs(ab[0]-ba[ba.size()-1]) != 1 || abs(ab[ab.size()-1]-ba[0]) != 1;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    Solution sol;

    if(sol.solve()) cout << "YES\n";
    else cout << "NO\n";
 
    return 0;
}