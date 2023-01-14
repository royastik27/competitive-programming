/**
 * Codeforces Round #108 (Div. 2)
 * Problem C - Pocket Book
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
 
using namespace std;

typedef long long int ll;

#define MOD 1000000007
 
class Solution {

public:
    int solve()
    {
        int n, m, i, j, cnt;
        char ch;
        bool mp[100][26];
        ll ans = 1;

        cin >> n >> m;

        memset(mp, 0, m*26);

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                cin >> ch;
                mp[j][ch-'A'] = true;
            }
        }

        for(i = 0; i < m; ++i)
        {
            cnt = 0;
            for(j = 0; j < 26; ++j)
                cnt += mp[i][j];

            ans = ans * cnt % MOD;
        }
 
        return ans;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    Solution sol;
   
    cout << sol.solve() << '\n';
 
    return 0;
}