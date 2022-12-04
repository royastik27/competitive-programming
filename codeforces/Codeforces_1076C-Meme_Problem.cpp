/**
 * Educational Codeforces Round 54 (Rated for Div. 2)
 * Problem C - Meme Problem
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Solution
{

public:
    void solve()
    {
        int n;
        double d;

        cin >> n;

        d = n*n - 4*n;

        if(d < 0)
            cout << "N\n";
        else
        {
            d = sqrt(d);

            cout << "Y " << ((n+d)/2.0) << ' ' << ((n-d)/2.0) << '\n';        
        }
        
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}