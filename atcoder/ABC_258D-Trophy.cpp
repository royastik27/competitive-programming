/**
 * AtCoder Beginner Contest 258
 * Problem D - Trophy
 * TIME: 47 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {
    
public:
    void solve()
    {
        int n, x, a, b;

        cin >> n >> x;

        long long int mn = INT64_MAX, sum = 0;

        while(n--)
        {
            cin >> a >> b;

            --x;
            sum += a + b;

            if(x >= 0)
                mn = min(mn, sum + (long long int)x * b);
        }

        cout << mn << '\n';

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