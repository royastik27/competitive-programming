/**
* UVA 562 - Dividing Coins
* AUTHOR: Eng. Astik Roy
* UVa Submission Rank: 479
**/

#include <iostream>

#define COIN_LIMIT 100
#define SUM_LIMIT 25000

using namespace std;

bool dp[COIN_LIMIT+1][SUM_LIMIT+1];

int knapSack(int ara[], int n, int sum)
{
    int i, j;

    for(i = 0; i<=n; i++)
        dp[i][0] = true;

    for(i = 1; i<=sum; i++)
        dp[0][i] = false;

    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<ara[i-1]; j++)
            dp[i][j] = dp[i-1][j];

        for(j = ara[i-1]; j<=sum; j++)
            dp[i][j] = dp[i-1][j] | dp[i-1][j-ara[i-1]];
    }

    for(i = sum; i>=0; i--)
    {
        if(dp[n][i])
        {
            return i;
        }
    }
}

int main()
{
    int test, number, sum, i;
    int coins[COIN_LIMIT];

    cin >> test;

    while(test--)
    {
        cin >> number;

        sum = 0;
        for(i = 0; i<number; i++)
        {
            cin >> coins[i];
            sum+=coins[i];
        }

        cout << sum - 2*knapSack(coins, number, sum/2) << endl;
    }

    return 0;
}
