/**
 * Codeforces Round #613 (Div. 2)
 * Problem C - Fadi and LCM
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

typedef long long int ll;

class Solution
{
    vector <ll> prime, ans;
    ll n, x, y;

    void generate_prime(int lim)
    {
        vector <bool> comp(lim+1, 0);
        
        prime.push_back(2);
        int root = sqrt(lim), i, j;

        for(i = 3; i <= root; i += 2)
        {
            if(!comp[i])
                for(j = i*i; j <= lim; j += i+i)
                    comp[j] = true;
        }

        for(i = 3; i <= lim; i += 2)
            if(!comp[i]) prime.push_back(i);

        return;
    }

    void brute_force(int pos = 0, ll mul = 1)
    {
        if(pos == ans.size())
        {
            ll a = mul, b = n / mul;

            if(max(a, b) < max(x, y))
            {
                x = a;
                y = b;
            }
        }
        else
        {
            brute_force(pos+1, mul);
            brute_force(pos+1, mul*ans[pos]);
        }

        return;
    }
public:
    void solve()
    {
        int sz, i;
        ll temp, term;

        cin >> n;

        generate_prime(sqrt(n));

        sz = prime.size();
        temp = n;
        for(i = 0; i < sz; ++i)
        {
            term = 1;
            
            while(temp % prime[i] == 0)
            {
                term *= prime[i];
                temp /= prime[i];
            }

            if(term > 1) ans.push_back(term);
        }

        if(temp > 1) ans.push_back(temp);
        
        x = 1;
        y = n;

        brute_force();

        cout << x << ' ' << y << '\n';

        return;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();
 
    return 0;
}