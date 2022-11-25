/**
 * Codeforces Round #595 (Div. 3)
 * Problem B2 - Books Exchange (hard version)
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200001

class Solution
{
    int next[LIM], days[LIM];
public:
    void solve()
    {
        int n, i, j, day;

        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> next[i];
            days[i] = 0;
        }

        for(i = 1; i <= n; ++i)
        {
            if(days[i]) continue;

            // count days
            day = 1;
            j = i;

            while(next[j] != i)
            {
                ++day;
                j = next[j];
            }

            // update days
            j = i;

            while(next[j] != i)
            {
                days[j] = day;
                j = next[j];
            }

            days[j] = day;
        }

        for(i = 1; i <= n; ++i) cout << days[i] << ' ';
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