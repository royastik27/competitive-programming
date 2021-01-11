/**
* UVA 11661 - Burger Time?
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 2000001

int getMinDist(char str[])
{
    int distRestourant, distDrugStore, dist, res, i;

    distRestourant = distDrugStore = res = MAX;

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == '.')
            continue;
        else if(str[i] == 'Z'){
            res = 0;
            break;
        }
        else if(str[i] == 'R')
            distRestourant = i;
        else
            distDrugStore = i;

        dist = abs(distRestourant-distDrugStore);

        if(dist < res)  res = dist;
    }

    return res;
}

int main()
{
    int length;
    char highwayStr[MAX];

    while(1)
    {
        cin >> length;
        if(!length) break;

        getchar();
        cin.getline(highwayStr, MAX);

        cout << getMinDist(highwayStr) << '\n';
    }

    return 0;
}
