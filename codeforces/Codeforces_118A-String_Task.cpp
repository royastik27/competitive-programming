/**
* Codeforces Beta Round #89 (Div. 2)
* Problem A - String Task
* Time: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char str[101];
    int i;

    cin >> str;

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] < 'a') str[i] += 32;

        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            continue;
        else
            cout << '.' << str[i];
    }

    cout << '\n';

    return 0;
}
