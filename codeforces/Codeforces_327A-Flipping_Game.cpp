/**
* Codeforces Round #191 (Div. 2)
* Problem A - Flipping Game
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, ara[101], pre[101], next[101];
    register int i, j;

    cin >> n;

    // input and prefix sum from left
    pre[0] = 0;
    for(i = 1; i <= n; ++i)
    {
        cin >> ara[i];
        pre[i] = ara[i] + pre[i-1];
    }

    // prefix sum from right
    next[n+1] = 0;
    for(i = n; i >= 1; --i)
        next[i] = ara[i] + next[i+1];

    // main operation
    int sum, total_sum, Max = -1;
    for(i = 1; i <= n; ++i)
    {
        sum = 0;
        for(j = i; j <= n; ++j)
        {
            if(ara[j] == 0)
                ++sum;

            total_sum = sum + pre[i-1] + next[j+1];

            if(total_sum > Max)
                Max = total_sum;
        }
    }

    cout << Max << '\n';

    return 0;
}
