/**
 * Codeforces Round #287 (Div. 2)
 * Problem B - Amr and Pins
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
 
using namespace std;

typedef long long int ll;

class Solution
{

public:
    int solve()
    {
        int r, x1, y1;
        ll x, y, dis;

        cin >> r >> x >> y >> x1 >> y1;

        x = x - x1;
        y = y - y1;
        dis = ceil(sqrt(x*x + y*y));

        return ceil(dis / 2.0 / r);
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