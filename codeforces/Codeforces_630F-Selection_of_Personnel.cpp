/**
 * Experimental Educational Round: VolBIT Formulas Blitz
 * Problem F - Selection of Personnel
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution {

    ll nCr(int n, int r)
    {
        ll ans = 1, fact = 1;
        int i, gcd;

        for(i = r; i > 1; --i) fact *= i;

        for(i = n; i > n-r; --i)
        {
            ans *= i;
            gcd = __gcd(ans, fact);
            ans /= gcd;
            fact /= gcd;
        }

        return ans / fact;
    }

public:
    ll solve()
    {
        int n;
        
        cin >> n;

        return nCr(n, 5) + nCr(n, 6) + nCr(n, 7);
    }
};

class Solution2
{
public:
    ll solve()
    {
        int n, i;
        ll ans = 0, temp = 1;

        cin >> n;

        for(i = 1; i <= 7; ++i)
        {            
            temp = temp * (n-i+1) / i;

            if(i >= 5 && i <= 7) ans += temp;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution2 sol;
    
    cout << sol.solve() << '\n';

    return 0;
}
