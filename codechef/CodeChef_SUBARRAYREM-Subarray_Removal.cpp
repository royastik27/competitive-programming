/**
 * CodeChef SUBARRAYREM - Subarray Removal
 * TIME: 0.02s
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{

public:
    int solve()
    {
        int n, ans, one, zero;
        bool bin;

        cin >> n;

        one = zero = 0;
        while(n--)
        {
            cin >> bin;

            if(bin) ++one;
            else ++zero;
        }

        ans = min(one, zero);

        one -= ans;

        ans += one/3;        

        return ans;
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