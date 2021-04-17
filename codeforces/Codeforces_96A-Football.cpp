/**
* Codeforces Beta Round #77 (Div. 2 Only)
* Problem A - Football
* Time: 60 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 100

int main()
{
    char position[LIMIT];
    int first = 0, second = 0;

    cin >> position;

    for(int i = 0; position[i] != '\0'; ++i)
    {
        if(position[i] == '0')
        {
            ++first;
            second = 0;
        }
        else
        {
            ++second;
            first = 0;
        }

        if(first >= 7 || second >= 7)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
