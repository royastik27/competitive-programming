/**
* Codeforces Round 324 (Div. 2)
* Problem B - Kolya and Tanya
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 1000000007

class Solution
{

public:
    void solve()
    {
        int n, i;
        ll all, invalid;

        cin >> n;

        all = 1;
        for(i = 0; i < n; ++i)
            all = all * 27 % MOD;

        invalid = 1;
        for(i = 0; i < n; ++i)
            invalid = invalid * 7 % MOD;

        cout << ((all - invalid + MOD) % MOD) << '\n';        

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}