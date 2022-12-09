/**
 * Codeforces Round #812 (Div. 2)
 * Problem C - Build Permutation
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define LIM 100000

class Solution
{
    vector <int> sqrs, ans;
    vector <int>::iterator UB;
    int n;
public:
    Solution()
    {
        int i, root = int(ceil(sqrt(LIM)));

        for(i = 0; i <= root; ++i)
            sqrs.push_back(i*i);

        return;
    }
    void solve()
    {
        int i, diff;

        cin >> n;

        --n;

        while(n >= 0)
        {
            UB = upper_bound(sqrs.begin(), sqrs.end(), n);

            if(*(--UB) != n)
                ++UB;

            diff = *UB - n;

            for(i = diff; i <= n; ++i)
                ans.push_back(i);

            n = diff - 1;
        }

        n = ans.size();
        for(i = n-1; i >= 0; --i)
            cout << ans[i] << ' ';
        cout << '\n';

        ans.clear();

        return;
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
        sol.solve();    

    return 0;
}