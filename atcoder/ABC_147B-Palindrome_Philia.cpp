/**
* AtCoder Beginner Contest 147
* Problem B - Palindrome Philia
* Time: 9 ms
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int Count = 0, len, i, j;
    char str[101];

    cin >> str;

    len = strlen(str);
    j = len - 1;
    len /= 2;

    for(i = 0; i < len; ++i, --j)
    {
        if(str[i] != str[j])
            ++Count;
    }

    cout << Count << '\n';


    return 0;
}
