/**
* Codeforces Round #677 (Div. 3)
* Problem C - Dominant Piranha
* Time: 717 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define SIZE 300002

int main()
{
    int TC, nPiranhas, p_size[SIZE], max_size, max_position, count_max, prev;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> nPiranhas;

        max_size = count_max = 0;

        for(i = 1; i <= nPiranhas; ++i)
        {
            cin >> p_size[i];
            if(p_size[i] > max_size)
                max_size = p_size[i];
        }

        p_size[0] = p_size[nPiranhas+1] = max_size;

        max_size = 0;

        // getting the position
        for(i = 1; i <= nPiranhas; ++i)
        {
            if(p_size[i] > max_size)
            {
                max_size = p_size[i];
                max_position = i;
                count_max = 1;
            }
            else if(p_size[i] == max_size)
            {
                ++count_max;

                if(p_size[i-1] != max_size || p_size[i+1] != max_size)
                    max_position = i;
            }
        }

        if(count_max == nPiranhas)
            max_position = -1;

        cout << max_position << '\n';
    }

    return 0;
}
