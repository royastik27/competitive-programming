/**
* Codeforces Round #163 (Div. 2)
* Problem B - Queue at the School
* Time: 60 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char position[51];
    int length, time, i, j;

    cin >> length >> time >> position;

    for(i = 0; i < time; ++i)
    {
        for(j = 1; j < length; ++j)
        {
            if(position[j] == 'G' && position[j-1] == 'B')
            {
                position[j-1] = 'G';
                position[j] = 'B';
                ++j;
            }
        }
    }

    cout << position << '\n';

    return 0;
}
