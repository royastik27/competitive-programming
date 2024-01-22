/**
* Codeforces Round 680 (Div. 2, based on Moscow Team Olympiad)
* Problem C - Division
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int ll;

#define QLIM 1000000000

class Solution
{
    ll p;
    int q;
    vector <int> prime;

    ll reduce(int prm)
    {
        ll p = this->p;
        int cnt;

        cnt = 0;
        while(q % prm == 0) {
            q /= prm;
            ++cnt;
        }

        while(p % prm == 0)
            p /= prm;

        --cnt;
        while(cnt--)
            p *= prm;

        return p;
    }
public:
    Solution()
    {
        // seive
        const int root = sqrt(QLIM) + 1000;
        ll i, j;
        bool comp[root+1];

        memset(comp, 0, sizeof(comp));

        for(i = 3; i*i <= root; i += 2)
            for(j = i*i; j <= root; j += i+i)
                comp[j] = true;

        prime.push_back(2);
        for(i = 3; i <= root; i += 2)
            if(!comp[i])
                prime.push_back(i);
        
        return;
    }
    void solve()
    {
        ll ans;
        int i;

        cin >> p >> q;

        if(p % q == 0) {
            ans = 0;
            // for every prime factor of q
            for(i = 0; (ll)prime[i]*prime[i] <= q; ++i)
                if(q % prime[i] == 0)
                    ans = max(ans, reduce(prime[i]));

            // last factor of q
            if(q > 1)
                ans = max(ans, reduce(q));
        }
        else ans = p;

        cout << ans << '\n';

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