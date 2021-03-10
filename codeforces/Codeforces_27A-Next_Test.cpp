/**
* Codeforces Beta Round #27 (Codeforces format, Div. 2)
* Problem A - Next Test
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

bool istaken[3001];

int main()
{
    int indices, index, i, max, res;

    cin >> indices;

    max = 0;

    for(i = 0; i < indices; ++i)
    {
        cin >> index;

        istaken[index] = true;

        if(index > max)
            max = index;
    }

    res = max + 1;
    for(i = 1; i <= max; ++i)
    {
        if(!istaken[i])
        {
            res = i;
            break;
        }
    }

    cout << res << '\n';

    return 0;
}
