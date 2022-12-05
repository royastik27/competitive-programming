/**
 * Codeforces Round #306 (Div. 2)
 * Problem C - Divisibility by Eight
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
        string str;
        int num, ans = -1, len, i, j, k;

        cin >> str;
        len = str.length();

        // 1 digit
        for(i = 0; i < len; ++i)
            if((num = int(str[i] - '0')) % 8 == 0)
            {
                ans = num;
                break;
            }
        
        // 2 digit
        if(ans == -1)
        {
            for(i = 0; i < len; ++i)
                for(j = i+1; j < len; ++j)
                {
                    num = int(str[i] - '0')*10 + int(str[j] - '0');

                    if(num % 8 == 0)
                    {
                        ans = num;
                        break;
                    }
                }
        }

        // 3 digit
        if(ans == -1)
        {
            for(i = 0; i < len; ++i)
            {
                for(j = i+1; j < len; ++j)
                {
                    for(k = j+1; k < len; ++k)
                    {
                        num = int(str[i] - '0')*100 + int(str[j] - '0')*10 + int(str[k] - '0');

                        if(num % 8 == 0)
                        {
                            ans = num;
                            break;
                        }
                    }
                }
            }
        }

        if(ans == -1) cout << "NO\n";
        else
            cout << "YES\n" << ans << '\n';

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