/**
 * Codeforces Round #691 (Div. 2)
 * Problem B - Move and Turn
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{

public:
    int solve()
    {
        int n;
        
        cin >> n;

        if(n & 1)
            return (n+1)*(n+3)/2;

        int ans = n/2;
        ans = (ans+1)*(ans+1);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';

    return 0;
}