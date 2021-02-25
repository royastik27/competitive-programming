/**
* Codeforces Problem 750
* Good Bye 2016
* Problem A - New Year and Hurry
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 11

int times[LIMIT];

int upperBound(int low, int high, int timeToParticipate)
{
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(timeToParticipate < times[mid])
            high = mid -1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int nProblems, timeToGo;

    cin >> nProblems >> timeToGo;

    // prefix sum of times
    for(int i = 1; i <= nProblems; ++i)
        times[i] = times[i - 1] + (i * 5);

    cout << upperBound(1, nProblems, 240 - timeToGo) - 1 << '\n';

    return 0;
}
