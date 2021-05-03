/**
* Codeforces Round 1335
* Problem C - Two Teams Composing
* Time: 327 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define MAX 200001

int main()
{
    int TC, nStudents, skill[MAX], i, j, res, unique, maxSame, data;

    cin >> TC;

    while(TC--)
    {
        cin >> nStudents;

        // initializing
        for(i = 1; i<=nStudents; ++i)   skill[i] = 0;
        unique = 0;
        maxSame = 1;

        for(i = 0; i<nStudents; ++i)
        {
            cin >> data;

            // getting the unique numbers
            if(!skill[data]) ++unique;
            //else if(skill[data] == 1) --unique;

            ++skill[data];

            // getting the maximum same
            if(skill[data] > maxSame)
                maxSame = skill[data];
        }

        // getting the result
        if(unique < maxSame)
            res = unique;
        else if(unique > maxSame)
            res = maxSame;
        else
            res = unique - 1;

        cout << res << '\n';
    }

    return 0;
}
