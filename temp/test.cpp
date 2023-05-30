/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 10000010
// #define LIM 1000

class Solution
{
    vector <int> prime;
public:
    Solution()
    {
        int i, j;
        bool comp[LIM + 2];

        memset(comp, 0, sizeof(comp));

        for(i = 3; i*i <= LIM; i += 2)
        {
            for(j = i*i; j <= LIM; j += i+i)
                comp[j] = true;
        }

        prime.push_back(2);

        for(j = 3; j <= LIM; j += 2)
            if(!comp[j])
                prime.push_back(j);

        return;        
    }
    void solve()
    {
        ll n, temp;
        int i, cnt;

        cin >> n;

        ll ans = 1;
        temp = n;

        for(i = 0; ll(prime[i]) * prime[i] <= n && temp != 0 && i < prime.size(); ++i)
        {
            if(n % prime[i] == 0)
            {
                cnt = 0;

                while(temp % prime[i] == 0)
                {
                    temp /= prime[i];
                    ++cnt;
                }

                // cout << "cnt: " << cnt << "\n";

                ans = ans * (cnt + 1);
            }
        }

        if(temp > 1)
            ans *= 2;

        cout << ans << "\n";

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