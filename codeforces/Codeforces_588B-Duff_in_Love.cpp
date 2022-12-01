/**
 * Codeforces Round #326 (Div. 2)
 * Problem B - Duff in Love
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    ll solve()
    {
        ll n, ans = 1;
        int root, root2, i, j;
        
        cin >> n;

        root = sqrt(n);
        vector <bool> isPrime(root+1, 1);

        // seive
        root2 = sqrt(root);
        for(i = 3; i <= root2; i += 2)
        {
            if(isPrime[i])
            {
                for(j = i*i; j <= root; j += i+i)
                    isPrime[j] = false;
            }
        }
        
        // generating ans
        if(!(n & 1))
        {
            ans *= 2;

            while(!(n & 1))
                n /= 2;
        }
        
        for(i = 3; i <= root; i += 2)
        {
            if(isPrime[i] && (n % i == 0))
            {
                ans *= i;

                while(n % i == 0)
                    n /= i;
            }
        }

        return ans * n;
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