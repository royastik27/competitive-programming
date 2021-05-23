/**
* Codeforces Round #697 (Div. 3)
* Problem C - Ball in Berland
* Time: 607 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 200001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, nBoys, nGirls, nPairs, boy[LIMIT], girl[LIMIT], bquery[LIMIT], gquery;
    long long int res;
    register int i;

    cin >> TC;

    while(TC--)
    {
        memset(boy, 0, sizeof(boy));
        memset(girl, 0, sizeof(girl));

        cin >> nBoys >> nGirls >> nPairs;

        for(i = 0; i < nPairs; ++i)
            cin >> bquery[i];

        cin >> gquery;

        // initializing first pair
        boy[bquery[0]] = 1;
        girl[gquery] = 1;

        // main operation
        res = 0;
        for(i = 1; i < nPairs; ++i)
        {
            cin >> gquery;
            // now we have: bquery[i] and gquery

            res += i - boy[bquery[i]] - girl[gquery];

            // updating the map
            ++boy[bquery[i]];
            ++girl[gquery];
        }

        cout << res << '\n';
    }

    return 0;
}
