/**
 * Educational Codeforces Round 89 (Rated for Div. 2)
 * Problem B - Shuffle
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution{

public:
    int solve()
    {
        int n, x, m, i, j, start, end;

        cin >> n >> x >> m;

        start = end = x;

        while(m--)
        {
            cin >> i >> j;

            if(max(start, i) <= end && min(end, j) >= start)
            {
                start = min(start, i);
                end = max(end, j);
            }
        }
        
        return end - start + 1;
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