/**
 * Codeforces Round #655 (Div. 2)
 * Problem B - Omkar and Last Class of Math
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    void solve()
    {
        int n;

        cin >> n;

        int root = sqrt(n), res, mn, a, b, b1;

        a = 1;
        mn = b = n - 1;

        for(int i = 2; i <= root; ++i) // i = quo
        {
            if(n % i == 0)
            {
                res = n / i;
                b1 = (i - 1) * res;

                if(b1 < mn)
                {
                    mn = b = b1;
                    a = res;
                }

                b1 = (res - 1) * i;

                if(b1 < mn)
                {
                    mn = b = b1;
                    a = i;
                }
            }
        }

        cout << a << ' ' << b << '\n';        

        return;
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
        sol.solve();
    
    return 0;
}