/**
* CodeTON Round 5 (Div. 1 + Div. 2, Rated, Prizes!)
* Problem C - Tenzing and Balls
* TIME: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200001

class Solution
{
    int a[LIM], dp[LIM], last[LIM];

public:
    Solution() { dp[0] = dp[1] = 0; }

    void solve()
    {
        int n, i, curr, taken_res;

        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            last[i] = 0;
        }

        last[a[1]] = 1;

        for(i = 2; i <= n; ++i)
        {
            curr = a[i];

            taken_res = dp[last[curr]];

            if(last[curr])
                if(dp[last[curr]] > dp[last[curr]-1]) // merge
                    taken_res += i - last[curr];
                else
                    taken_res += i - last[curr] + 1;

            dp[i] = max(dp[i-1], taken_res);
            last[curr] = i;
        }

        cout << dp[n] << '\n';

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