/**
* Codeforces Round #367 (Div. 2)
* Problem B - Interesting Drink
* Dynamic Programming Solution
* Time: 311 ms
* AUTHOR: Astik Roy
**/
 
#include <iostream>
#include <cstring>
 
using namespace std;
 
#define LIMIT 100001
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int nShops, nDays, amount, dp[LIMIT], Max;
    register int i;
 
    memset(dp, 0, sizeof(dp));
 
    cin >> nShops;
 
    Max = 0;
    for(i = 0; i < nShops; ++i)
    {
        cin >> amount;
 
        ++dp[amount];
 
        if(amount > Max) Max = amount;
    }
 
    for(i = 2; i <= Max; ++i)
        dp[i] += dp[i-1];
 
    cin >> nDays;
 
    while(nDays--)
    {
        cin >> amount;
 
        if(amount > Max) cout << nShops << '\n';
        else cout << dp[amount] << '\n';
    }
 
    return 0;
}
