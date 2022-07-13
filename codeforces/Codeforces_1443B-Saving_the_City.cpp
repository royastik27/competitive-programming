/**
 * Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
 * Problem B - Saving the City
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
        int n, len, i, ans = 0, a, b;
        string str;

        cin >> a >> b >> str;
        len = str.length();

        int cnt = 1000;
        for(i = 0; i < len; ++i)
        {
            if(str[i] == '1')
            {
                if(cnt)
                {
                    if(cnt * b < a) ans += cnt * b;
                    else ans += a;

                    cnt = 0;
                }
            }
            else ++cnt;
        }

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