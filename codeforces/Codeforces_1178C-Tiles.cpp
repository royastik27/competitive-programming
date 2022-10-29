/**
 * Codeforces Global Round 4
 * Problem C - Tiles
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 998244353

class Solution {

public:
    int solve()
    {
        int weight, height, n, ans = 4;

        cin >> weight >> height;

        n = weight + height - 2;
        
        while(n--)
            ans = ans * 2 % MOD;
        
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
