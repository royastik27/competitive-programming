/**
* HackerRank - Game of Stones
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define SIZE 101

int main()
{
    int TC, nStones, i;
    bool states[SIZE];

    // pre-calculation (true = winning position : false = loosing position)
    states[0] = states[1] = false;
    states[2] = states[3] = states[4] = true;

    for(i = 5; i < SIZE; ++i)
        states[i] = (!states[i - 2]) | (!states[i - 3]) | (!states[i - 5]);

    cin >> TC;

    while(TC--)
    {
        cin >> nStones;

        if(states[nStones])
            cout << "First\n";
        else    cout << "Second\n";
    }

    return 0;
}
