/**
 * Codeforces Round #579 (Div. 3)
 * Problem C - Common Divisors
 * TIME: 156 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    int solve()
    {
        int n, root, ans = 0;
        ll gcd = 0, i;

        cin >> n;

        while(n--)
        {
            cin >> i;
            gcd = __gcd(gcd, i);
        }

        root = sqrt(gcd);
        for(i = 1; i <= root; ++i)
        {
            if(gcd % i == 0)
            {
                if(i == gcd / i)
                    ++ans;
                else ans += 2;
            }
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