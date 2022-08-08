/**
 * Codeforces Round #273 (Div. 2)
 * Problem B - Random Teams
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {   
    
public:
    void solve()
    {
        int n, m;

        cin >> n >> m;

        long long int quo = n / m;
        int rem = n % m;

        long long int min = rem * (quo+1) * quo / 2;
        min += (m - rem) * quo * (quo - 1) / 2;
        long long int max = (long long int)(n-m) * (n-m + 1) / 2;

        cout << min << ' ' << max << '\n';
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