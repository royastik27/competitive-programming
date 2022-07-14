/**
 * Codeforces Round #694 (Div. 1)
 * Problem A - Strange Birthday Party
 * Number 10th Solution of Codeforces with C++ 14 (Sorting by time in ascending order)
 * Time: 155 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define LIM 300000

class Solution
{
    int mp[LIM + 1], cost[LIM];
public:
    long long int solve()
    {
        long long int ans = 0;
        int n, m, i, el;

        // INPUT
        cin >> n >> m;
        memset(mp, 0, sizeof(mp));

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            ++mp[el];
        }
        for(i = 0; i < m; ++i) cin >> cost[i];

        // GETTING ANS
        int k = 0, j, mn, cnt;

        for(i = m; i >=1; --i)
        {
            if(k < i)
            {
                mn = min(i - k - 1, mp[i]);

                for(j = 0; j < mn; ++j) { ans += cost[k++]; --mp[i];; }
            }

            ans += (long long int)mp[i] * cost[i - 1];
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