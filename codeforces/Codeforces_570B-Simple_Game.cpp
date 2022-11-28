/**
 * Codeforces Round #316 (Div. 2)
 * Problem B - Simple Game
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
        int n, m, mid;

        cin >> n >> m;

        if(n == 1) return 1;

        mid = (1+n) / 2;
        
        if((m > mid) || (n & 1 && m == mid))
            return m-1;
        
        return m+1;
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