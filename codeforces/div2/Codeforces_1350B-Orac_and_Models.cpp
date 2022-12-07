/**
 * Codeforces Round #641 (Div. 2)
 * Problem B - Orac and Models
 * TIME: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define LIM 100001

class Solution
{
    int arr[LIM], mem[LIM];

    int check(int divIdx, int parIdx)
    {
        if(arr[divIdx] < arr[parIdx])
            return mem[divIdx];
        
        return 0;
    }
public:
    int solve()
    {
        int n, i, j, root, ans = 1, mx;

        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            mem[i] = 0;
        }

        for(i = 1; i <= n; ++i)
        {
            root = sqrt(i);
            mx = 0;

            for(j = 1; j <= root; ++j)
            {
                if(i % j == 0)
                    mx = max(mx, max(check(j, i), check(i/j, i)));
            }

            mem[i] = mx+1;
            ans = max(ans, mem[i]);
        }

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