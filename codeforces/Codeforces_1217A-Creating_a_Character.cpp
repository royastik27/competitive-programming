/**
 * Educational Codeforces Round 72 (Rated for Div. 2)
 * Problem A - Creating a Character
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{

public:
    int solve()
    {
        int str, intel, exp, x;

        cin >> str >> intel >> exp;

        if(str + exp <= intel) return 0;

        return min(int(ceil((str + exp - intel) / 2.0)), exp + 1);
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