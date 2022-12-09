/**
 * Codeforces Round #608 (Div. 2)
 * Problem B - Blocks
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution
{
    int n;
    string str;
    vector <int> ans;

    bool check(char ch)
    {
        int i;
        string temp = str;

        for(i = 0; i < n-1; ++i)
        {
            if(temp[i] != ch)
            {
                ans.push_back(i+1);
                
                if(temp[i+1] != ch)
                {
                    temp[i+1] = ch;
                    ++i;
                }
                else
                    temp[i+1] = temp[i];
            }
        }

        if(temp[n-1] == ch)
            return true;

        ans.clear();

        return false;
    }

    void printAns()
    {
        int i, sz = ans.size();

        cout << sz << '\n';

        for(i = 0; i < sz; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
public:
    void solve()
    {
        cin >> n >> str;

        if(check('W') || check('B'))
            printAns();
        else cout << "-1\n";
        
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