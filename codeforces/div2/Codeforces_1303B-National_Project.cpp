/**
 * Educational Codeforces Round 82 (Rated for Div. 2)
 * Problem B - National Project
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution {
    int n, g, b, half, full;
public:
    ll solve()
    {
        cin >> n >> g >> b;

        half = ceil(n / 2.0);
        full = ceil(half / double(g)) - 1;

        return half - (full*g) + max(n - half - ll(full)*b, 0LL) + full * ll(g+b);
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
        cout << sol.solve() << '\n';
 
    return 0;
}