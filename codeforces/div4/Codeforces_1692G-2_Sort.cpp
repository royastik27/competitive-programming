/**
 * Codeforces Round #799 (Div. 4)
 * Problem G - 2^Sort
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    int n, k, prev, num, ans, i, j;
public:
    int solve()
    {
        cin >> n >> k >> prev;

        i = ans = 0;

        for(j = 1; j < n; ++j)
        {
            cin >> num;

            if(num * 2 <= prev) // if not OK
            {
                ans += max(j - i - k, 0);
                i = j;
            }

            prev = num;
        }

        return ans + max(j - i - k, 0);
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