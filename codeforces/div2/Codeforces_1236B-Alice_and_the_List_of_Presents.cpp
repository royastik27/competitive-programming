/**
* Codeforces Round 593 (Div. 2)
* Problem B - Alice and the List of Presents
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 1000000007

class Solution
{
    int power(int b, int p)
    {
        if(!p)
            return 1;
        else if(p & 1)
            return (ll)b * power(b, p-1) % MOD;
        else
            return power((ll)b * b % MOD, p/2);
    }
public:
    void solve()
    {
        int n, m;

        cin >> n >> m;

        cout << power(power(2, m) - 1, n) << '\n';

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