/**
* Codeforces Contest 978
* Codeforces Round #481 (Div. 3)
* Problem B - File Name
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int length, no_x, Count;
    char str[101];

    cin >> length >> str;

    Count = no_x = 0;
    for(int i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == 'x')
            ++no_x;
        else
            no_x = 0;

        if(no_x > 2)
            ++Count;
    }

    cout << Count << '\n';

    return 0;
}
