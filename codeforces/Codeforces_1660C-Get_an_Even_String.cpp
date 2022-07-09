/**
 * Codeforces Round #780 (Div. 3)
 * Problem C - Get an Even String
 * Time: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

class Solution
{
    public:
    int solve()
    {
        int ans = 0, i;
        string str;
        set <char> s;
        pair < set <char>::iterator, bool > check;

        cin >> str;

        int len = str.length();
        for(i = 0; i < len; ++i)
        {
            check = s.insert(str[i]);
            if(!check.second)
            {
                ans += s.size() - 1;
                s.clear();
            }
        }

        ans += s.size();
        
        return ans;
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