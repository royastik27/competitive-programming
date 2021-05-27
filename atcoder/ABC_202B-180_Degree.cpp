/**
* AtCoder Beginner Contest 202
* Problem B - 180 Degree
* Time: 11 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char str[100001];
    int i;

    cin >> str;

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == '6') str[i] = '9';
        else if(str[i] == '9') str[i] = '6';
    }

    reverse(str, str+i);

    cout << str << '\n';

    return 0;
}
