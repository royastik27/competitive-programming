/**
 * UVA 10684 - The jackpot
 * RANK: 1481 out of 16443
 * TIME: 0.030 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum, max, el, i;

    while(cin >> n && n)
    {
        sum = max = 0;

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            sum += el;

            if(sum < 0) sum = 0;

            if(sum > max) max = sum;
        }

        if(max) cout << "The maximum winning streak is " << max << ".\n";
        else cout << "Losing streak.\n";
    }

    return 0;
}