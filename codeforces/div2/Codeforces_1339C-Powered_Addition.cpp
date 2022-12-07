/**
 * Codeforces Round #633 (Div. 2)
 * Problem C - Powered Addition
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 1000000000

class Solution
{
    vector <int> pow2, diff;
public:
    Solution()
    {
        int num = 1;

        pow2.push_back(num);

        while(num <= LIM)
        {
            num *= 2;
            pow2.push_back(num);
        }

        return;
    }
    int solve()
    {
        int n, prev, curr, d, ans = 0;
        
        cin >> n >> prev;

        --n;
        while(n--)
        {
            cin >> curr;

            d = prev - curr;

            if(d > 0)
            {
                diff.push_back(d);
                curr += d;
            }

            prev = curr;
        }

        n = diff.size();

        for(d = 0; d < n; ++d)
        {
            for(curr = 0; curr < pow2.size() && diff[d] >= pow2[curr]; ++curr);

            ans = max(ans, curr);
        }

        diff.clear();

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