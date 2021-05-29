/**
* Codeforces Round #130 (Div. 2)
* Problem A - Dubstep
* Time: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

char str[201];

inline bool isWUB(int i, int len)
{
    return (len - i > 2 && str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B');
}

int main()
{
    char res[201];
    int i, j, len;

    cin >> str;

    len = strlen(str);

    i = 0;
    j = -1;

    // determining the first character
    if(isWUB(i, len)) {
        while(isWUB(i, len))
            i += 3;

        res[++j] = str[i++];
    }

    while(i < len)
    {
        if(isWUB(i, len)) {
            if(res[j] != ' ') // for avoiding extra space
                res[++j] = ' ';
            i += 3;
        }
        else {
            res[++j] = str[i++];
        }
    }

    // terminating string
    if(res[j] == ' ')
        res[j] = '\0';
    else res[++j] = '\0';

    cout << res << '\n';

    return 0;
}
