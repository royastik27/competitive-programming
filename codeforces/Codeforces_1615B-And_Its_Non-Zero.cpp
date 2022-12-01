/**
 * Codeforces Global Round 18
 * Problem B - And It's Non-Zero
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200000
#define BITLIM 18

class Solution
{
    int bits[LIM+1][BITLIM];
public:
    Solution()
    {
        int i, j;

        for(i = 0; i < BITLIM; ++i) bits[0][i] = 0;

        for(i = 1; i <= LIM; ++i)
        {
            for(j = 0; j < BITLIM; ++j)
                bits[i][j] = bits[i-1][j] + bool(i & (1 << j));
        }

        return;
    }
    int solve()
    {
        int left, right, mx = 0, i;

        cin >> left >> right;

        for(i = 0; i < BITLIM; ++i)
            mx = max(mx, bits[right][i]-bits[left-1][i]);

        return right - left + 1 - mx;
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