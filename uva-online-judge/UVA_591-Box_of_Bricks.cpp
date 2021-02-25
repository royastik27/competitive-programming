/**
* UVA 591 - Box of Bricks
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int nBricks, height[50], avg, res, i, set = 0;

    while(1)
    {
        cin >> nBricks;
        if(!nBricks) break;

        avg = 0;
        for(i = 0; i<nBricks; ++i)
        {
            cin >> height[i];
            avg += height[i];
        }
        avg /= nBricks;

        res = 0;
        for(i = 0; i<nBricks; ++i)
        {
            if(height[i] > avg)
                res += height[i] - avg;
        }

        cout << "Set #" << ++set << '\n';
        cout << "The minimum number of moves is " << res << ".\n\n";
    }

    return 0;
}
