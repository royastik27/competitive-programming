/**
 * Codeforces Round #784 (Div. 4)
 * Problem H - Maximal AND
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define LIM 31

class Solution
{
    int bits[LIM];
    vector < pair<int, int> > to_bit;
public:
    int solve()
    {
        int n, k, num, i, j, ans = 0, diff;
        memset(bits, 0, sizeof(bits));

        cin >> n >> k;

        for(i = 0; i < n; ++i)
        {
            cin >> num;

            for(j = 0; j < LIM; ++j)
                bits[j] += bool(num & (1 << j));
        }

        for(i = 0; i < LIM; ++i)
        {
            diff = n - bits[i];

            if(!diff)
                ans |= (1 << i);
            else if(diff <= k)
                to_bit.push_back({i, diff});
        }

        n = to_bit.size();

        for(i = n-1; i >= 0; --i)
        {
            if(to_bit[i].second > k)
                continue;

            ans |= (1 << to_bit[i].first);
            k -= to_bit[i].second;
        }

        to_bit.clear();
        
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