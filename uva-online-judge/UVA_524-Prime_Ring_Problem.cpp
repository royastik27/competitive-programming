/**
 * UVA 524 - Prime Ring Problem
 * RANK: 1737 out of 20441
 * TIME: 0.140 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define PLIM 32
#define LIM 17

class Solution {
    bool isPrime[PLIM], mp[LIM];
    int ans[LIM], n;

    void generate(int state)
    {
        if(state == n)
        {
            // PRINTING RESULT
            int sum = ans[state - 1] + 1;

            if(isPrime[sum])
            {
                for(int i = 0; i < n-1; ++i)
                    cout << ans[i] << ' ';

                cout << ans[n-1] << '\n';
            }

            return;
        }

        int sum;

        for(int i = 2; i <= n; ++i)
        {
            sum = ans[state-1] + i;

            if(!mp[i] && isPrime[sum])
            {
                ans[state] = i;

                mp[i] = true;
                generate(state + 1);
                mp[i] = false;
            }
        }

        return;
    }
public:
    Solution()
    {
        ans[0] = 1;

        // GENERATING PRIMES
        int i;

        memset(isPrime, 0, sizeof(isPrime));

        isPrime[2] = true;
        for(i = 3; i < PLIM; i += 2) isPrime[i] = true;

        // multiples of 3
        for(i = 6; i < PLIM; i += 3) isPrime[i] = false;

        // multiples of 5
        for(i = 10; i < PLIM; i += 5) isPrime[i] = false;

        return;
    }
    void solve(int n)
    {
        memset(mp, 0, (n+1)*sizeof(bool));
        this->n = n;

        generate(1);

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int n, k = 0;

    while(cin >> n)
        { if(k) cout << '\n'; cout << "Case " << ++k << ":\n"; sol.solve(n); }
    
    return 0;
}