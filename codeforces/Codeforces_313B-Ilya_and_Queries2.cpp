/**
* Codeforces Round #186 (Div. 2)
* Porblem B - Ilya and Queries
* Dynamic Programming Solution
* Time: 622 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 100001

int main()
{
    ios_base::sync_with_stdio(false);

    int len, nQueries, dp[LIMIT], left, right;
    char str[LIMIT];
    register int i;

    cin >> str;
    len = strlen(str);

    dp[1] = 0;
    for(i = 2; i <= len; ++i)
    {
        if(str[i-1] == str[i-2])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = dp[i-1];
    }

    cin >> nQueries;
    while(nQueries--)
    {
        cin >> left >> right;

        cout << dp[right] - dp[left] << '\n';
    }

    return 0;
}
