/**
* Codeforces Round #634 (Div. 3)
* Problem B - Construct the String
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char str[2001], segment[2001], ch;
    int TC, len, seg_size, distinct, i, j;

    cin >> TC;

    while(TC--)
    {
        cin >> len >> seg_size >> distinct;

        j = seg_size - distinct + 1;

        for(i = 0; i < j; ++i)
            segment[i] = 'a';

        ch = 'a';
        for(; i < seg_size; ++i)
            segment[i] = ++ch;

        j = 0;
        for(i = 0; i < len; ++i)
        {
            str[i] =  segment[j];

            if(++j >= seg_size) j = 0;
        }

        str[i] = '\0';
        cout << str << '\n';
    }

    return 0;
}
