/**
* Codeforces Problem 6
* Codeforces Beta Round #6 (Div. 2 Only)
* Problem C - Alice, Bob and Chocolate
* Time: 278 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 100000

int main()
{
    int nChocolates, time[LIMIT], left[LIMIT], right[LIMIT], i, j, alice, bob;

    cin >> nChocolates;

    for(i = 0; i < nChocolates; ++i)
        cin >> time[i];

    // prefix sum
    left[0] = time[0];
    right[0] = time[nChocolates-1];

    for(i = 1, j = nChocolates-2; i < nChocolates; ++i, --j)
    {
        left[i] = left[i-1] + time[i];
        right[i] = right[i-1] + time[j];
    }

    // two pointer method
    alice = bob = 0;
    while(alice + bob < nChocolates)
    {
        if(left[alice] > right[bob])
            ++bob;
        else
            ++alice;
    }

    cout << alice << ' ' << bob << '\n';

    return 0;
}
