/**
* Codeforces Round #529 (Div. 3)
* Problem B - Array Stabilization
* Second smallest and second largest in linear scan
* Time: 156 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define INF 100001

int main()
{
    int nElements, num, largest, secondLargest, smallest, secondSmallest;

    cin >> nElements;

    smallest = secondSmallest = INF;
    largest = secondLargest = 0;

    for(int i = 0; i < nElements; ++i)
    {
        cin >> num;

        if(num < smallest)
        {
            secondSmallest = smallest;
            smallest = num;
        }
        else if(num < secondSmallest)
            secondSmallest = num;

        if(num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if(num > secondLargest)
            secondLargest = num;
    }

    cout << min(secondLargest - smallest, largest - secondSmallest) << '\n';

    return 0;
}
