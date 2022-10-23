/**
 * LightOJ 1005 - Rooks
 * TIME: 5 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
 
using namespace std;

typedef long long int ll;
 
class Solution {    

public:
    ll solve()
    {
        int n, k;

        cin >> n >> k;

        if(k > n) return 0;
        
        ll ans = 1, i, fact = 1, gcd;

        for(i = k; i >= 2; --i) fact *= i;

        for(i = 0; i < k; ++i, --n)
        {
            gcd = __gcd(fact, (ll)n*n);

            ans *= n*n / gcd;
            fact /= gcd;
        }
        
        return ans * fact;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Solution sol;
    int TC, k = 0;

    cin >> TC;

    while(TC--)
        cout << "Case " << ++k << ": " << sol.solve() << '\n';
    
    return 0;
}