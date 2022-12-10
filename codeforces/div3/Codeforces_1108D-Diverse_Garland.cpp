/**
 * Codeforces Round #535 (Div. 3)
 * Problem D - Diverse Garland
 * Simpler than the editorial
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;
 
class Solution
{

public:
    void solve()
    {
        int n, i, j, cnt;
        string str;
        char ch[3] = { 'R', 'G', 'B' };

        cin >> n >> str;

        str[n] = 'R';
        cnt = 0;

        for(i = 1; i < n; ++i)
        {
            if(str[i] == str[i-1])
            {
                ++cnt;

                for(j = 0; j < 3; ++j)
                    if(str[i-1] != ch[j] && str[i+1] != ch[j])
                    {
                        str[i] = ch[j];
                        break;
                    }
            }
        }

        str[n] = '\0';

        cout << cnt << '\n' << str << '\n';
 
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