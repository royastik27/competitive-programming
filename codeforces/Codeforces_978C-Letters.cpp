/**
* Codeforces Contest 978
* Codeforces Round #481 (Div. 3)
* Problem C - Letters
* Time: 1466 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 200000

long long int prefixSum[LIMIT], room_no;

int upperBound(int low, int high)
{
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(prefixSum[mid] >= room_no)
            high = mid-1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int nDormitories, nLetters, position, i;
    long long int nRooms;

    cin >> nDormitories >> nLetters;

    cin >> prefixSum[0];
    for(i = 1; i < nDormitories; ++i)
    {
        cin >> nRooms;
        prefixSum[i] = prefixSum[i-1] + nRooms;
    }

    while(nLetters--)
    {
        cin >> room_no;

        position = upperBound(0, nDormitories-1);

        cout << position + 1 << ' ' <<  (room_no - prefixSum[position-1]) << '\n';
    }

    return 0;
}
