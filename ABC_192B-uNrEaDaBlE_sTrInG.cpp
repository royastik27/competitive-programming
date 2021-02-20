/**
* Atcoder Beginner Contest 192
* Problem B - uNrEaDaBlE sTrInG
* Time: 5 ms
* Author: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

bool isHardToRead(char str[])
{
    int i, len;

    len = strlen(str);

    for(i = 0; i < len; i+=2)
    {
        if(str[i] <= 'Z')
            return false;
    }

    for(i = 1; i < len; i+=2)
    {
        if(str[i] >= 'a')
            return false;
    }

    return true;
}

int main()
{
    char str[1001];

    cin >> str;

    if(isHardToRead(str))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
