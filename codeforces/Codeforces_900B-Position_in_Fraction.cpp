/**
 * Codeforces Round #450 (Div. 2)
 * Problem B - Position in Fraction
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100000

class Solution{

public:
    int solve()
    {
        int a, b, c, pos, res, rem;
        bool vis[LIM] = {};

        cin >> a >> b >> c;

        pos = 0;

        for(int i = 0; i < b; ++i)
        {
            a *= 10;
            ++pos;

            res = a / b;

            if(res == c) return pos;

            while(!res)
            {
                a *= 10;
                ++pos;
                res = a / b;
            }

            if(res == c) return pos;

            rem = a - b*res;

            if(rem == 0) break;
            if(vis[rem]) break;

            vis[rem] = true;

            a = rem;
        }
        
        return (!c && !rem) ? pos + 1 : -1;
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