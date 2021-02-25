/**
* Codeforces Problem 71A - Way Too Long Words
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

void abbreviate(char str[])
{
    int len, i, j, nLetters;
    char lastword, letters[98];

    len = strlen(str);

    if(len > 10)
    {
        nLetters = len-2;

        j = -1;
        while(nLetters)
        {
            letters[++j] = nLetters%10 + '0';
            nLetters /= 10;
        }

        lastword = str[len-1];

        for(i = 1; j >=0; ++i, --j)
        {
            str[i] = letters[j];
        }
        str[i] = lastword;
        str[++i] = '\0';
    }
}

int main()
{
    int TC;
    char str[101];

    cin >> TC;
    getchar();

    while(TC--)
    {
        cin.getline(str, 101);

        abbreviate(str);

        cout << str << '\n';
    }

    return 0;
}
