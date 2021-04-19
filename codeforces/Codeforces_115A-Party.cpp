/**
* Codeforces Beta Round #87 (Div. 1 Only)
* Problem A - Party
* Time: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 2001

int superior[LIMIT];

int find_level(int i)
{
    if(superior[i] == -1)
        return 1;

    return 1 + find_level(superior[i]);
}

int main()
{
    int nEmployees, max_level, i;

    cin >> nEmployees;

    for(i = 1; i <= nEmployees; ++i)
        cin >> superior[i];

    max_level = 0;
    for(i = 1; i <= nEmployees; ++i)
        max_level = max(max_level, find_level(i));

    cout << max_level << '\n';

    return 0;
}
