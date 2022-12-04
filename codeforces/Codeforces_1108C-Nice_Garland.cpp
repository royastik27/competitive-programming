/**
 * Codeforces Round #535 (Div. 3)
 * Problem C - Nice Garland
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    string comb[6] = { "RGB", "RBG", "GRB", "GBR", "BRG", "BGR" };
public:
    void solve()
    {
        int n, ans = 0, i, j, cnt, mn_pos;
        string str;

        cin >> n >> str;

        if(n == 2 && str[0] == str[1])
        {
            ++ans;

            str[1] = (str[0] == 'R') ? 'G' : 'R';
        }
        else if(n > 2)
        {
            ans = n;

            for(i = 0; i < 6; ++i)
            {
                cnt = 0;

                for(j = 0; j < n; ++j)
                    if(str[j] != comb[i][j%3])
                        ++cnt;

                if(cnt < ans)
                {
                    ans = cnt;
                    mn_pos = i;
                }
            }

            for(i = 0; i < n; ++i)
                str[i] = comb[mn_pos][i%3];
        }

        cout << ans << '\n' << str << '\n';
        
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