/**
 * Codeforces Round #677 (Div. 3)
 * Problem E - Two Round Dances
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

typedef long long int ll;
 
class Solution {

    ll nCr(int n, int r)
    {
        ll ans = 1;

        int i;
        for(i = n; i > r; --i) ans *= i;

        for(i = n - r; i > 1; --i) ans /= i;

        return ans;
    }

    int fact(int n)
    {
        int ans = 1;
        for(int i = n; i > 1; --i) ans *= i;
        return ans;
    }
public:
    ll solve()
    {
        ll ans, i, n, temp;

        cin >> n;

        ans = nCr(n, n/2) / 2;
        temp = fact(n/2 - 1);

        ans *= temp * temp;

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