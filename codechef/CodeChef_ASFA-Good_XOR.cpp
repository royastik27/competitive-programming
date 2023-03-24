/**
 * CodeChef ASFA - Good XOR
 * TIME: 0.01s
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    int n, zero, one, inc;
    bool bit;
public:
    int solve()
    {
        cin >> n;

        zero = one = 0;

        for(int i = 0; i < n; ++i)
        {
            cin >> bit;

            if(bit) ++one;
            else ++zero;
        }

        if(n & 1 || !one || (n == 2 && !zero))   // case: impossible
            return -1;

        if(one > zero)
        {
            inc = (one - zero) / 2;

            return inc / 2 + (inc & 1) * 2;
        }

        return (zero - one) / 2;
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