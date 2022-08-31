/**
 * Codeforces Round #817 (Div. 4)
 * Problem A - Spell Check
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    string name = "Timur";
public:
    Solution()
    {
        sort(name.begin(), name.end());
    }
    bool solve()
    {
        int n;
        string str;

        cin >> n >> str;
        sort(str.begin(), str.end());

        return (str == name);
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}