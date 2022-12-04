/**
 * Codeforces Round #604 (Div. 2)
 * Problem B - Beautiful Numbers
 * TIME: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200000

class Solution
{
    int arr[LIM];
    char ans[LIM];
public:
    void solve()
    {
        int n, i, j, one, taken, mx;

        cin >> n;
        for(i = 0; i < n; ++i) ans[i] = '0';

        for(i = 0; i < n; ++i)
        {
            cin >> arr[i];

            if(arr[i] == 1) one = i;
        }

        i = one-1;
        j = one + 1;

        ans[0] = '1';
        taken = mx = 1;

        while(i >= 0 && j < n)
        {
            if(arr[i] < arr[j])
            {
                one = arr[i];
                --i;
            }
            else
            {
                one = arr[j];
                ++j;
            }

            ++taken;
            if(one > mx)
                mx = one;

            if(mx == taken)
                ans[mx-1] = '1';
        }

        while(i >= 0)
        {
            ++taken;

            if(arr[i] > mx)
                mx = arr[i];

            if(mx == taken)
                ans[mx-1] = '1';

            --i;
        }

        while(j < n)
        {
            ++taken;

            if(arr[j] > mx)
                mx = arr[j];

            if(mx == taken)
                ans[mx-1] = '1';

            ++j;
        }

        ans[n] = '\0';

        cout << ans << '\n';
        
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