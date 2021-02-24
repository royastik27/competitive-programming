/**
* Codeforces Problem 12
* Codeforces Beta Round #12 (Div 2 Only)
* Problem B - Correct Solution?
* Time: 60 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define LIMIT 11

int main()
{
    char num[LIMIT], input[LIMIT];

    cin >> num >> input;

    int len = strlen(num), i;

    sort(num, num + len);

    // swapping first zero with first non-zero digit
    if(num[0] == '0' && strcmp(num, "0") != 0)
    {
        for(i = 1; num[i] == '0'; ++i);

        num[0] = num[i];
        num[i] = '0';
    }

    if(strcmp(input, num) == 0)
        cout << "OK\n";
    else
        cout << "WRONG_ANSWER\n";

    return 0;
}
