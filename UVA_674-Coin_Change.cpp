/**
* UVA 674 - Coin Change
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

#define COINS 5

using namespace std;

int no_ways(int coins[], int value)
{
    int dp[value+1], i, j;

    dp[0] = 1;
    for(i = 1; i<=value; i++)
        dp[i] = 0;

    for(i = 1; i<=COINS; i++)
    {
        for(j = coins[i-1]; j<=value; j++)
        {
            dp[j]+=(dp[j-coins[i-1]]);
        }
    }

    return dp[value];
}

int main()
{
    int coins[] = {1, 5, 10, 25, 50}, amount;

    while(cin >> amount)
    {
        cout << no_ways(coins, amount) << '\n';
    }

    return 0;
}
