/**
 * Codeforces Round #294 (Div. 2)
 * Problem C - A and B and Team Training
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution{

public:
    int solve()
    {
        int n, m, ans = 0;

        cin >> n >> m;
        
        while(n && m)
        {
            if(n == 1 && m == 1) break;

            if(n > m)
            {
                n -= 2;
                --m;
            }
            else
            {
                m -= 2;
                --n;
            }

            ++ans;
        }       
        
        return ans;
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