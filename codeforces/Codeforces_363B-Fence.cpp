/**
* Codeforces Round #211 (Div. 2)
* Problem B - Fence
* Time: 108 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 150001

int main()
{
    ios_base::sync_with_stdio(false);

    int nPlanks, width, Min, sum, height[LIMIT], position;
    register int i;

    cin >> nPlanks >> width;

    Min = 0;
    for(i = 1; i <= width; ++i)
    {
        cin >> height[i];
        Min += height[i];
    }

    sum = Min;
    position = 1;

    for(i = width+1; i <= nPlanks; ++i)
    {
        cin >> height[i];
        sum = sum - height[i-width] + height[i];

        if(sum < Min)
        {
            Min = sum;
            position = i-width+1;
        }
    }

    cout << position << '\n';

    return 0;
}
