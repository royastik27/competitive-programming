/**
 * Codeforces Round #572 (Div. 2)
 * Problem C - Candies!
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    void solve()
    {
        int n, q, num, i, j;

        cin >> n;

        vector <int> pre(n+1);

        for(i = 1; i <= n; ++i)
        {
            cin >> num;
            pre[i] = pre[i-1] + num;
        }

        cin >> q;

        while(q--)
        {
            cin >> i >> j;

            cout << ((pre[j] - pre[i-1]) / 10) << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}