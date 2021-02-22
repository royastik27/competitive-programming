/**
* Codeforces Contest 977
* Codeforces Round #479 (Div. 3)
* Problem B - Two-gram
* Time: 15 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 101
#define MAP_SIZE 676 // 26 x 26

int Map[MAP_SIZE], highest, highestIndex;

void addToMap(char a, char b)
{
    int index = (a - 'A')*26 + (b - 'A');

    if(++Map[index] > highest)
    {
        highestIndex = index;
        highest = Map[index];
    }
}

int main()
{
    int length, secondLast, div, i;
    char str[LIMIT];

    cin >> length >> str;

    secondLast = length - 1;

    for(i = 0; i < secondLast; ++i)
        addToMap(str[i], str[i + 1]);

    div = highestIndex / 26;

    cout << (char)(div + 'A') << (char)(highestIndex % 26 + 'A') << '\n';

    return 0;
}
