/**
 * UVA 574 - Sum It Up
 * RANK: 2674 out of 9371
 * TIME: 0.000 sec
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