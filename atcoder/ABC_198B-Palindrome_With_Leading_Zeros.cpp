/**
* AtCoder Beginner Contest 198
* Problem B - Palindrome with leading zeros
* Time: 8 ms
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char n[11], zeroStr[30];
    int i, len, zero = 0, j;

    cin >> n;

    len = strlen(n);

    for(i = len-1; i >= 0; --i)
    {
        if(n[i] == '0')
            ++zero;
        else break;
    }

    for(i = 0; i < zero; ++i)
        zeroStr[i] = '0';

    zeroStr[zero] = '\0';

    strcat(zeroStr, n);

    len = strlen(zeroStr);

    for(i = 0, j = len-1; i < j; ++i, --j)
    {
        if(zeroStr[i] != zeroStr[j])
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
