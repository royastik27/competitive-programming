/**
* UVA 11389 - The Bus Driver Problem
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <algorithm>

#define LIMIT 100

using namespace std;

int main()
{
    int n_drivers, limit, rate, i, sum, res;
    int morning[LIMIT], evening[LIMIT];

    while(1)
    {
        cin >> n_drivers;

        if(!n_drivers) break;

        cin >> limit >> rate;

        for(i = 0; i<n_drivers; i++)
        {
            cin >> morning[i];
        }
        for(i = 0; i<n_drivers; i++)
        {
            cin >> evening[i];
        }

        res = 0;

        sort(morning, morning+n_drivers);
        sort(evening, evening+n_drivers, greater<int>());

        for(i = 0; i<n_drivers; i++)
        {
            sum = morning[i]+evening[i];

            if(sum > limit)
                res+=(sum-limit);
        }

        cout << res*rate << '\n';
    }

    return 0;
}
