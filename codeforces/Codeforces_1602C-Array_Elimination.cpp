/**
 * Codeforces Round #751 (Div. 2)
 * Problem C - Array Elimination
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define LIM 200000

class Solution{
    int bits[30];
    vector <int> ans;

    void get_bits(int n)
    {
        for(int i = 0; i < 30; ++i)
            if(n & (1 << i))
                ++bits[i];

        return;
    }
public:
    void solve()
    {
        int n, i, gcd, el;
        memset(bits, 0, sizeof(bits));

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            get_bits(el);
        }

        gcd = 0;

        for(i = 0; i < 30; ++i)
            gcd = __gcd(gcd, bits[i]);

        if(gcd)
        {
            for(i = 1; i*i < gcd; ++i)
            {
                if(gcd % i == 0)
                {
                    ans.push_back(i);
                    ans.push_back(gcd / i);
                }
            }

            if(i*i == gcd) ans.push_back(i);

            sort(ans.begin(), ans.end());
            int sz = ans.size();
            
            for(i = 0; i < sz; ++i) cout << ans[i] << ' ';
            cout << '\n';

            ans.clear();
        }
        else
        {
            for(i = 1; i <= n; ++i) cout << i << ' ';
            cout << '\n';
        }
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