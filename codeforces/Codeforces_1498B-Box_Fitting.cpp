/**
* CodeCraft-21 and Codeforces Round #711 (Div. 2)
* Problem B - Box Fitting
* Time: 249 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int TC, nWidths, boxWidth, left, pows[20], i, width, toFilled, height, Count;

    cin >> TC;

    while(TC--)
    {
        for(i = 0; i < 20; ++i)
            pows[i] = 0;

        cin >> nWidths >> boxWidth;

        left = height = 0;
        while(nWidths--)
        {
            cin >> width;
            ++left;

            // mapping powers of 2 in an array
            ++pows[(int)log2(width)];
        }

        // filling up the box
        while(left)
        {
            toFilled = boxWidth;

            // greedy fill up
            for(i = 19; i >= 0; --i)
            {
                // considering current power of 2
                width = pow(2, i);

                if(toFilled < width || !pows[i])
                    continue;

                Count = toFilled / width;

                if(Count > pows[i])
                    Count = pows[i];

                // filling up
                toFilled -= Count * width;
                pows[i] -= Count;
                left -= Count;
            }

            ++height;
        }

        cout << height << '\n';
    }

    return 0;
}
