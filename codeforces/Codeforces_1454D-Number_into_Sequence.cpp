/**
 * Codeforces Round #686 (Div. 3)
 * Problem D - Number into Sequence
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ll;

#define LIM 100000

class Solution{
    vector <int> prime;
public:
    Solution()
    {
        int i, j, root = sqrt(LIM);
        bool isPrime[LIM + 1];
        
        for(i = 3; i <= LIM; i += 2) isPrime[i] = true;

        prime.push_back(2);

        for(i = 3; i <= root; i += 2)
        {
            if(isPrime[i])
            {
                for(j = 3*i; j <= LIM; j += i+i)
                    isPrime[j] = false;
            }
        }

        for(i = 3; i <= LIM; i += 2)
            if(isPrime[i]) prime.push_back(i);

        return;
    }

    void solve()
    {
        ll n, temp;
        int mx, i, root, cnt, mxPrime;

        cin >> n;
        temp = n;
        root = sqrt(n);

        mx = 1;
        for(i = 0; temp > 1 && prime[i] <= root; ++i)
        {
            cnt = 0;
            while(temp % prime[i] == 0)
            {
                ++cnt;
                temp /= prime[i];
            }

            if(cnt > mx)
            {
                mx = cnt;
                mxPrime = prime[i];
            }
        }

        if(mx == 1)
            cout << "1\n" << n << '\n';
        else
        {
            cout << mx << '\n';
            temp = 1;

            for(i = 1; i < mx; ++i)
            {
                cout << mxPrime << ' ';
                temp *= mxPrime;
            }

            cout << n / temp << '\n';
        }

        return;
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