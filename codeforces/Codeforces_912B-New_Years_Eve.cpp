/**
 * Codeforces Round #456 (Div. 2)
 * Problem B - New Year's Eve
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution{

public:
    ll solve()
    {
        ll n, k, ans = 0;

        cin >> n >> k;

        if(k == 1)
            return n;

        while(n)
        {
            ans = ans * 2 + 1;
            n /= 2;
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