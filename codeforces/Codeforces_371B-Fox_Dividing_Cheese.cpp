/**
 * Codeforces Round #218 (Div. 2)
 * Problem B - Fox Dividing Cheese
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

class Solution{

public:
    int solve()
    {
        int a, b, div[3] = { 2, 3, 5 }, i, curr, mn, diff, temp, ans = 0, cnt1, cnt2;

        cin >> a >> b;

        for(i = 0; i < 3; ++i)
        {
            curr = div[i];
            cnt1 = cnt2 = 0;

            temp = a;
            while(temp % curr == 0)
            {
                ++cnt1;
                temp /= curr;
            }

            temp = b;
            while(temp % curr == 0)
            {
                ++cnt2;
                temp /= curr;
            }

            mn = min(cnt1, cnt2);

            // for a
            diff = abs(cnt1-mn);
            ans += diff;

            while(diff--)
                a /= curr;

            // for b
            diff = abs(cnt2-mn);
            ans += diff;

            while(diff--)
                b /= curr;
        }        

        return (a == b) ? ans : -1;
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