/**
* VK Cup 2012 Qualification Round 1
* Problem B - Taxi
* Time: 248 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int nGroups, ara[5], nChildren, nTaxi;

    memset(ara, 0, sizeof(ara));

    cin >> nGroups;

    while(nGroups--)
    {
        cin >> nChildren;

        ++ara[nChildren];
    }

    nTaxi = ara[4];

    nTaxi += ara[3];
    if(ara[3] > ara[1])
        ara[1] = 0;
    else
        ara[1] -= ara[3];

    if(!ara[2])
        goto calc1;

    nTaxi += ara[2] / 2;
    if(ara[2] % 2 == 1)
    {
        ++nTaxi;
        if(ara[1] >= 2)
            ara[1] -= 2;
        else if(ara[1] == 1)
            --ara[1];
    }

    calc1:
    if(ara[1])
        nTaxi += ceil(ara[1]/4.0);

    cout << nTaxi << '\n';

    return 0;
}
