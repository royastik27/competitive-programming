/**
 * Educational Codeforces Round 77 (Rated for Div. 2)
 * Problem B - Obtain Two Zeroes
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    int a, b;
public:
    bool solve()
    {
        cin >> a >> b;

        if(!a ^ !b) return false;

        int x = 2*a - b;

        return (x % 3) == 0 && (x = x / 3) >= 0 && 2*x <= a;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";

    return 0;
}