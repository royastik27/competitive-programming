/**
 * UVA 574 - Sum It Up
 * RANK: 2674 out of 9371
 * TIME: 0.000 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define SUMLIM 10001 // or, INF
#define COINLIM 101

class Solution {
    int coinDP[SUMLIM][COINLIM], cntDP[SUMLIM][COINLIM], coin[COINLIM];
public:
    Solution()
    {
        coin[0] = 0;
    }
    void solve()
    {
        int total, n, i, j, takenCoin, prevCoin;
        cin >> total >> n;

        for(i = 1; i <= n; ++i) cin >> coin[i];
        sort(coin, coin+n+1);

        coinDP[0][0] = 0;
        for(i = 1; i <= total; ++i) coinDP[0][i] = SUMLIM;

        cntDP[0][0] = 0;
        for(i = 1; i <= total; ++i) cntDP[0][i] = SUMLIM;

        for(i = 1; i <= n; ++i)
        {
            coinDP[i][0] = cntDP[i][0] = 0;

            for(j = 1; j <= total; ++j)
            {
                if(j < coin[i])
                {
                    if(coin[i] <= coinDP[i-1][j])
                    {
                        coinDP[i][j] = coin[i];
                        cntDP[i][j] = 1;
                    }
                    else { coinDP[i][j] = coinDP[i-1][j]; cntDP[i][j] = cntDP[i-1][j]; }
                }
                else
                {
                    takenCoin = coin[i] + coinDP[i-1][j - coin[i]];
                    prevCoin = coinDP[i-1][j];

                    if(takenCoin < prevCoin)
                    {
                        coinDP[i][j] = takenCoin;
                        cntDP[i][j] = 1 + cntDP[i-1][j - coin[i]];
                    }
                    else if(prevCoin == takenCoin)
                    {
                        coinDP[i][j] = takenCoin;

                        if(1 + cntDP[i-1][j - coin[i]] < cntDP[i-1][j])
                            cntDP[i][j] = 1 + cntDP[i-1][j - coin[i]];
                        else cntDP[i][j] = cntDP[i-1][j];
                    }
                    else { coinDP[i][j] = prevCoin; cntDP[i][j] = cntDP[i-1][j]; }
                }
            }
        }

        cout << coinDP[n][total] << ' ' << cntDP[n][total] << '\n';     

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