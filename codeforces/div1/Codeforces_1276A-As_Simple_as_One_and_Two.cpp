/**
 * Codeforces Round #606 (Div. 1, based on Technocup 2020 Elimination Round 4)
 * Problem A - As Simple as One and Two
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int len, n, i;
    string str;
    vector <int> ans;
public:
    void solve()
    {
        cin >> str;

        len = str.length();

        n = len - 1;
        for(i = 1; i < n; ++i)
        {
            if(str[i] == 'n' && str[i-1] == 'o' && str[i+1] == 'e')
                ans.push_back(i+1);
            else if(str[i] == 'w' && str[i-1] == 't' && str[i+1] == 'o')
            {
                if(i+3 < len && str[i+2] == 'n' && str[i+3] == 'e')
                {
                    ans.push_back(i+2);
                    i += 3;
                }
                else ans.push_back(i+1);
            }
        }

        n = ans.size();
        cout << n << '\n';
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        ans.clear();     

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