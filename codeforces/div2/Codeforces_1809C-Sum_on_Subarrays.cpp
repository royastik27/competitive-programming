/**
* Educational Codeforces Round 145 (Rated for Div. 2)
* Problem C - Sum on Subarrays
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 31

class Solution
{
    int a[LIM];
    bool pos[LIM];
public:
    void solve()
    {
        int n, k, copyK, i, negSum;

        cin >> n >> k;

        // assigning positive positions
        memset(pos, 0, n+1);

        copyK = k;
        i = n;

        while(k)
        {
            if(k > i)
            {
                pos[i] = true;
                k -= i;
                --i;
            }
            else
            {
                pos[k] = true;
                k = 0;
            }
        }

        k = copyK;

        // entering values
        negSum = 0;
        for(i = 1; i <= n; ++i)
        {
            if(pos[i])
            {
                a[i] = negSum + 1;
                negSum = 0;
            }
            else
            {
                if(pos[i-1])
                {
                    negSum = a[i-1] + 1;
                    a[i] = 0 - negSum;
                }
                else
                {
                    a[i] = -1;
                    ++negSum;
                }
            }
        }

        // printing result
        for(i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << '\n';

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