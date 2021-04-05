/**
* UVa 299 - Train Swapping
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int TC, len, Swap, carriage[50], temp;
    register int i, j;

    cin >> TC;

    while(TC--)
    {
        cin >> len;

        for(i = 0; i < len; ++i)
            cin >> carriage[i];

        Swap = 0;

        // bubble sorting
        for(i = 0; i < len - 1; ++i)
        {
            for(j = 0; j + 1 < len - i; ++j)
            {
                if(carriage[j] > carriage[j + 1])
                {
                    temp = carriage[j];
                    carriage[j] = carriage[j+1];
                    carriage[j+1] = temp;
                    ++Swap;
                }
            }
        }

        cout << "Optimal train swapping takes " << Swap << " swaps.\n";
    }

    return 0;
}
