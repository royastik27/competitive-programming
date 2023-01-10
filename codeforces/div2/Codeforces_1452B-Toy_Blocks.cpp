/**
 * Educational Codeforces Round 98 (Rated for Div. 2)
 * Problem B - Toy Blocks
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution
{
    int n, i, num, mx;
    ll sum;
public:
    ll solve()
    {
        cin >> n;

        mx = sum = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> num;

            sum += num;
            mx = max(mx, num);
        }

        return max(mx * ll(n-1), ll(ceil(sum / double(n-1))* (n-1))) - sum;
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