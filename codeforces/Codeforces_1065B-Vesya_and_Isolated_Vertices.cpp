/**
 * Educational Codeforces Round 52 (Rated for Div. 2)
 * Problem B - Vasya and Isolated Vertices
 * Ranked at the top page among all submissions (Sorted by consumed time ascending)
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution {

public:
    void solve()
    {
        int n;
        ll m;

        cin >> n >> m;

        if(m > n/2)
            cout << 0 << ' ';
        else cout << n - 2*m << ' ';

        if(!m) cout << n << '\n';
        else
        {
            ll low = 1, high = 1;
            int node = 2, diff = 0;

            while(m > high)
            {
                low = high + 1;
                high = low + ++diff;
                ++node;
            }

            cout << n - node << '\n';
        }

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