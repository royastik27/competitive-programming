/**
 * Codeforces Round #401 (Div. 2)
 * Problem B - Game of Credit Cards
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {

public:
    void solve()
    {
        string str1, str2;
        int n, i, j, mp[10] = {}, mp2[10] = {}, ans1 = 0, ans2 = 0, idx;

        cin >> n >> str1 >> str2;

        for(i = 0; i < n; ++i)
        {
            idx = int(str2[i] - '0');
            ++mp[idx]; ++mp2[idx];
        }

        // 1st case
        for(i = 0; i < n; ++i)
        {
            for(j = int(str1[i]-'0'); j < 10; ++j)
                if(mp[j]) break;

            if(j < 10)
                { --mp[j]; ++ans1; }
        }
        ans1 = n - ans1;

        // 2nd case
        for(i = 0; i < n; ++i)
        {
            for(j = int(str1[i]-'0') + 1; j < 10; ++j)
                if(mp2[j]) break;

            if(j < 10)
                { --mp2[j]; ++ans2; }
        }

        cout << ans1 << '\n' << ans2 << '\n';
        
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
